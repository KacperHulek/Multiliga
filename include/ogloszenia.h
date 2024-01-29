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

    void on_edytujButton_clicked();

    void on_usunButton_clicked();

    void on_dodajButton_clicked();

    void on_powrotButton_clicked();

private:
    Ui::Ogloszenia *ui;
    QSqlQueryModel *model;
    int currentUserID;
};

#endif // OGLOSZENIA_H
