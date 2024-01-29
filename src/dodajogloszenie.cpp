#include "../include/dodajogloszenie.h"
#include "ui_dodajogloszenie.h"
#include <QMessageBox>
DodajOgloszenie::DodajOgloszenie(QWidget *parent,
                                 DatabaseManager *dbManager,QSqlQueryModel *model) :
    QDialog(parent),
    ui(new Ui::DodajOgloszenie),
    dbManager(dbManager),
    model(model)
{
    ui->setupUi(this);
}

DodajOgloszenie::~DodajOgloszenie()
{
    delete ui;
}

void DodajOgloszenie::on_pushButton_clicked()
{
    //dodaj ogloszenie
    QString textBody = ui->plainTextEdit->toPlainText();
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO [Advertisements] ([userID],[textBody]) "
                        "VALUES (:userID, :textBody)");

    insertQuery.bindValue(":userID", dbManager->getCurrentUserID());
    insertQuery.bindValue(":textBody", textBody);
    if(insertQuery.exec()){
        model->setQuery("SELECT * FROM [TablicaOgloszen]");
        close();
    }else {
        QMessageBox::information(nullptr, "Blad", "Blad.");
    }
}


void DodajOgloszenie::on_pushButton_2_clicked()
{
    close();
}

