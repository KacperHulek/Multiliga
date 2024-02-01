#ifndef ZMIANALOGINU_H
#define ZMIANALOGINU_H
#include <QtSql>
#include <QDialog>

namespace Ui {
class ZmianaLoginu;
}

class ZmianaLoginu : public QDialog
{
    Q_OBJECT

public:
    explicit ZmianaLoginu(QWidget *parent = nullptr, int getCurrentUserID= 0);
    ~ZmianaLoginu();

private slots:
    void on_zmienLoginButton_clicked();

    void on_powrotButton_clicked();

private:
    Ui::ZmianaLoginu *ui;
    int currentUserID;
};

#endif // ZMIANALOGINU_H
