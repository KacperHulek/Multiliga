#include "zmianaloginu.h"
#include "ui_zmianaloginu.h"
#include <QDebug>
#include "bcrypt/BCrypt.hpp"
#include <QMessageBox>

ZmianaLoginu::ZmianaLoginu(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::ZmianaLoginu),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

ZmianaLoginu::~ZmianaLoginu()
{
    delete ui;
}

void ZmianaLoginu::on_pushButton_clicked()
{
    QString nowyLogin = ui->nowyLoginText->text();
    QString wpisaneHaslo = ui->hasloText->text();
    QSqlQuery loginquery;
    loginquery.prepare("SELECT * FROM Users WHERE [login] = :login");
    loginquery.bindValue(":login", nowyLogin);

    if(nowyLogin.size()<4||nowyLogin.size()>50)
        QMessageBox::information(nullptr, "Blad", "Nieprawidlowa ilosc znakow nowego loginu!");
    else if(loginquery.exec() && loginquery.next())
        QMessageBox::information(nullptr, "Blad", "Podany login juz istnieje!");
    else{
        QSqlQuery query;
        query.prepare("SELECT * FROM Users WHERE [ID] = :ID");
        query.bindValue(":ID", dbManager->getCurrentUserID());
        if(query.exec() && query.next()){
            QByteArray storedPassword = query.value("password").toByteArray();
            QString storedPasswordString = QString::fromUtf8(storedPassword);
            if(BCrypt::validatePassword(wpisaneHaslo.toStdString(),storedPasswordString.toStdString())){
                int result = QMessageBox::question(nullptr, "Zmiana loginu", "Czy napewno zmienic login?",
                                                   QMessageBox::Yes | QMessageBox::No);
                if (result == QMessageBox::Yes){
                    QSqlQuery updateQuery;
                    updateQuery.prepare("UPDATE Users SET [login] = :newLogin WHERE [ID] = :ID");
                    updateQuery.bindValue(":newLogin", nowyLogin);
                    updateQuery.bindValue(":ID", dbManager->getCurrentUserID());
                    if (updateQuery.exec()) {
                        QMessageBox::information(nullptr, "Sukces", "Poprawnie zmieniono login!");
                        close();
                    } else {
                        QMessageBox::information(nullptr, "Blad", "Blad.");
                    }
                }

            } else {
                QMessageBox::information(nullptr, "Blad", "Nieprawidlowe haslo!");
            }
        }
        else{
            qDebug() << query.lastError().text();
        }
    }
}

