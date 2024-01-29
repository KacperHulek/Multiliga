#include "ogloszenia.h"
#include "ui_ogloszenia.h"
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QPlainTextEdit>
#include "edytujwpis.h"
#include "dodajogloszenie.h"
Ogloszenia::Ogloszenia(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::Ogloszenia),
    dbManager(dbManager)
{
    ui->setupUi(this);
    ui->listView->setWordWrap(true);

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM [TablicaOgloszen]");
    ui->listView->setModel(model);


}

Ogloszenia::~Ogloszenia()
{
    delete ui;
}

void Ogloszenia::on_pushButton_2_clicked()
{
    //usun wpis
    int result = QMessageBox::question(nullptr, "Usuwanie wpisu", "Czy napewno usunac dany wpis? Ta akcja jest nieodwracalna!",
                                       QMessageBox::Yes | QMessageBox::No);

    if (result == QMessageBox::Yes){
        QModelIndex currentIndex = ui->listView->currentIndex();

        int deleteID = model->record(currentIndex.row()).value("ID").toInt();
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM [Advertisements] WHERE ID = :id");
        deleteQuery.bindValue(":id", deleteID);

        if (deleteQuery.exec()) {
            model->setQuery("SELECT * FROM [TablicaOgloszen]");
        } else {
            qDebug() << "Error deleting record:" << deleteQuery.lastError().text();
        }
    }
}




void Ogloszenia::on_pushButton_clicked()
{
    // edytuj wpis
    QModelIndex currentIndex = ui->listView->currentIndex();
    int recordID = model->record(currentIndex.row()).value("ID").toInt();
    EdytujWpis *okno = new EdytujWpis(nullptr,dbManager,recordID,model);
    okno->show();
}


void Ogloszenia::on_pushButton_3_clicked()
{
    //dodaj nowe ogloszenie
    DodajOgloszenie *okno = new DodajOgloszenie(nullptr,dbManager,model);
    okno->show();

}


void Ogloszenia::on_pushButton_4_clicked()
{
    close();
}

