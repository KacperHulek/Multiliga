#ifndef ZARZADZAJLIGAMI_H
#define ZARZADZAJLIGAMI_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class ZarzadzajLigami;
}

class ZarzadzajLigami : public QDialog
{
    Q_OBJECT

public:
    explicit ZarzadzajLigami(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~ZarzadzajLigami();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ZarzadzajLigami *ui;
    DatabaseManager *dbManager;
    QSqlQueryModel *model;
};

#endif // ZARZADZAJLIGAMI_H
