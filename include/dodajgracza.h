#ifndef DODAJGRACZA_H
#define DODAJGRACZA_H

#include <QDialog>
#include "databasemanager.h"
#include "edytujlige.h"

namespace Ui {
class DodajGracza;
}

class DodajGracza : public QDialog
{
    Q_OBJECT

public:
    explicit DodajGracza(QWidget *parent = nullptr,
                         DatabaseManager *dbManager = nullptr, EdytujLige *el = nullptr);
    ~DodajGracza();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DodajGracza *ui;
    DatabaseManager *dbManager;
    EdytujLige *el;
    QSqlQueryModel *model;
};

#endif // DODAJGRACZA_H
