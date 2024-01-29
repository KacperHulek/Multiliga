#include "../include/dodajgracza.h"
#include "ui_dodajgracza.h"

DodajGracza::DodajGracza(QWidget *parent, DatabaseManager *dbManager, EdytujLige *el) :
    QDialog(parent),
    ui(new Ui::DodajGracza),
    dbManager(dbManager),
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

void DodajGracza::on_pushButton_2_clicked()
{
    close();
}


void DodajGracza::on_pushButton_clicked()
{
    //zatwierdz
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

