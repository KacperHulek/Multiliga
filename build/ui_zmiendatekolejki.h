/********************************************************************************
** Form generated from reading UI file 'zmiendatekolejki.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZMIENDATEKOLEJKI_H
#define UI_ZMIENDATEKOLEJKI_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ZmienDateKolejki
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ZmienDateKolejki)
    {
        if (ZmienDateKolejki->objectName().isEmpty())
            ZmienDateKolejki->setObjectName("ZmienDateKolejki");
        ZmienDateKolejki->resize(281, 183);
        ZmienDateKolejki->setModal(true);
        verticalLayout_3 = new QVBoxLayout(ZmienDateKolejki);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ZmienDateKolejki);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(ZmienDateKolejki);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateTimeEdit->setDate(QDate(2003, 1, 5));
        dateTimeEdit->setCalendarPopup(false);

        verticalLayout->addWidget(dateTimeEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(ZmienDateKolejki);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(ZmienDateKolejki);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ZmienDateKolejki);

        QMetaObject::connectSlotsByName(ZmienDateKolejki);
    } // setupUi

    void retranslateUi(QDialog *ZmienDateKolejki)
    {
        ZmienDateKolejki->setWindowTitle(QCoreApplication::translate("ZmienDateKolejki", "Zmien date kolejki", nullptr));
        label->setText(QCoreApplication::translate("ZmienDateKolejki", "Podaj now\304\205 dat\304\231 kolejki", nullptr));
        pushButton->setText(QCoreApplication::translate("ZmienDateKolejki", "Zatwierd\305\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ZmienDateKolejki", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZmienDateKolejki: public Ui_ZmienDateKolejki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZMIENDATEKOLEJKI_H
