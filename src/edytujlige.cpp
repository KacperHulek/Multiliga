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
    int liczbaPoziomow = 3;
    int iluAwansuje = 0;
    int iluSpada = 0;
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

