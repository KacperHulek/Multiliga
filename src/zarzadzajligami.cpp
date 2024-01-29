#include "../include/zarzadzajligami.h"
#include "ui_zarzadzajligami.h"
#include "../include/edytujlige.h"

ZarzadzajLigami::ZarzadzajLigami(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZarzadzajLigami)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT [name], [ID] FROM [Leagues] WHERE ownerID = " + QString::number(1)); //currentUserID
    ui->listView->setModel(model);

}

ZarzadzajLigami::~ZarzadzajLigami()
{
    delete ui;
}

void ZarzadzajLigami::on_pushButton_2_clicked()
{
    close();
}


void ZarzadzajLigami::on_pushButton_clicked()
{
    //wybierz
    QModelIndex currentIndex = ui->listView->currentIndex();
    int leagueID = model->record(currentIndex.row()).value("ID").toInt();
    EdytujLige *okno = new EdytujLige(nullptr,leagueID);
    okno->show();
}

