#include "../include/edycjadanych.h"
#include "ui_edycjadanych.h"
#include <QMessageBox>
#include "../include/zmianaloginu.h"
#include "../include/zmianahasla.h"
EdycjaDanych::EdycjaDanych(QWidget *parent, MenuOpiekuna *mo) :
    QDialog(parent),
    ui(new Ui::EdycjaDanych),
    mo(mo)
{
    ui->setupUi(this);
}

EdycjaDanych::~EdycjaDanych()
{
    delete ui;
}

void EdycjaDanych::on_zmienLoginButton_clicked()
{
    ZmianaLoginu *okno = new ZmianaLoginu(nullptr, mo->getCurrentUserID());
    okno->show();
}


void EdycjaDanych::on_zmienHasloButton_clicked()
{
    ZmianaHasla *okno = new ZmianaHasla(nullptr,mo->getCurrentUserID());
    okno->show();
}


void EdycjaDanych::on_usunKontoButton_clicked()
{
    int result = QMessageBox::question(nullptr, "Usuwanie konta", "Czy napewno usunac konto? Ta akcja jest nieodwracalna",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result == QMessageBox::Yes) {
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM Users WHERE [ID] = :userID");
        deleteQuery.bindValue(":userID", mo->getCurrentUserID());
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

    }
}


void EdycjaDanych::on_zamknijButton_clicked()
{
    close();
}

