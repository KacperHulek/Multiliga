#include "../include/ranking.h"
#include "ui_ranking.h"

Ranking::Ranking(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::Ranking),
    dbManager(dbManager)
{
    ui->setupUi(this);
    this->listModel = new QSqlQueryModel();
    listModel->setQuery("SELECT [name],[ID] FROM [Leagues]");
    ui->listView->setModel(listModel);

    this->tableModel = new QSqlQueryModel();
    //listModel->setQuery("SELECT * FROM [Ranking] WHERE leagueID = " + QString::number(leagueID));

}

Ranking::~Ranking()
{
    delete ui;
}

void Ranking::on_listView_clicked(const QModelIndex &index)
{
    QModelIndex currentIndex = index;
    leagueID = listModel->record(currentIndex.row()).value("ID").toInt();
    tableModel->setQuery("SELECT * FROM [Ranking] WHERE leagueID = " + QString::number(leagueID));
    ui->tableView->setModel(tableModel);
}

