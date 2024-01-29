#ifndef ZMIANAHASLA_H
#define ZMIANAHASLA_H
#include <QtSql>
#include <QDialog>
namespace Ui {
class ZmianaHasla;
}

class ZmianaHasla : public QDialog
{
    Q_OBJECT

public:
    explicit ZmianaHasla(QWidget *parent = nullptr, int currentUserID = NULL);
    ~ZmianaHasla();

private slots:
    void on_zmienHasloButton_clicked();

    void on_powrotButton_clicked();

private:
    Ui::ZmianaHasla *ui;
    int currentUserID;
};

#endif // ZMIANAHASLA_H
