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
    void on_dalejButton_clicked();

    void on_powrotButton_clicked();

    void on_listaLigView_clicked(const QModelIndex &index);

    void on_listaKolejekView_clicked(const QModelIndex &index);

private:
    Ui::AktualizujWyniki *ui;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    int leagueID;
    int queueID;
};

#endif // AKTUALIZUJWYNIKI_H
