#include "../include/zmianahasla.h"
#include "ui_zmianahasla.h"
#include <QDebug>
#include "bcrypt/BCrypt.hpp"
#include <QMessageBox>

ZmianaHasla::ZmianaHasla(QWidget *parent, int currentUserID) :
    QDialog(parent),
    ui(new Ui::ZmianaHasla),
    currentUserID(currentUserID)
{
    ui->setupUi(this);
}

ZmianaHasla::~ZmianaHasla()
{
    delete ui;
}

void ZmianaHasla::on_pushButton_clicked()
{
    QString stareHaslo = ui->stareHasloText->text();
    QString noweHaslo = ui->noweHasloText->text();
    QString powtorzHaslo = ui->powtorzHasloText->text();

    if(noweHaslo.size()<4||noweHaslo.size()>50)
        QMessageBox::information(nullptr, "Blad", "Nieprawidlowa ilosc znakow nowego hasla!");
    else if (noweHaslo!=powtorzHaslo)
        QMessageBox::information(nullptr, "Blad", "Niepoprawnie powtorzone nowe haslo!");

    else {
        qDebug()<<"test1";
        QSqlQuery query;
        qDebug()<<"test2";
        query.prepare("SELECT * FROM Users WHERE [ID] = :ID");
        query.bindValue(":ID", currentUserID);
        qDebug()<<"test3";
        if(query.exec() && query.next()){
            QByteArray storedPassword = query.value("password").toByteArray();
            QString storedPasswordString = QString::fromUtf8(storedPassword);
            if(BCrypt::validatePassword(stareHaslo.toStdString(),storedPasswordString.toStdString())){
                int result = QMessageBox::question(nullptr, "Zmiana hasla", "Czy napewno zmienic haslo?",
                                                   QMessageBox::Yes | QMessageBox::No);

                if (result == QMessageBox::Yes) {
                    std::string stdHashedPassword = BCrypt::generateHash(noweHaslo.toStdString());
                    QString hashedPassword = QString().fromStdString(stdHashedPassword);
                    QByteArray hashedPasswordBytes = hashedPassword.toUtf8();

                    QSqlQuery updateQuery;
                    updateQuery.prepare("UPDATE Users SET [password] = :newPassword WHERE [ID] = :ID");
                    updateQuery.bindValue(":newPassword", hashedPasswordBytes);
                    updateQuery.bindValue(":ID", currentUserID);

                    if (updateQuery.exec()) {
                        QMessageBox::information(nullptr, "Sukces", "Poprawnie zmieniono haslo!");
                        close();
                    } else {
                        QMessageBox::information(nullptr, "Blad", "Blad.");
                    }
                }
                else {}


            } else {
                QMessageBox::information(nullptr, "Blad", "Bledne haslo!");
            }
        }
        else
            qDebug() << query.lastError().text();
    }

}

