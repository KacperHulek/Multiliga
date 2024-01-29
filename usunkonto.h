#ifndef USUNKONTO_H
#define USUNKONTO_H

#include <QDialog>
#include "databasemanager.h"
namespace Ui {
class UsunKonto;
}

class UsunKonto : public QDialog
{
    Q_OBJECT

public:
    explicit UsunKonto(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~UsunKonto();

private:
    Ui::UsunKonto *ui;
    DatabaseManager *dbManager;
};

#endif // USUNKONTO_H
