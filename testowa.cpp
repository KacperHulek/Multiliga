#include "testowa.h"
#include "ui_testowa.h"

Testowa::Testowa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testowa)
{
    ui->setupUi(this);
}

Testowa::~Testowa()
{
    delete ui;
}
