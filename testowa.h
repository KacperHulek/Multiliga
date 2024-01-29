#ifndef TESTOWA_H
#define TESTOWA_H

#include <QDialog>

namespace Ui {
class Testowa;
}

class Testowa : public QDialog
{
    Q_OBJECT

public:
    explicit Testowa(QWidget *parent = nullptr);
    ~Testowa();

private:
    Ui::Testowa *ui;
};

#endif // TESTOWA_H
