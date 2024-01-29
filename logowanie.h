#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QDialog>

namespace Ui {
class EkranLogowania;
}

class EkranLogowania : public QDialog
{
    Q_OBJECT

public:
    explicit EkranLogowania(QWidget *parent = nullptr);
    ~EkranLogowania();

private:
    Ui::EkranLogowania *ui;
};

#endif // LOGOWANIE_H
