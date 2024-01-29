/********************************************************************************
** Form generated from reading UI file 'dodajgracza.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJGRACZA_H
#define UI_DODAJGRACZA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DodajGracza
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DodajGracza)
    {
        if (DodajGracza->objectName().isEmpty())
            DodajGracza->setObjectName("DodajGracza");
        DodajGracza->resize(685, 591);
        DodajGracza->setModal(true);
        verticalLayout_2 = new QVBoxLayout(DodajGracza);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(DodajGracza);
        tableView->setObjectName("tableView");
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(DodajGracza);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(DodajGracza);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DodajGracza);

        QMetaObject::connectSlotsByName(DodajGracza);
    } // setupUi

    void retranslateUi(QDialog *DodajGracza)
    {
        DodajGracza->setWindowTitle(QCoreApplication::translate("DodajGracza", "Dodawanie graczy", nullptr));
        pushButton->setText(QCoreApplication::translate("DodajGracza", "Zatwierd\305\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DodajGracza", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DodajGracza: public Ui_DodajGracza {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJGRACZA_H
