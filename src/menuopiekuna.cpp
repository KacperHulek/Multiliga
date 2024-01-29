#include "../include/menuopiekuna.h"
#include "ui_menuopiekuna.h"
#include "../include/spotkania.h"
#include "../include/edycjadanych.h"
#include "../include/ogloszenia.h"
#include "../include/zarzadzajligami.h"
#include "../include/aktualizujwyniki.h"
#include "../include/ranking.h"

MenuOpiekuna::MenuOpiekuna(QWidget *parent, MainWindow *mw) :
    QWidget(parent),
    ui(new Ui::MenuOpiekuna),
    mw(mw)
{
    ui->setupUi(this);
}

MenuOpiekuna::~MenuOpiekuna()
{
    delete ui;
}

void MenuOpiekuna::on_harmonogramButton_clicked()
{
    Spotkania *spotkania = new Spotkania(nullptr);
    spotkania->show();
}

void MenuOpiekuna::on_edytujButton_clicked()
{
    EdycjaDanych *okno = new EdycjaDanych(nullptr,this);
    okno->show();
}

void MenuOpiekuna::showMainWindow()
{
    mw->show();
}

void MenuOpiekuna::on_wylogujButton_clicked()
{
    mw->setCurrentUserID(NULL);
    this->close();
    mw->show();
}


void MenuOpiekuna::on_tablicaButton_clicked()
{
    Ogloszenia *okno = new Ogloszenia(nullptr,mw->getCurrentUserID());
    okno->show();
}


void MenuOpiekuna::on_zarzadzajButton_clicked()
{
    ZarzadzajLigami *okno = new ZarzadzajLigami(nullptr,mw->getCurrentUserID());
    okno->show();
}


void MenuOpiekuna::on_analizujButton_clicked()
{
    AktualizujWyniki *okno = new AktualizujWyniki(nullptr);
    okno->show();
}


void MenuOpiekuna::on_rankingButton_clicked()
{
    //ranking
    Ranking *okno = new Ranking(nullptr);
    okno->show();
}

int MenuOpiekuna::getCurrentUserID(){
    return mw->getCurrentUserID();
}
