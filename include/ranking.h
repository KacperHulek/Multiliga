#ifndef RANKING_H
#define RANKING_H

#include <QDialog>
#include "databasemanager.h"
namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~Ranking();

private slots:
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::Ranking *ui;
    DatabaseManager *dbManager;
    QSqlQueryModel  *listModel;
    QSqlQueryModel  *tableModel;
    int leagueID;
};

#endif // RANKING_H
