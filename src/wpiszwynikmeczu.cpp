#include "../include/wpiszwynikmeczu.h"
#include "ui_wpiszwynikmeczu.h"

WpiszWynikMeczu::WpiszWynikMeczu(QWidget *parent, int queueID) :
    QDialog(parent),
    ui(new Ui::WpiszWynikMeczu),
    queueID(queueID)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM [WpiszWynik] WHERE queueID = " + QString::number(queueID));
    ui->tableView->setModel(model);

}

WpiszWynikMeczu::~WpiszWynikMeczu()
{
    delete ui;
}

void WpiszWynikMeczu::on_wpiszWynikButton_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    int matchID = model->record(currentIndex.row()).value("matchID").toInt();
    QSqlQuery query;
    query.prepare("UPDATE [Matches] SET [playerAscore] = :newPlayerAscore, [playerBscore] = :newPlayerBscore WHERE [ID] = :matchID");
    query.bindValue(":newPlayerAscore",ui->spinBoxA->value());
    query.bindValue(":newPlayerBscore",ui->spinBoxB->value());
    query.bindValue(":matchID",matchID);

    if(query.exec()){
        model->setQuery("SELECT * FROM [WpiszWynik] WHERE queueID = " + QString::number(queueID));
        ui->tableView->setModel(model);
    }
    else{
        qDebug()<<query.lastError();
    }
}


void WpiszWynikMeczu::on_powrotButton_clicked()
{
    close();
}

