/********************************************************************************
** Form generated from reading UI file 'zmianaloginu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZMIANALOGINU_H
#define UI_ZMIANALOGINU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ZmianaLoginu
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *nowyLoginText;
    QLineEdit *hasloText;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ZmianaLoginu)
    {
        if (ZmianaLoginu->objectName().isEmpty())
            ZmianaLoginu->setObjectName("ZmianaLoginu");
        ZmianaLoginu->resize(311, 110);
        ZmianaLoginu->setModal(true);
        verticalLayout_4 = new QVBoxLayout(ZmianaLoginu);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(ZmianaLoginu);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(ZmianaLoginu);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        nowyLoginText = new QLineEdit(ZmianaLoginu);
        nowyLoginText->setObjectName("nowyLoginText");

        verticalLayout->addWidget(nowyLoginText);

        hasloText = new QLineEdit(ZmianaLoginu);
        hasloText->setObjectName("hasloText");
        hasloText->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(hasloText);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(ZmianaLoginu);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(ZmianaLoginu);

        QMetaObject::connectSlotsByName(ZmianaLoginu);
    } // setupUi

    void retranslateUi(QDialog *ZmianaLoginu)
    {
        ZmianaLoginu->setWindowTitle(QCoreApplication::translate("ZmianaLoginu", "Ekran zmiany loginu", nullptr));
        label->setText(QCoreApplication::translate("ZmianaLoginu", "Nowy login", nullptr));
        label_2->setText(QCoreApplication::translate("ZmianaLoginu", "Has\305\202o", nullptr));
        pushButton->setText(QCoreApplication::translate("ZmianaLoginu", "Zmie\305\204 login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZmianaLoginu: public Ui_ZmianaLoginu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZMIANALOGINU_H
