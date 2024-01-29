#include "../include/menuopiekuna.h"
#include "ui_menuopiekuna.h"
#include "../include/spotkania.h"
#include "../include/edycjadanych.h"
#include "../include/ogloszenia.h"
#include "../include/zarzadzajligami.h"
#include "../include/aktualizujwyniki.h"
#include "../include/ranking.h"

MenuOpiekuna::MenuOpiekuna(QWidget *parent,
DatabaseManager *dbManager, MainWindow *mw) :
    QWidget(parent),
    ui(new Ui::MenuOpiekuna),
    dbManager(dbManager),
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
    Spotkania *spotkania = new Spotkania(nullptr,dbManager);
    spotkania->show();
}

void MenuOpiekuna::on_edytujButton_clicked()
{
    EdycjaDanych *okno = new EdycjaDanych(nullptr, dbManager,this);
    okno->show();
}

void MenuOpiekuna::showMainWindow()
{
    mw->show();
}

void MenuOpiekuna::on_wylogujButton_clicked()
{
    dbManager->clearCurrentUserID();
    this->close();
    mw->show();
}


void MenuOpiekuna::on_tablicaButton_clicked()
{
    Ogloszenia *okno = new Ogloszenia(nullptr,dbManager);
    okno->show();
}


void MenuOpiekuna::on_zarzadzajButton_clicked()
{
    ZarzadzajLigami *okno = new ZarzadzajLigami(nullptr,dbManager);
    okno->show();
}


void MenuOpiekuna::on_analizujButton_clicked()
{
    AktualizujWyniki *okno = new AktualizujWyniki(nullptr,dbManager);
    okno->show();
}


void MenuOpiekuna::on_rankingButton_clicked()
{
    //ranking
    Ranking *okno = new Ranking(nullptr,dbManager);
    okno->show();
}

