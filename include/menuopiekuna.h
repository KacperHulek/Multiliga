#ifndef MENUOPIEKUNA_H
#define MENUOPIEKUNA_H

#include <QWidget>
#include "databasemanager.h"
#include "mainwindow.h"
namespace Ui {
class MenuOpiekuna;
}

class MenuOpiekuna : public QWidget
{
    Q_OBJECT

public:
    explicit MenuOpiekuna(QWidget *parent = nullptr,
    DatabaseManager *dbManager = nullptr, MainWindow *mw = nullptr);
    void showMainWindow();
    ~MenuOpiekuna();

private slots:
    void on_harmonogramButton_clicked();

    void on_edytujButton_clicked();

    void on_wylogujButton_clicked();

    void on_tablicaButton_clicked();

    void on_zarzadzajButton_clicked();

    void on_analizujButton_clicked();

    void on_rankingButton_clicked();

private:
    Ui::MenuOpiekuna *ui;
    DatabaseManager *dbManager;
    MainWindow *mw;
};

#endif // MENUOPIEKUNA_H
