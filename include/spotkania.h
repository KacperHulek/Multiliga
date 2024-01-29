#ifndef SPOTKANIA_H
#define SPOTKANIA_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Spotkania;
}

class Spotkania : public QDialog
{
    Q_OBJECT

public:
    explicit Spotkania(QWidget *parent = nullptr);
    ~Spotkania();

private slots:
    void on_powrotButton_clicked();

private:
    Ui::Spotkania *ui;
    QSqlQueryModel *model;
};

#endif // SPOTKANIA_H
