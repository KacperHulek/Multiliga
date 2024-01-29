#ifndef DODAJOGLOSZENIE_H
#define DODAJOGLOSZENIE_H

#include <QtSql>
#include <QDialog>
namespace Ui {
class DodajOgloszenie;
}

class DodajOgloszenie : public QDialog
{
    Q_OBJECT

public:
    explicit DodajOgloszenie(QWidget *parent = nullptr, QSqlQueryModel *model=nullptr, int currentUserID = NULL);
    ~DodajOgloszenie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DodajOgloszenie *ui;
    QSqlQueryModel *model;
    int currentUserID;
};

#endif // DODAJOGLOSZENIE_H
