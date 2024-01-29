#ifndef SPOTKANIA_H
#define SPOTKANIA_H

#include <QDialog>
#include "databasemanager.h"
#include <QtSql>

namespace Ui {
class Spotkania;
}

class Spotkania : public QDialog
{
    Q_OBJECT

public:
    explicit Spotkania(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~Spotkania();

private:
    Ui::Spotkania *ui;
    DatabaseManager *dbManager;
    QSqlQueryModel *model;
};

#endif // SPOTKANIA_H
