#include "../include/edytujlige.h"
#include "ui_edytujlige.h"
#include "../include/zmiendatekolejki.h"
#include "../include/edytujgraczawlidze.h"
#include "../include/dodajgracza.h"

EdytujLige::EdytujLige(QWidget *parent, int leagueID) :
    QDialog(parent),
    ui(new Ui::EdytujLige),
    leagueID(leagueID)
{
    ui->setupUi(this);
    this->updateStuff();
}

EdytujLige::~EdytujLige()
{
    delete ui;
}

void EdytujLige::updateStuff(){
    //queueID = 0;
    //playerID = 0;
    QDateTime queueDate;
    QSqlQuery helperQuery;
    helperQuery.prepare("SELECT * FROM [HelperView1] WHERE [LeagueID] = :LeagueID ORDER BY QueueDate");
    helperQuery.bindValue(":LeagueID",leagueID);
    if(helperQuery.exec()&&helperQuery.next()){
        queueID = helperQuery.value("QueueID").toInt();
        queueDate = helperQuery.value("QueueDate").toDateTime();
        ui->dateTimeEdit->setDateTime(queueDate);
    }
    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM [EdycjaLigi] WHERE [QueueID] = " + QString::number(queueID) + " ORDER BY Poziom");
    ui->tableView->setModel(model);
}
int EdytujLige::getQueueID(){
    return queueID;
}
int EdytujLige::getPlayerID(){
    return playerID;
}

void EdytujLige::on_zmienDateKolejkiButton_clicked()
{
    ZmienDateKolejki *okno = new ZmienDateKolejki(nullptr,this);
    okno->show();
}

void EdytujLige::on_edytujGraczaButton_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    playerID = model->record(currentIndex.row()).value("playerID").toInt();
    EdytujGraczaWLidze *okno = new EdytujGraczaWLidze(nullptr,this);
    okno->show();
}

void EdytujLige::on_dodajGraczaButton_clicked()
{
    DodajGracza *okno = new DodajGracza(nullptr,this);
    okno->show();
}

void EdytujLige::on_powrotButton_clicked()
{
    close();
}

