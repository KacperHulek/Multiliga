#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QMainWindow>
enum class Role {
    opiekun,
    gracz,
    wlasciciel,
    ksiegowa,
    sponsor,
    gosc
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setCurrentUserID(int ID);
    int getCurrentUserID();

private slots:
    void on_zalogujButton_clicked();

    void on_zarejestrujButton_clicked();

private:
    Ui::MainWindow *ui;
    Role getRoleFromString(const QString& roleStr);
    QSqlDatabase db;
    int currentUserID;
};

#endif // MAINWINDOW_H
