#include "../include/zarzadzajligami.h"
#include "ui_zarzadzajligami.h"
#include "../include/edytujlige.h"

ZarzadzajLigami::ZarzadzajLigami(QWidget *parent, int currentUserID) :
    QDialog(parent),
    ui(new Ui::ZarzadzajLigami),
    currentUserID(currentUserID)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT [name], [ID] FROM [Leagues] WHERE ownerID = " + QString::number(currentUserID));
    ui->listaLigView->setModel(model);

}

ZarzadzajLigami::~ZarzadzajLigami()
{
    delete ui;
}

void ZarzadzajLigami::on_wybierzButton_clicked()
{
    QModelIndex currentIndex = ui->listaLigView->currentIndex();
    int leagueID = model->record(currentIndex.row()).value("ID").toInt();
    EdytujLige *okno = new EdytujLige(nullptr,leagueID);
    okno->show();
}

void ZarzadzajLigami::on_powrotButton_clicked()
{
    close();
}

