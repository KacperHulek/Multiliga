#include "../include/edytujgraczawlidze.h"
#include "ui_edytujgraczawlidze.h"
#include <QMessageBox>

EdytujGraczaWLidze::EdytujGraczaWLidze(QWidget *parent, DatabaseManager *dbManager, EdytujLige *el) :
    QDialog(parent),
    ui(new Ui::EdytujGraczaWLidze),
    dbManager(dbManager),
    el(el)
{
    ui->setupUi(this);




}

EdytujGraczaWLidze::~EdytujGraczaWLidze()
{
    delete ui;
}

void EdytujGraczaWLidze::on_pushButton_2_clicked()
{
    //usun gracza
    int result = QMessageBox::question(nullptr, "Usuwanie gracza", "Czy napewno usunac gracza? Ta akcja jest nieodwracalna",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("UPDATE Players SET [queueID] = :newQueueID WHERE [ID] = :playerID");
        query.bindValue(":newQueueID",QVariant());
        query.bindValue(":playerID",el->getPlayerID());
        if(query.exec()){
            el->updateStuff();
            close();
        }
    }
}


void EdytujGraczaWLidze::on_pushButton_clicked()
{
    //zatwierdz
    QSqlQuery queryPoziom;
    queryPoziom.prepare("UPDATE Players SET [level] = :newLevel WHERE [ID] = :playerID");
    queryPoziom.bindValue(":newLevel",ui->spinBox->value());
    queryPoziom.bindValue(":playerID",el->getPlayerID());
    if(queryPoziom.exec());
    else
        qDebug()<<queryPoziom.lastError();

    QSqlQuery queryZaplata;
    queryZaplata.prepare("SELECT * FROM [QueuePayments] WHERE [playerID] = :playerID AND [queueID] = :queueID");
    queryZaplata.bindValue(":playerID",el->getPlayerID());
    queryZaplata.bindValue(":queueID",el->getQueueID());
    if(queryZaplata.exec()){
        QSqlQuery queryAktualizuj;
        if(queryZaplata.next()){
            //znaczy ze jest juz rekord dot wplaty
            queryAktualizuj.prepare("UPDATE QueuePayments SET [paid] = :isPaid WHERE [playerID] = :playerID AND [queueID] = :queueID");
        }
        else{
            //trzeba dodac taki rekord
            queryAktualizuj.prepare("INSERT INTO QueuePayments ([playerID], [queueID], [paid]) VALUES (:playerID, :queueID, :isPaid)");
        }
        queryAktualizuj.bindValue(":playerID",el->getPlayerID());
        queryAktualizuj.bindValue(":queueID",el->getQueueID());

        bool isPaid = 0;
        if(ui->comboBox_2->currentText()=="Tak")
            isPaid = 1;
        queryAktualizuj.bindValue(":isPaid",isPaid);
        if(queryAktualizuj.exec()){
            el->updateStuff();
            close();
        }else{
            qDebug()<<queryAktualizuj.lastError();
        }


    }else{
        qDebug()<<queryZaplata.lastError();
    }


}


void EdytujGraczaWLidze::on_pushButton_3_clicked()
{
    close();
}

