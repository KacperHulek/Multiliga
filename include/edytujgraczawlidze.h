#ifndef EDYTUJGRACZAWLIDZE_H
#define EDYTUJGRACZAWLIDZE_H

#include <QtSql>
#include <QDialog>
#include "edytujlige.h"

namespace Ui {
class EdytujGraczaWLidze;
}

class EdytujGraczaWLidze : public QDialog
{
    Q_OBJECT

public:
    explicit EdytujGraczaWLidze(QWidget *parent = nullptr, EdytujLige *el = nullptr);
    ~EdytujGraczaWLidze();

private slots:
    void on_zatwierdzButton_clicked();

    void on_usunGraczaButton_clicked();

    void on_powrotButton_clicked();

private:
    Ui::EdytujGraczaWLidze *ui;
    EdytujLige *el;
};

#endif // EDYTUJGRACZAWLIDZE_H
