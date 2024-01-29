#ifndef ASDFAAA_H
#define ASDFAAA_H

#include <QDialog>

namespace Ui {
class asdfaaa;
}

class asdfaaa : public QDialog
{
    Q_OBJECT

public:
    explicit asdfaaa(QWidget *parent = nullptr);
    ~asdfaaa();

private:
    Ui::asdfaaa *ui;
};

#endif // ASDFAAA_H
