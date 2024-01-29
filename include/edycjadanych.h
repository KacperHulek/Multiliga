#ifndef EDYCJADANYCH_H
#define EDYCJADANYCH_H

#include <QtSql>
#include <QDialog>
#include "menuopiekuna.h"
namespace Ui {
class EdycjaDanych;
}

class EdycjaDanych : public QDialog
{
    Q_OBJECT

public:
    explicit EdycjaDanych(QWidget *parent = nullptr, MenuOpiekuna *mo = nullptr);
    ~EdycjaDanych();


private slots:
    void on_zmienLoginButton_clicked();

    void on_zmienHasloButton_clicked();

    void on_usunKontoButton_clicked();

    void on_zamknijButton_clicked();

private:
    Ui::EdycjaDanych *ui;
    MenuOpiekuna *mo;
};

#endif // EDYCJADANYCH_H
