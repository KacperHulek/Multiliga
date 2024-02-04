#ifndef EDYTUJLIGE_H
#define EDYTUJLIGE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class EdytujLige;
}

class EdytujLige : public QDialog
{
    Q_OBJECT

public:
    void updateStuff();
    int getQueueID();
    int getPlayerID();
    int getLeagueID();
    explicit EdytujLige(QWidget *parent = nullptr, int leagueID = 0);
    ~EdytujLige();

private slots:
    void on_zmienDateKolejkiButton_clicked();

    void on_edytujGraczaButton_clicked();

    void on_dodajGraczaButton_clicked();

    void on_powrotButton_clicked();

    void on_aktualizujPoziomyButton_clicked();

    void on_wygenerujMeczeButton_clicked();

private:
    Ui::EdytujLige *ui;
    QSqlQueryModel *model;
    int leagueID;
    int queueID;
    int playerID;
    int liczbaPoziomow = 3;
    int iluAwansuje = 0;
    int iluSpada = 0;
};

#endif // EDYTUJLIGE_H
