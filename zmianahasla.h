#ifndef ZMIANAHASLA_H
#define ZMIANAHASLA_H

#include <QDialog>
#include "databasemanager.h"
namespace Ui {
class ZmianaHasla;
}

class ZmianaHasla : public QDialog
{
    Q_OBJECT

public:
    explicit ZmianaHasla(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~ZmianaHasla();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ZmianaHasla *ui;
    DatabaseManager *dbManager;
};

#endif // ZMIANAHASLA_H
