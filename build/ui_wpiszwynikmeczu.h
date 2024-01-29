/********************************************************************************
** Form generated from reading UI file 'wpiszwynikmeczu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WPISZWYNIKMECZU_H
#define UI_WPISZWYNIKMECZU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WpiszWynikMeczu
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBoxA;
    QLabel *label_2;
    QSpinBox *spinBoxB;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *WpiszWynikMeczu)
    {
        if (WpiszWynikMeczu->objectName().isEmpty())
            WpiszWynikMeczu->setObjectName("WpiszWynikMeczu");
        WpiszWynikMeczu->resize(783, 540);
        WpiszWynikMeczu->setModal(true);
        verticalLayout_2 = new QVBoxLayout(WpiszWynikMeczu);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(WpiszWynikMeczu);
        tableView->setObjectName("tableView");
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(WpiszWynikMeczu);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        spinBoxA = new QSpinBox(WpiszWynikMeczu);
        spinBoxA->setObjectName("spinBoxA");
        spinBoxA->setMaximum(3);

        horizontalLayout_2->addWidget(spinBoxA);

        label_2 = new QLabel(WpiszWynikMeczu);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        spinBoxB = new QSpinBox(WpiszWynikMeczu);
        spinBoxB->setObjectName("spinBoxB");
        spinBoxB->setMaximum(3);

        horizontalLayout_2->addWidget(spinBoxB);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(WpiszWynikMeczu);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(WpiszWynikMeczu);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(WpiszWynikMeczu);

        QMetaObject::connectSlotsByName(WpiszWynikMeczu);
    } // setupUi

    void retranslateUi(QDialog *WpiszWynikMeczu)
    {
        WpiszWynikMeczu->setWindowTitle(QCoreApplication::translate("WpiszWynikMeczu", "Edytuj wynik mecz\303\263w", nullptr));
        label->setText(QCoreApplication::translate("WpiszWynikMeczu", "Gracz A", nullptr));
        label_2->setText(QCoreApplication::translate("WpiszWynikMeczu", "Gracz B", nullptr));
        pushButton->setText(QCoreApplication::translate("WpiszWynikMeczu", "Wpisz wynik", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WpiszWynikMeczu", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WpiszWynikMeczu: public Ui_WpiszWynikMeczu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WPISZWYNIKMECZU_H
