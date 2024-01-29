#include "usunkonto.h"
#include "ui_usunkonto.h"

UsunKonto::UsunKonto(QWidget *parent, DatabaseManager *dbManage) :
    QDialog(parent),
    ui(new Ui::UsunKonto),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

UsunKonto::~UsunKonto()
{
    delete ui;
}
