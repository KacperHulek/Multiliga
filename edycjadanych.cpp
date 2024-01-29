#include "edycjadanych.h"
#include "ui_edycjadanych.h"
#include <QMessageBox>
#include "zmianaloginu.h"
#include "zmianahasla.h"
EdycjaDanych::EdycjaDanych(QWidget *parent,DatabaseManager *dbManager, MenuOpiekuna *mo) :
    QDialog(parent),
    ui(new Ui::EdycjaDanych),
    dbManager(dbManager),
    mo(mo)
{
    ui->setupUi(this);
}

EdycjaDanych::~EdycjaDanych()
{
    delete ui;
}

//zmiana loginu
void EdycjaDanych::on_pushButton_clicked()
{
    ZmianaLoginu *okno = new ZmianaLoginu(nullptr,dbManager);
    okno->show();
}


void EdycjaDanych::on_pushButton_3_clicked()
{
    int result = QMessageBox::question(nullptr, "Usuwanie konta", "Czy napewno usunac konto? Ta akcja jest nieodwracalna",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result == QMessageBox::Yes) {
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM Users WHERE [ID] = :userID");
        deleteQuery.bindValue(":userID", dbManager->getCurrentUserID());
        if (deleteQuery.exec()) {
            QMessageBox::information(nullptr, "Sukces", "Poprawnie usunieto konto!");
            mo->showMainWindow();
            mo->close();
            close();
        } else {
            qDebug() << deleteQuery.lastError().text();
            QMessageBox::information(nullptr, "Blad", "Blad podczas usuwania konta!");
        }
    } else {
        close();
    }
}


void EdycjaDanych::on_pushButton_2_clicked()
{
    ZmianaHasla *okno = new ZmianaHasla(nullptr,dbManager);
    okno->show();
}


void EdycjaDanych::on_pushButton_4_clicked()
{
    close();
}

