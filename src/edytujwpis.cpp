#include "../include/edytujwpis.h"
#include "ui_edytujwpis.h"
#include <QSql>
#include <QMessageBox>
EdytujWpis::EdytujWpis(QWidget *parent, int recordID,QSqlQueryModel *model) :
    QDialog(parent),
    ui(new Ui::EdytujWpis),
    recordID(recordID),
    model(model)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM [Advertisements] WHERE [ID] = :recordID");
    query.bindValue(":recordID",recordID);
    if(query.exec() && query.next()){
        QString text = query.value("textBody").toString();
        ui->plainTextEdit->setPlainText(text);
    }



}

EdytujWpis::~EdytujWpis()
{
    delete ui;
}

void EdytujWpis::on_pushButton_clicked()
{
    //zatwierdz
    QString newText = ui->plainTextEdit->toPlainText();
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Advertisements SET [textBody] = :newText WHERE [ID] = :ID");
    updateQuery.bindValue(":newText", newText);
    updateQuery.bindValue(":ID", recordID);
    if (updateQuery.exec()) {
        model->setQuery("SELECT * FROM [TablicaOgloszen]");
        close();
    } else {
        QMessageBox::information(nullptr, "Blad", "Blad.");
    }
}


void EdytujWpis::on_pushButton_2_clicked()
{
    //anuluj
    close();
}

