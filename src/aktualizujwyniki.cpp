#include "../include/aktualizujwyniki.h"
#include "ui_aktualizujwyniki.h"
#include "../include/wpiszwynikmeczu.h"

AktualizujWyniki::AktualizujWyniki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AktualizujWyniki)
{
    ui->setupUi(this);
    this->model1 = new QSqlQueryModel();
    this->model2 = new QSqlQueryModel();

    leagueID = 1;

    model1->setQuery("SELECT [name], [ID] FROM [Leagues]");
    ui->listaLigView->setModel(model1);

    model2->setQuery("SELECT [date], [ID], [leagueID] FROM [Queues] WHERE [leagueID] = " + QString::number(leagueID));
    ui->listaKolejekView->setModel(model2);

    queueID = model2->record(0).value("ID").toInt();
}

AktualizujWyniki::~AktualizujWyniki()
{
    delete ui;
}

void AktualizujWyniki::on_dalejButton_clicked()
{
    WpiszWynikMeczu *okno = new WpiszWynikMeczu(nullptr,queueID);
    okno->show();
}

void AktualizujWyniki::on_powrotButton_clicked()
{
    close();
}

void AktualizujWyniki::on_listaLigView_clicked(const QModelIndex &index)
{
    QModelIndex currentIndex = index;
    leagueID = model1->record(currentIndex.row()).value("ID").toInt();
    model2->setQuery("SELECT [date], [ID], [leagueID] FROM [Queues] WHERE leagueID = "+QString::number(leagueID));
    ui->listaKolejekView->setModel(model2);
}

void AktualizujWyniki::on_listaKolejekView_clicked(const QModelIndex &index)
{
    QModelIndex currentIndex = index;
    queueID = model2->record(currentIndex.row()).value("ID").toInt();
}
