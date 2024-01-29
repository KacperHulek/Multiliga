#ifndef EDYTUJWPIS_H
#define EDYTUJWPIS_H

#include <QDialog>
#include "databasemanager.h"
namespace Ui {
class EdytujWpis;
}

class EdytujWpis : public QDialog
{
    Q_OBJECT

public:
    explicit EdytujWpis(QWidget *parent = nullptr,
                        DatabaseManager *dbManager = nullptr, int recordID = 0,QSqlQueryModel *model=nullptr);
    ~EdytujWpis();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EdytujWpis *ui;
    DatabaseManager *dbManager;
    int recordID;
    QSqlQueryModel *model;
};

#endif // EDYTUJWPIS_H
