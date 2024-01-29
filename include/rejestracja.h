#ifndef REJESTRACJA_H
#define REJESTRACJA_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class Rejestracja;
}

class Rejestracja : public QDialog
{
    Q_OBJECT

public:
    explicit Rejestracja(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~Rejestracja();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Rejestracja *ui;
    DatabaseManager *dbManager;
};

#endif // REJESTRACJA_H
