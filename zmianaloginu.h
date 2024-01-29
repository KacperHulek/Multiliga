#ifndef ZMIANALOGINU_H
#define ZMIANALOGINU_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class ZmianaLoginu;
}

class ZmianaLoginu : public QDialog
{
    Q_OBJECT

public:
    explicit ZmianaLoginu(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~ZmianaLoginu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ZmianaLoginu *ui;
    DatabaseManager *dbManager;
};

#endif // ZMIANALOGINU_H
