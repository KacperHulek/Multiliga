#include "../include/aktualizujwyniki.h"
#include "ui_aktualizujwyniki.h"
#include "../include/wpiszwynikmeczu.h"

AktualizujWyniki::AktualizujWyniki(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::AktualizujWyniki),
    dbManager(dbManager)
{
    ui->setupUi(this);
    this->model1 = new QSqlQueryModel();
    this->model2 = new QSqlQueryModel();

    leagueID = 1;



    model1->setQuery("SELECT [name], [ID] FROM [Leagues]");
    ui->listView->setModel(model1);

    model2->setQuery("SELECT [date], [ID], [leagueID] FROM [Queues] WHERE [leagueID] = " + QString::number(leagueID));
    ui->listView_2->setModel(model2);

    queueID = model2->record(0).value("ID").toInt();

}

AktualizujWyniki::~AktualizujWyniki()
{
    delete ui;
}


void AktualizujWyniki::on_listView_indexesMoved(const QModelIndexList &indexes)
{

}


void AktualizujWyniki::on_listView_activated(const QModelIndex &index)
{
//    qDebug()<<leagueID;
//    QModelIndex currentIndex = ui->listView->currentIndex();
//    leagueID = model1->record(currentIndex.row()).value("ID").toInt();
//    model2->setQuery("SELECT [date], [ID], [leagueID] FROM [Queues] WHERE leagueID = "+QString::number(leagueID));
//    ui->listView_2->setModel(model2);
}


void AktualizujWyniki::on_listView_2_clicked(const QModelIndex &index)
{
    QModelIndex currentIndex = index;
    queueID = model2->record(currentIndex.row()).value("ID").toInt();
}


void AktualizujWyniki::on_listView_clicked(const QModelIndex &index)
{
    //qDebug()<<leagueID;
    QModelIndex currentIndex = index;
    leagueID = model1->record(currentIndex.row()).value("ID").toInt();
    model2->setQuery("SELECT [date], [ID], [leagueID] FROM [Queues] WHERE leagueID = "+QString::number(leagueID));
    ui->listView_2->setModel(model2);
}


void AktualizujWyniki::on_pushButton_clicked()
{
    close();
}


void AktualizujWyniki::on_pushButton_2_clicked()
{
    //dalej queueID
    WpiszWynikMeczu *okno = new WpiszWynikMeczu(nullptr,dbManager,queueID);
    okno->show();
}

