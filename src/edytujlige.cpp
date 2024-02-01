#include "../include/edytujlige.h"
#include "ui_edytujlige.h"
#include "../include/zmiendatekolejki.h"
#include "../include/edytujgraczawlidze.h"
#include "../include/dodajgracza.h"

EdytujLige::EdytujLige(QWidget *parent, int leagueID) :
    QDialog(parent),
    ui(new Ui::EdytujLige),
    leagueID(leagueID)
{
    ui->setupUi(this);
    this->updateStuff();
}

EdytujLige::~EdytujLige()
{
    delete ui;
}

void EdytujLige::updateStuff(){
    //queueID = 0;
    //playerID = 0;
    QDateTime queueDate;
    QSqlQuery helperQuery;
    helperQuery.prepare("SELECT * FROM [HelperView1] WHERE [LeagueID] = :LeagueID ORDER BY QueueDate DESC");
    helperQuery.bindValue(":LeagueID",leagueID);
    if(helperQuery.exec()&&helperQuery.next()){
        queueID = helperQuery.value("QueueID").toInt();
        queueDate = helperQuery.value("QueueDate").toDateTime();
        ui->dateTimeEdit->setDateTime(queueDate);
    }
    this->model = new QSqlQueryModel();
    qDebug()<<QString::number(queueID);
    model->setQuery("SELECT * FROM [EdycjaLigi] WHERE [QueueID] = " + QString::number(queueID) + " ORDER BY Poziom");
    ui->tableView->setModel(model);
}
int EdytujLige::getQueueID(){
    return queueID;
}
int EdytujLige::getPlayerID(){
    return playerID;
}

void EdytujLige::on_zmienDateKolejkiButton_clicked()
{
    ZmienDateKolejki *okno = new ZmienDateKolejki(nullptr,this);
    okno->show();
}

void EdytujLige::on_edytujGraczaButton_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    playerID = model->record(currentIndex.row()).value("playerID").toInt();
    EdytujGraczaWLidze *okno = new EdytujGraczaWLidze(nullptr,this);
    okno->show();
}

void EdytujLige::on_dodajGraczaButton_clicked()
{
    DodajGracza *okno = new DodajGracza(nullptr,this);
    okno->show();
}

void EdytujLige::on_powrotButton_clicked()
{
    close();
}


void EdytujLige::on_aktualizujPoziomyButton_clicked()
{

    //update QUEUE PAYMENTS!!!
    //automatyczne tworzenie meczy!!!
    //to ponizej musi byc w mainwindow.
    //        QSqlQuery qPayQuery;
    //        qPayQuery.prepare("INSERT INTO QueuePayments (playerID, queueID, paid) VALUES (:playerID, :queueID, 0)");
    //        qPayQuery.bindValue(":queueID",newQueueID);
    //        qPayQuery.bindValue(":playerID",i.key());
    //        if(qPayQuery.exec());
    //        else
    //            qDebug()<<qPayQuery.lastError();

    QVector<int> leagues;
    QSqlQuery query;
    query.prepare("SELECT [ID] FROM [Leagues]");
    if(query.exec()){
        while(query.next()){
            int leagueID = query.value(0).toInt();
            leagues.append(leagueID);
        }
    }else{
        qDebug()<<"Error: "<<query.lastError();
    }

    for(int i : leagues){
        int newQueueID = 0;
        int previousQueueID = 0;
        QSqlQuery queueQuery;
        queueQuery.prepare("SELECT * FROM [Queues] WHERE [leagueID] = :leagueID ORDER BY [date] DESC LIMIT 2");
        queueQuery.bindValue(":leagueID",i);
        if(queueQuery.exec()&&queueQuery.next()){
            newQueueID = queueQuery.value("ID").toInt();
            if(queueQuery.next())
                previousQueueID = queueQuery.value("ID").toInt();
            else{qDebug()<<"Error: "<<queueQuery.lastError();}
            QSqlQuery matchesQuery;
            matchesQuery.prepare("SELECT * FROM [Matches] WHERE [queueID] = :queueID");
            matchesQuery.bindValue(":queueID",previousQueueID);
            QMap<int,int> mapaPunktow;
            //qDebug()<<previousQueueID;
            //qDebug()<<newQueueID;
            if(matchesQuery.exec()&&previousQueueID&&newQueueID){
                while(matchesQuery.next()){
                    int playeraID = matchesQuery.value("playeraID").toInt();
                    int playerbID = matchesQuery.value("playerbID").toInt();
                    int playerAscore = matchesQuery.value("playerAscore").toInt();
                    int playerBscore = matchesQuery.value("playerBscore").toInt();
                    if(!mapaPunktow.contains(playeraID))
                        mapaPunktow.insert(playeraID,0);
                    if(!mapaPunktow.contains(playerbID))
                        mapaPunktow.insert(playerbID,0);
                    if(playerAscore>playerBscore)
                        mapaPunktow.insert(playeraID,mapaPunktow.value(playeraID)+1);
                    else if(playerBscore>playerAscore)
                        mapaPunktow.insert(playerbID,mapaPunktow.value(playerbID)+1);
                }

                for(auto i = mapaPunktow.cbegin(), end = mapaPunktow.cend(); i != end; i++){
                    QSqlQuery upQuery;
                    upQuery.prepare("UPDATE Players SET points = :points, queueID = :queueID  WHERE ID = :playerID");
                    upQuery.bindValue(":playerID",i.key());
                    upQuery.bindValue(":points",i.value());
                    upQuery.bindValue(":queueID",newQueueID);
                    if(upQuery.exec());
                    else
                        qDebug()<<upQuery.lastError();
                }
                qDebug()<<previousQueueID;
                QVector<int> demote;
                QVector<int> promote;
                for(int i = liczbaPoziomow; i>0; i--){
                    QSqlQuery query;
                    query.prepare("SELECT * FROM Players WHERE queueID = :queueID ORDER BY points DESC LIMIT :rows");
                    query.bindValue(":queueID",newQueueID);
                    query.bindValue(":rows",iluAwansuje);
                    if(i<liczbaPoziomow&&query.exec()){
                        while(query.next())
                            promote.append(query.value("ID").toInt());
                    }else if(!query.exec()){qDebug()<<"qError: "<<query.lastError();}

                    query.prepare("SELECT * FROM Players WHERE queueID = :queueID ORDER BY points LIMIT :rows");
                    query.bindValue(":queueID",previousQueueID);
                    query.bindValue(":rows",iluSpada);
                    if(i>1 && query.exec()){
                        while(query.next())
                            demote.append(query.value("ID").toInt());
                    }else if(!query.exec()){qDebug()<<"wError: "<<query.lastError();}
                }
                qDebug()<<newQueueID;
                QSqlQuery helperQuery;
                helperQuery.prepare("SELECT * FROM Players WHERE queueID = :queueID");
                helperQuery.bindValue(":queueID",previousQueueID);
                if(helperQuery.exec()){
                    for(auto i : demote){
                        QSqlQuery demoteQuery;
                        demoteQuery.prepare("UPDATE Players SET level = :level WHERE ID = :playerID");
                        demoteQuery.bindValue(":playerID",i);
                        demoteQuery.bindValue(":level",helperQuery.value("level").toInt()-1);
                        if(demoteQuery.exec());else{qDebug()<<"eError: "<<demoteQuery.lastError();}
                    }
                    for(auto i : promote){
                        QSqlQuery promoteQuery;
                        promoteQuery.prepare("UPDATE Players SET level = :level WHERE ID = :playerID");
                        promoteQuery.bindValue(":playerID",i);
                        promoteQuery.bindValue(":level",helperQuery.value("level").toInt()-1);
                        if(promoteQuery.exec());else{qDebug()<<"rError: "<<promoteQuery.lastError();}
                    }
                }else{qDebug()<<"tError: "<<helperQuery.lastError();}

            }else{
                qDebug()<<"yError: "<<matchesQuery.lastError();
            }
        }else{qDebug()<<"uError: "<<queueQuery.lastError();}
    }


}

void EdytujLige::on_wygenerujMeczeButton_clicked()
{
    //co jest potrzebne:
    //ID najnowszej kolejki w danej lidze,
    //lista graczy przypisanych do tej kolejki,
    //nalezy pamietac o tym by nie duplikowac meczy
    //gdy sie 2 razy kliknie ten przycisk (sprawdzenie czy
    //dani gracze juz grali ze soba w ramach tej kolejki)
    //gracze graja miedzy soba w tym samym poziomie
    //trzeba dodac mozliwosc edycji meczow (w tym i dodawania, a zatem potrzebna kolejna klasa :)))))

    QVector<int> leagues;
    QSqlQuery query;
    int queueID;
    query.prepare("SELECT [ID] FROM [Leagues]");
    if(query.exec()){
        while(query.next()){
            int leagueID = query.value(0).toInt();
            leagues.append(leagueID);
        }
    }else{
        qDebug()<<"Error: "<<query.lastError();
    }

    for(int l : leagues){
        QDate dataKolejki;
        QSqlQuery queueQuery;
        queueQuery.prepare("SELECT [ID], [date] FROM [Queues] WHERE [leagueID] = :leagueID ORDER BY [date] DESC LIMIT 1");
        queueQuery.bindValue(":leagueID",l);
        if(queueQuery.exec()){
            if(queueQuery.next()){
                queueID = queueQuery.value("ID").toInt();
                dataKolejki = queueQuery.value("date").toDate();
            }
        }else{qDebug()<<"Error: "<<queueQuery.lastError();}



        for(int i = liczbaPoziomow;i>0;i--){
            QVector<int> playersID;
            qDebug()<<playersID.size();
            QVector<int> meczeA;
            QVector<int> meczeB;
            QSqlQuery playersQuery;
            playersQuery.prepare("SELECT [ID] FROM [Players] WHERE [queueID] = :queueID AND [level] = :level");
            playersQuery.bindValue(":queueID",queueID);
            playersQuery.bindValue(":level",i);
            if(playersQuery.exec()){
                //tyle ile jest graczy w kolejce, tyle meczy powinno być przypisane do poszczegolnego gracza
                while(playersQuery.next()){
                    playersID.append(playersQuery.value("ID").toInt());
                }

                //mamy liste graczy w danej kolejce na dany poziom. Teraz tworzymy liste meczy
                if(playersID.size()>1){
                    for(int j = 0; j<playersID.size()-1;j++){
                        for(int k = j+1; k<playersID.size();k++){
                            meczeA.append(playersID.value(j));
                            meczeB.append(playersID.value(k));
                        }
                    }
                    for(int j = 0; j<meczeA.size();j++){
                        //to teraz sprawdzamy czy juz nie ma takich meczy miedzy tymi graczami, a nastepnie insertujemy
                        int graczA = meczeA.value(j);
                        int graczB = meczeB.value(j);
                        QSqlQuery matchesQuery;
                        matchesQuery.prepare("SELECT * FROM [Matches] WHERE [queueID] = :queueID "
                                             "AND (([playeraID] = :graczA AND [playerbID] = :graczB) "
                                             "OR ([playeraID] = :graczB AND [playerbID] = :graczA)) ");
                        matchesQuery.bindValue(":queueID",queueID);
                        matchesQuery.bindValue(":graczA",graczA);
                        matchesQuery.bindValue(":graczB",graczB);

                        if(matchesQuery.exec()){
                            if(!matchesQuery.next()){
                                QSqlQuery insertQuery;
                                insertQuery.prepare("INSERT INTO [Matches] (playeraID, playerbID, queueID, courtID, date) "
                                                    "VALUES (:playeraID, :playerbID, :queueID, :courtID, :date)");
                                insertQuery.bindValue(":playeraID",graczA);
                                insertQuery.bindValue(":playerbID",graczB);
                                insertQuery.bindValue(":queueID",queueID);
                                insertQuery.bindValue(":courtID",1); // AKTUALNIE NA JEDNYM BOISKU SIE GRA

                                QDateTime dataMeczu;
                                dataMeczu.setDate(dataKolejki);
                                QTime czas;
                                czas.setHMS(12,0,0,0);
                                dataMeczu.setTime(czas.addSecs(j*1800));
                                insertQuery.bindValue(":date",dataMeczu.toString("yyyy-MM-dd HH:mm:ss"));
                                if(!insertQuery.exec())
                                    qDebug()<<"Error: "<<insertQuery.lastError();
                            }
                        }else{qDebug()<<"Error: "<<matchesQuery.lastError();}
                    }
                }
            }else{qDebug()<<"Error: "<<playersQuery.lastError();}
        }


    }




}

