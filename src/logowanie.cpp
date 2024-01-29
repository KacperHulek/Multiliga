#include "logowanie.h"
#include "ui_ekranlogowania.h"

EkranLogowania::EkranLogowania(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EkranLogowania)
{
    ui->setupUi(this);
}

EkranLogowania::~EkranLogowania()
{
    delete ui;
}
