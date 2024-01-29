#ifndef WPISZWYNIKMECZU_H
#define WPISZWYNIKMECZU_H

#include <QDialog>
#include "databasemanager.h"
namespace Ui {
class WpiszWynikMeczu;
}

class WpiszWynikMeczu : public QDialog
{
    Q_OBJECT

public:
    explicit WpiszWynikMeczu(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr, int queueID = 0);
    ~WpiszWynikMeczu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::WpiszWynikMeczu *ui;
    DatabaseManager *dbManager;
    int queueID;
    QSqlQueryModel *model;

};

#endif // WPISZWYNIKMECZU_H
