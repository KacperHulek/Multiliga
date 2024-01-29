#ifndef ZMIENDATEKOLEJKI_H
#define ZMIENDATEKOLEJKI_H

#include <QDialog>
#include "databasemanager.h"
#include "edytujlige.h"
//do zrobienia
namespace Ui {
class ZmienDateKolejki;
}

class ZmienDateKolejki : public QDialog
{
    Q_OBJECT

public:
    explicit ZmienDateKolejki(QWidget *parent = nullptr,
                              DatabaseManager *dbManager = nullptr, EdytujLige *el = nullptr);
    ~ZmienDateKolejki();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ZmienDateKolejki *ui;
    DatabaseManager *dbManager;
    EdytujLige *el;
};

#endif // ZMIENDATEKOLEJKI_H
