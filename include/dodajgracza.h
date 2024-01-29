#ifndef DODAJGRACZA_H
#define DODAJGRACZA_H

#include <QtSql>
#include <QDialog>
#include "edytujlige.h"

namespace Ui {
class DodajGracza;
}

class DodajGracza : public QDialog
{
    Q_OBJECT

public:
    explicit DodajGracza(QWidget *parent = nullptr, EdytujLige *el = nullptr);
    ~DodajGracza();

private slots:
    void on_zatwierdzButton_clicked();

    void on_powrotButton_clicked();

private:
    Ui::DodajGracza *ui;
    EdytujLige *el;
    QSqlQueryModel *model;
};

#endif // DODAJGRACZA_H
