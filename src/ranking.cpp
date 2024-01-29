#include "../include/ranking.h"
#include "ui_ranking.h"

Ranking::Ranking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
    this->listModel = new QSqlQueryModel();
    listModel->setQuery("SELECT [name],[ID] FROM [Leagues]");
    ui->listaLigView->setModel(listModel);

    this->tableModel = new QSqlQueryModel();
    //listModel->setQuery("SELECT * FROM [Ranking] WHERE leagueID = " + QString::number(leagueID));

}

Ranking::~Ranking()
{
    delete ui;
}

void Ranking::on_listaLigView_clicked(const QModelIndex &index)
{
    QModelIndex currentIndex = index;
    leagueID = listModel->record(currentIndex.row()).value("ID").toInt();
    tableModel->setQuery("SELECT * FROM [Ranking] WHERE leagueID = " + QString::number(leagueID) + " ORDER BY [wygrane mecze] DESC");
    ui->tabelaGraczyView->setModel(tableModel);
}

