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
    explicit EdytujLige(QWidget *parent = nullptr, int leagueID = 0);
    ~EdytujLige();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EdytujLige *ui;
    QSqlQueryModel *model;
    int leagueID;
    int queueID;
    int playerID;
};

#endif // EDYTUJLIGE_H
