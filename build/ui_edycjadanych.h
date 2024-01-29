/********************************************************************************
** Form generated from reading UI file 'edycjadanych.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDYCJADANYCH_H
#define UI_EDYCJADANYCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EdycjaDanych
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *EdycjaDanych)
    {
        if (EdycjaDanych->objectName().isEmpty())
            EdycjaDanych->setObjectName("EdycjaDanych");
        EdycjaDanych->resize(200, 168);
        EdycjaDanych->setModal(true);
        verticalLayout_2 = new QVBoxLayout(EdycjaDanych);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(EdycjaDanych);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(EdycjaDanych);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(EdycjaDanych);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(EdycjaDanych);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EdycjaDanych);

        QMetaObject::connectSlotsByName(EdycjaDanych);
    } // setupUi

    void retranslateUi(QDialog *EdycjaDanych)
    {
        EdycjaDanych->setWindowTitle(QCoreApplication::translate("EdycjaDanych", "Edytuj swoje dane", nullptr));
        pushButton->setText(QCoreApplication::translate("EdycjaDanych", "Zmie\305\204 login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EdycjaDanych", "Zmie\305\204 has\305\202o", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EdycjaDanych", "Usu\305\204 konto", nullptr));
        pushButton_4->setText(QCoreApplication::translate("EdycjaDanych", "Zamknij", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdycjaDanych: public Ui_EdycjaDanych {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDYCJADANYCH_H
