/********************************************************************************
** Form generated from reading UI file 'aktualizujwyniki.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AKTUALIZUJWYNIKI_H
#define UI_AKTUALIZUJWYNIKI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AktualizujWyniki
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView;
    QListView *listView_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *AktualizujWyniki)
    {
        if (AktualizujWyniki->objectName().isEmpty())
            AktualizujWyniki->setObjectName("AktualizujWyniki");
        AktualizujWyniki->resize(520, 388);
        AktualizujWyniki->setModal(true);
        verticalLayout_2 = new QVBoxLayout(AktualizujWyniki);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AktualizujWyniki);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        listView = new QListView(AktualizujWyniki);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);

        listView_2 = new QListView(AktualizujWyniki);
        listView_2->setObjectName("listView_2");

        verticalLayout->addWidget(listView_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_2 = new QPushButton(AktualizujWyniki);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(AktualizujWyniki);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AktualizujWyniki);

        QMetaObject::connectSlotsByName(AktualizujWyniki);
    } // setupUi

    void retranslateUi(QDialog *AktualizujWyniki)
    {
        AktualizujWyniki->setWindowTitle(QCoreApplication::translate("AktualizujWyniki", "Aktualizacja wynikow", nullptr));
        label->setText(QCoreApplication::translate("AktualizujWyniki", "Wybierz lig\304\231 a nast\304\231pnie kolejk\304\231", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AktualizujWyniki", "Dalej", nullptr));
        pushButton->setText(QCoreApplication::translate("AktualizujWyniki", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AktualizujWyniki: public Ui_AktualizujWyniki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AKTUALIZUJWYNIKI_H
