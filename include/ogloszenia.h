#ifndef OGLOSZENIA_H
#define OGLOSZENIA_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Ogloszenia;
}

class Ogloszenia : public QDialog
{
    Q_OBJECT

public:
    explicit Ogloszenia(QWidget *parent = nullptr, int currentUserID = NULL);
    ~Ogloszenia();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Ogloszenia *ui;
    QSqlQueryModel *model;
    int currentUserID;
};

#endif // OGLOSZENIA_H
