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
    aktualizujWynikiGraczy();

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

void Ranking::aktualizujWynikiGraczy(){
    QSqlQuery queryPlayers;
    queryPlayers.prepare("SELECT * FROM [Players]");
    if(queryPlayers.exec()){
        while(queryPlayers.next()){
            int playerID = queryPlayers.value("ID").toInt();
            QSqlQuery querySumaWygranychSetow1;
            QSqlQuery querySumaWygranychSetow2;
            int sumaWygranychSetow = 0;
            querySumaWygranychSetow1.prepare("SELECT SUM(playerAscore) FROM [Matches] WHERE playeraID = :playerID");
            querySumaWygranychSetow2.prepare("SELECT SUM(playerBscore) FROM [Matches] WHERE playerbID = :playerID");
            querySumaWygranychSetow1.bindValue(":playerID",playerID);
            querySumaWygranychSetow2.bindValue(":playerID",playerID);
            if(querySumaWygranychSetow1.exec()&&querySumaWygranychSetow1.next()){
                sumaWygranychSetow += querySumaWygranychSetow1.value(0).toInt();
            }else{qDebug()<<querySumaWygranychSetow1.lastError();}

            if(querySumaWygranychSetow2.exec()&&querySumaWygranychSetow2.next()){
                sumaWygranychSetow += querySumaWygranychSetow2.value(0).toInt();
            }else{qDebug()<<querySumaWygranychSetow2.lastError();}

            QSqlQuery queryWygrane;
            int sumaWygranychMeczy = 0;
            queryWygrane.prepare("SELECT COUNT([ID]) FROM [HelperWynikMeczu] WHERE (playeraID = :playerID AND wynikmeczu = 1)"
                                 "OR (playerbID = :playerID AND wynikmeczu = 2)");
            queryWygrane.bindValue(":playerID",playerID);
            if(queryWygrane.exec()&&queryWygrane.next()){
                sumaWygranychMeczy = queryWygrane.value(0).toInt();
            }else{qDebug()<<queryWygrane.lastError();}

            QSqlQuery updatePlayer;
            updatePlayer.prepare("UPDATE [Players] SET [wonSets] = :wygraneSety, [wonMatches] = :wygraneMecze WHERE [ID] = :playerID");
            updatePlayer.bindValue(":playerID",playerID);
            updatePlayer.bindValue(":wygraneMecze",sumaWygranychMeczy);
            updatePlayer.bindValue(":wygraneSety",sumaWygranychSetow);
            if(updatePlayer.exec()){}else{qDebug()<<updatePlayer.lastError();}
        }
    }else{qDebug()<<queryPlayers.lastError();}
}
