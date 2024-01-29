/********************************************************************************
** Form generated from reading UI file 'ogloszenia.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OGLOSZENIA_H
#define UI_OGLOSZENIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Ogloszenia
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Ogloszenia)
    {
        if (Ogloszenia->objectName().isEmpty())
            Ogloszenia->setObjectName("Ogloszenia");
        Ogloszenia->resize(714, 588);
        Ogloszenia->setModal(true);
        verticalLayout_2 = new QVBoxLayout(Ogloszenia);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        listView = new QListView(Ogloszenia);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(Ogloszenia);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Ogloszenia);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_3 = new QPushButton(Ogloszenia);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(Ogloszenia);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Ogloszenia);

        QMetaObject::connectSlotsByName(Ogloszenia);
    } // setupUi

    void retranslateUi(QDialog *Ogloszenia)
    {
        Ogloszenia->setWindowTitle(QCoreApplication::translate("Ogloszenia", "Ogloszenia", nullptr));
        pushButton->setText(QCoreApplication::translate("Ogloszenia", "Edytuj", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Ogloszenia", "Usu\305\204", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Ogloszenia", "Dodaj nowe og\305\202oszenie", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Ogloszenia", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ogloszenia: public Ui_Ogloszenia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OGLOSZENIA_H
