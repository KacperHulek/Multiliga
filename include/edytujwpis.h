#ifndef EDYTUJWPIS_H
#define EDYTUJWPIS_H
#include <QtSql>
#include <QDialog>
namespace Ui {
class EdytujWpis;
}

class EdytujWpis : public QDialog
{
    Q_OBJECT

public:
    explicit EdytujWpis(QWidget *parent = nullptr, int recordID = 0, QSqlQueryModel *model=nullptr);
    ~EdytujWpis();

private slots:
    void on_zatwierdzButton_clicked();

    void on_anulujButton_clicked();

private:
    Ui::EdytujWpis *ui;
    int recordID;
    QSqlQueryModel *model;
};

#endif // EDYTUJWPIS_H
