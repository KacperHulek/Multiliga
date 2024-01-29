#include "asdfaaa.h"
#include "ui_asdfaaa.h"

asdfaaa::asdfaaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asdfaaa)
{
    ui->setupUi(this);
}

asdfaaa::~asdfaaa()
{
    delete ui;
}
