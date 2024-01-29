#include "../include/zarzadzajligami.h"
#include "ui_zarzadzajligami.h"
#include "../include/edytujlige.h"

ZarzadzajLigami::ZarzadzajLigami(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::ZarzadzajLigami),
    dbManager(dbManager)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT [name], [ID] FROM [Leagues] WHERE ownerID = " + QString::number(dbManager->getCurrentUserID()));
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
    EdytujLige *okno = new EdytujLige(nullptr,dbManager,leagueID);
    okno->show();
}

