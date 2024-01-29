#ifndef RANKING_H
#define RANKING_H

#include <QtSql>
#include <QDialog>
namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = nullptr);
    ~Ranking();

private slots:
    void on_listaLigView_clicked(const QModelIndex &index);

private:
    Ui::Ranking *ui;
    QSqlQueryModel  *listModel;
    QSqlQueryModel  *tableModel;
    int leagueID;
};

#endif // RANKING_H
