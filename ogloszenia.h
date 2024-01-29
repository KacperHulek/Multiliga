#ifndef OGLOSZENIA_H
#define OGLOSZENIA_H

#include <QDialog>
#include "databasemanager.h"
#include <QtSql>

namespace Ui {
class Ogloszenia;
}

class Ogloszenia : public QDialog
{
    Q_OBJECT

public:
    explicit Ogloszenia(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~Ogloszenia();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Ogloszenia *ui;
    DatabaseManager *dbManager;
    QSqlQueryModel *model;
};

#endif // OGLOSZENIA_H
