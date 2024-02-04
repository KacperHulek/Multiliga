#include "../include/dodajgracza.h"
#include "ui_dodajgracza.h"

DodajGracza::DodajGracza(QWidget *parent, EdytujLige *el) :
    QDialog(parent),
    ui(new Ui::DodajGracza),
    el(el)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM [DodajGracza] WHERE [LeagueID] = " + QString::number(el->getLeagueID()) + " AND ([QueueID] IS NULL OR [QueueID] <> " + QString::number(el->getQueueID()) + ")");
    ui->tableView->setModel(model);
}

DodajGracza::~DodajGracza()
{
    delete ui;
}

void DodajGracza::on_zatwierdzButton_clicked()//wypadałoby zmienic nazwe obiektu tego przycisku na "dodaj"
{
    //tworzyc queuepayments jesli nie istnieje
    QModelIndex currentIndex = ui->tableView->currentIndex();
    int playerID = model->record(currentIndex.row()).value("PlayerID").toInt();
    QSqlQuery query;
    query.prepare("UPDATE [Players] SET [queueID] = :queueID WHERE [ID] = :playerID");
    query.bindValue(":queueID",el->getQueueID());
    query.bindValue(":playerID",playerID);
    if(query.exec()){
        model->setQuery("SELECT * FROM [DodajGracza] WHERE [LeagueID] = " + QString::number(el->getLeagueID()) + " AND ([QueueID] IS NULL OR [QueueID] <> " + QString::number(el->getQueueID()) + ")");
        ui->tableView->setModel(model);
        el->updateStuff();
        aktualizujQueuePayments(playerID,el->getQueueID());
    }
    else
        qDebug()<<query.lastError();
}


void DodajGracza::on_powrotButton_clicked()
{
    close();
}

void DodajGracza::aktualizujQueuePayments(int playerID, int queueID){

    QSqlQuery queryZaplata;
    queryZaplata.prepare("SELECT * FROM [QueuePayments] WHERE [playerID] = :playerID AND [queueID] = :queueID");
    queryZaplata.bindValue(":playerID",playerID);
    queryZaplata.bindValue(":queueID",queueID);
    if(queryZaplata.exec()){
        QSqlQuery queryAktualizuj;
        if(!queryZaplata.next()){
            queryAktualizuj.prepare("INSERT INTO QueuePayments ([playerID], [queueID], [paid]) VALUES (:playerID, :queueID, 0)");
            queryAktualizuj.bindValue(":playerID",playerID);
            queryAktualizuj.bindValue(":queueID",queueID);
            if(queryAktualizuj.exec()){}else{qDebug()<<queryAktualizuj.lastError();}
        }
    }else{qDebug()<<queryZaplata.lastError();}
}

