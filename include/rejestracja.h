#ifndef REJESTRACJA_H
#define REJESTRACJA_H

#include <QtSql>
#include <QDialog>

namespace Ui {
class Rejestracja;
}

class Rejestracja : public QDialog
{
    Q_OBJECT

public:
    explicit Rejestracja(QWidget *parent = nullptr);
    ~Rejestracja();

private slots:
    void on_zarejestrujButton_clicked();

private:
    Ui::Rejestracja *ui;
};

#endif // REJESTRACJA_H
