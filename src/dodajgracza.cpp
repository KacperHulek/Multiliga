#include "../include/dodajgracza.h"
#include "ui_dodajgracza.h"

DodajGracza::DodajGracza(QWidget *parent, EdytujLige *el) :
    QDialog(parent),
    ui(new Ui::DodajGracza),
    el(el)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM [DodajGracza] WHERE [QueueID] IS NULL OR [QueueID] <> " + QString::number(el->getQueueID()));
    ui->tableView->setModel(model);
}

DodajGracza::~DodajGracza()
{
    delete ui;
}

void DodajGracza::on_zatwierdzButton_clicked()//wypadałoby zmienic nazwe obiektu tego przycisku na "dodaj"
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    int playerID = model->record(currentIndex.row()).value("PlayerID").toInt();
    QSqlQuery query;
    query.prepare("UPDATE [Players] SET [queueID] = :queueID WHERE [ID] = :playerID");
    query.bindValue(":queueID",el->getQueueID());
    query.bindValue(":playerID",playerID);
    if(query.exec()){
        model->setQuery("SELECT * FROM [DodajGracza] WHERE [QueueID] IS NULL OR [QueueID] <> " + QString::number(el->getQueueID()));
        ui->tableView->setModel(model);
        el->updateStuff();
    }
    else
        qDebug()<<query.lastError();
}


void DodajGracza::on_powrotButton_clicked()
{
    close();
}

