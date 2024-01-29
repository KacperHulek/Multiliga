#ifndef EDYTUJGRACZAWLIDZE_H
#define EDYTUJGRACZAWLIDZE_H

#include <QDialog>
#include "databasemanager.h"
#include "edytujlige.h"

namespace Ui {
class EdytujGraczaWLidze;
}

class EdytujGraczaWLidze : public QDialog
{
    Q_OBJECT

public:
    explicit EdytujGraczaWLidze(QWidget *parent = nullptr,
                                DatabaseManager *dbManager = nullptr, EdytujLige *el = nullptr);
    ~EdytujGraczaWLidze();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::EdytujGraczaWLidze *ui;
    DatabaseManager *dbManager;
    EdytujLige *el;
};

#endif // EDYTUJGRACZAWLIDZE_H
