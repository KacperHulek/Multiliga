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
    explicit ZmianaLoginu(QWidget *parent = nullptr, int getCurrentUserID= NULL);
    ~ZmianaLoginu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ZmianaLoginu *ui;
    int currentUserID;
};

#endif // ZMIANALOGINU_H
