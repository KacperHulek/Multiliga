#include "../include/rejestracja.h"
#include "ui_rejestracja.h"
#include <QMessageBox>
#include "bcrypt/BCrypt.hpp"

Rejestracja::Rejestracja(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::Rejestracja),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

Rejestracja::~Rejestracja()
{
    delete ui;
}

void Rejestracja::on_pushButton_clicked()
{
    QString login = ui->loginText->text();
    QString haslo = ui->hasloText->text();
    QString phaslo = ui->powtorzhasloText->text();
    QString email = ui->emailText->text();
    QString imie = ui->imieText->text();
    QString nazwisko = ui->nazwiskoText->text();
    QString uprawnienia = ui->comboBox->currentText();

    if(login.isEmpty() || haslo.isEmpty() || phaslo.isEmpty() || email.isEmpty() || imie.isEmpty() || nazwisko.isEmpty())
        QMessageBox::information(nullptr, "Ostrzezenie", "Wypelnij wszystkie pola!");
    else if(haslo != phaslo)
        QMessageBox::information(nullptr, "Ostrzezenie", "Niepoprawnie powtorzone haslo!");
    else if(login.size()>50 || haslo.size()>50 || phaslo.size()>50 || email.size()>50 || imie.size()>50 || nazwisko.size()>50)
        QMessageBox::information(nullptr, "Ostrzezenie", "Maksymalna liczba znakow to 50!");
    else if(login.size()<4 || haslo.size()<4 || phaslo.size()<4 || email.size()<4 || imie.size()<2 || nazwisko.size()<2)
        QMessageBox::information(nullptr, "Ostrzezenie", "Minimalna liczba znakow to 4 (2 dla imienia i nazwiska)!");
    else if (dbManager){
        QSqlQuery querylogin;
        querylogin.prepare("SELECT [login] FROM [Users] WHERE login = :login");
        querylogin.bindValue(":login", login);

        QSqlQuery queryemail;
        queryemail.prepare("SELECT [email] FROM [Users] WHERE email = :email");
        queryemail.bindValue(":email", email);

        if (querylogin.exec() && querylogin.next())
            QMessageBox::information(nullptr, "Ostrzeżenie", "Podany login już istnieje!");
        else if(queryemail.exec() && queryemail.next())
            QMessageBox::information(nullptr, "Ostrzeżenie", "Podany email już istnieje!");
        else {
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO [Users] ([login], [password], [email], [name], [surname], [role]) "
                                "VALUES (:login, :password, :email, :name, :surname, :role)");

            insertQuery.bindValue(":login", login);
            std::string stdHashedPassword = BCrypt::generateHash(haslo.toStdString());
            QString hashedPassword = QString().fromStdString(stdHashedPassword);
            QByteArray hashedPasswordBytes = hashedPassword.toUtf8();
            insertQuery.bindValue(":password", hashedPasswordBytes);
            insertQuery.bindValue(":email", email);
            insertQuery.bindValue(":name", imie);
            insertQuery.bindValue(":surname", nazwisko);
            insertQuery.bindValue(":role", uprawnienia);

            if (insertQuery.exec()){
                QMessageBox::information(nullptr, "Sukces", "Rejestracja udana!");
                hide();
            }
            else
                QMessageBox::critical(nullptr, "Błąd", "Błąd podczas rejestracji!");
        }
    }
    else
        QMessageBox::information(nullptr, "Ostrzezenie", "Brak polaczenia z baza danych!");
}

