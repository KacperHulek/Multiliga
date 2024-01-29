#include "../include/zmiendatekolejki.h"
#include "ui_zmiendatekolejki.h"
#include <QMessageBox>

ZmienDateKolejki::ZmienDateKolejki(QWidget *parent, EdytujLige *el) :
    QDialog(parent),
    ui(new Ui::ZmienDateKolejki),
    el(el)
{
    ui->setupUi(this);
}

ZmienDateKolejki::~ZmienDateKolejki()
{
    delete ui;
}

void ZmienDateKolejki::on_pushButton_2_clicked()
{
    //anuluj
    close();
}


void ZmienDateKolejki::on_pushButton_clicked()
{
    //zatwierdz
    if(ui->dateTimeEdit->dateTime()<QDateTime::currentDateTime().addDays(1)){
        QMessageBox::information(nullptr, "Blad", "Podana data musi być większa od aktualnej o co najmniej 1 dzień!");
    }
    else{
        QDateTime newDate = ui->dateTimeEdit->dateTime();
        QSqlQuery query;
        query.prepare("UPDATE [Queues] SET [date] = :newDate WHERE [ID] = :queueID");
        query.bindValue(":queueID",el->getQueueID());
        query.bindValue(":newDate",newDate);
        if (query.exec()){
            el->updateStuff();
            close();
        }else{
            QMessageBox::information(nullptr, "Blad", "Blad");
        }

    }
}

