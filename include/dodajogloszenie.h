#ifndef DODAJOGLOSZENIE_H
#define DODAJOGLOSZENIE_H

#include <QDialog>
#include "databasemanager.h"
namespace Ui {
class DodajOgloszenie;
}

class DodajOgloszenie : public QDialog
{
    Q_OBJECT

public:
    explicit DodajOgloszenie(QWidget *parent = nullptr,
                             DatabaseManager *dbManager = nullptr,QSqlQueryModel *model=nullptr);
    ~DodajOgloszenie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DodajOgloszenie *ui;
    DatabaseManager *dbManager;
    QSqlQueryModel *model;
};

#endif // DODAJOGLOSZENIE_H
