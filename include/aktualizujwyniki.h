#ifndef AKTUALIZUJWYNIKI_H
#define AKTUALIZUJWYNIKI_H
#include <QtSql>
#include <QDialog>
namespace Ui {
class AktualizujWyniki;
}

class AktualizujWyniki : public QDialog
{
    Q_OBJECT

public:
    explicit AktualizujWyniki(QWidget *parent = nullptr);
    ~AktualizujWyniki();

private slots:
    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_listView_activated(const QModelIndex &index);

    void on_listView_2_clicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AktualizujWyniki *ui;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    int leagueID;
    int queueID;
};

#endif // AKTUALIZUJWYNIKI_H
