#ifndef ZMIENDATEKOLEJKI_H
#define ZMIENDATEKOLEJKI_H
#include <QtSql>
#include <QDialog>
#include "edytujlige.h"
namespace Ui {
class ZmienDateKolejki;
}

class ZmienDateKolejki : public QDialog
{
    Q_OBJECT

public:
    explicit ZmienDateKolejki(QWidget *parent = nullptr, EdytujLige *el = nullptr);
    ~ZmienDateKolejki();

private slots:
    void on_zatwierdzButton_clicked();

    void on_anulujButton_clicked();

private:
    Ui::ZmienDateKolejki *ui;
    EdytujLige *el;
};

#endif // ZMIENDATEKOLEJKI_H
