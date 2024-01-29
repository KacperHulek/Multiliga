#include "../include/spotkania.h"
#include "ui_spotkania.h"
Spotkania::Spotkania(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spotkania)
{
    ui->setupUi(this);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM [HarmonogramSpotkan]");
    ui->tableView->setModel(model);
}

Spotkania::~Spotkania()
{
    delete ui;
}
