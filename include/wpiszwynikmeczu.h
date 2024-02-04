#ifndef WPISZWYNIKMECZU_H
#define WPISZWYNIKMECZU_H

#include <QtSql>
#include <QDialog>
namespace Ui {
class WpiszWynikMeczu;
}

class WpiszWynikMeczu : public QDialog
{
    Q_OBJECT

public:
    explicit WpiszWynikMeczu(QWidget *parent = nullptr, int queueID = 0);
    ~WpiszWynikMeczu();

private slots:
    void on_wpiszWynikButton_clicked();

    void on_powrotButton_clicked();

private:
    Ui::WpiszWynikMeczu *ui;
    int queueID;
    QSqlQueryModel *model;


};

#endif // WPISZWYNIKMECZU_H
