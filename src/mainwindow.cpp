#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include "../include/databasemanager.h"
#include "../include/menuopiekuna.h"
#include "../include/rejestracja.h"
#include "bcrypt/BCrypt.hpp"
#include <iostream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    dbManager(nullptr) // Inicjalizacja obiektu DatabaseManager
{
    ui->setupUi(this);

    QString dbname = "../sqlitedb.db";

    dbManager = new DatabaseManager(dbname); // Tworzenie obiektu DatabaseManager

    if (dbManager->openConnection()) {
        qDebug() << "Connected to the database.";
    } else {
        qDebug()<<"Error = "<<dbManager->lastError();
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    if (dbManager) {
        dbManager->closeConnection(); // Zamknij połączenie z bazą danych
        delete dbManager; // Zwolnij zasoby obiektu DatabaseManager
    }
}

void MainWindow::on_zalogujButton_clicked()
{
    QString login = ui->loginText->text();
    QString haslo = ui->hasloText->text();
    ui->hasloText->setText("");
    if (dbManager) {
        QSqlQuery loginquery;
        loginquery.prepare("SELECT * FROM [Users] WHERE login = :login");
        loginquery.bindValue(":login", login);

        if (loginquery.exec() && loginquery.next()) {
            //Login istnieje
            QByteArray storedPassword = loginquery.value("password").toByteArray();
            QString storedPasswordString = QString::fromUtf8(storedPassword);
            if(BCrypt::validatePassword(haslo.toStdString(),storedPasswordString.toStdString())){
                dbManager->setCurrentUserID(loginquery.value("ID").toInt());
                Role rola = getRoleFromString(loginquery.value("role").toString());
                switch (rola){
                case Role::opiekun:{
                    this->hide();

                    MenuOpiekuna *menu = new MenuOpiekuna(nullptr, dbManager,this);
                    menu->show();

                    break;
                }
                case Role::gracz:{
                    QMessageBox::information(nullptr, "Uwaga", "Interfejs dla gracza nie zostal zaimplementowany!");
                    break;
                }
                }
            }else {
                // Błędny login lub hasło
                QMessageBox::information(nullptr, "Blad", "Niepoprawne dane logowania!");
            }

        } else {
            // Błędny login lub hasło
            QMessageBox::information(nullptr, "Blad", "Niepoprawne dane logowania!");
        }
    }
    login = NULL;
    haslo = NULL;
}

void MainWindow::on_zarejestrujButton_clicked()
{
    Rejestracja *rejestracja = new Rejestracja(nullptr, dbManager); // Przekazanie wskaźnika do DatabaseManager
    rejestracja->show();
}

Role MainWindow::getRoleFromString(const QString& roleStr) {
    if (roleStr == "opiekun") {
        return Role::opiekun;
    } else if (roleStr == "gracz") {
        return Role::gracz;
    }
    else if (roleStr == "wlasciciel") {
        return Role::wlasciciel;
    }
    else if (roleStr == "ksiegowa") {
        return Role::ksiegowa;
    }
    else if (roleStr == "sponsor") {
        return Role::sponsor;
    }
    return Role::gosc; // Domyślna rola
}
