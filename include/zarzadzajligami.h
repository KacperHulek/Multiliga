#ifndef ZARZADZAJLIGAMI_H
#define ZARZADZAJLIGAMI_H

#include <QtSql>
#include <QDialog>

namespace Ui {
class ZarzadzajLigami;
}

class ZarzadzajLigami : public QDialog
{
    Q_OBJECT

public:
    explicit ZarzadzajLigami(QWidget *parent = nullptr, int currentUserID = 0);
    ~ZarzadzajLigami();

private slots:
    void on_wybierzButton_clicked();

    void on_powrotButton_clicked();

private:
    Ui::ZarzadzajLigami *ui;
    QSqlQueryModel *model;
    int currentUserID;
};

#endif // ZARZADZAJLIGAMI_H
