#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include "../include/menuopiekuna.h"
#include "../include/rejestracja.h"
#include "bcrypt/BCrypt.hpp"
#include <iostream>
#include <QMessageBox>
#include <QtSql>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../sqlitedb.db");

    if (db.open()){
        qDebug() << "Connected to the database.";
        queueSmartUpdate();

    } else {
        qDebug()<<"Error = "<< db.lastError();
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    if (db.isOpen()){
        db.close();
    }
}

void MainWindow::queueSmartUpdate(){
    QVector<int> leagues;
    QSqlQuery query;
    query.prepare("SELECT [ID] FROM [Leagues]");
    if(query.exec()){
        while(query.next()){
            int leagueID = query.value(0).toInt();
            leagues.append(leagueID);
        }
    }else{
        qDebug()<<"Error: "<<query.lastError();
    }

    for(int i : leagues){
        QSqlQuery queueQuery;
        queueQuery.prepare("SELECT * FROM [Queues] WHERE [leagueID] = :leagueID ORDER BY [date] DESC");
        queueQuery.bindValue(":leagueID",i);
        if(queueQuery.exec()&&queueQuery.next()){
            qDebug()<<queueQuery.value("date").toDate();
            qDebug()<<QDate::currentDate();
            if(queueQuery.value("date").toDate()<=QDate::currentDate()){
                qDebug()<<"test";
                //trzeba dodac nowa kolejke
                int seasonID = queueQuery.value("seasonID").toInt();
                QDate date = queueQuery.value("date").toDate();
                QSqlQuery insertQueueQuery;
                insertQueueQuery.prepare("INSERT INTO [Queues] ([leagueID], [seasonID], [date]) VALUES "
                                         "(:leagueID, :seasonID, :date)");
                insertQueueQuery.bindValue(":leagueID",i);
                insertQueueQuery.bindValue(":seasonID",seasonID);
                insertQueueQuery.bindValue(":date",date.addDays(7));
                if(insertQueueQuery.exec()){
                    //inserted new queue
                }else{
                    qDebug()<<"Error: "<<insertQueueQuery.lastError();
                }

            }
        }
    }
}

void MainWindow::on_zalogujButton_clicked()
{
    QString login = ui->loginText->text();
    QString haslo = ui->hasloText->text();
    ui->hasloText->setText("");
    if (db.isOpen()) {
        QSqlQuery loginquery;
        loginquery.prepare("SELECT * FROM [Users] WHERE login = :login");
        loginquery.bindValue(":login", login);

        if (loginquery.exec() && loginquery.next()) {
            //Login istnieje
            QByteArray storedPassword = loginquery.value("password").toByteArray();
            QString storedPasswordString = QString::fromUtf8(storedPassword);
            if(BCrypt::validatePassword(haslo.toStdString(),storedPasswordString.toStdString())){
                setCurrentUserID(loginquery.value("ID").toInt());
                Role rola = getRoleFromString(loginquery.value("role").toString());
                switch (rola){
                case Role::opiekun:{
                    this->hide();

                    MenuOpiekuna *menu = new MenuOpiekuna(nullptr, this);
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
    Rejestracja *rejestracja = new Rejestracja(nullptr); // Przekazanie wskaźnika do DatabaseManager
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

void MainWindow::setCurrentUserID(int ID){
    currentUserID = ID;
}
int MainWindow::getCurrentUserID(){
    return currentUserID;
}
