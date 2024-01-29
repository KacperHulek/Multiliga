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
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::EdycjaDanych *ui;
    MenuOpiekuna *mo;
};

#endif // EDYCJADANYCH_H
