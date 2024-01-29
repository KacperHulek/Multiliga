/********************************************************************************
** Form generated from reading UI file 'spotkania.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPOTKANIA_H
#define UI_SPOTKANIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Spotkania
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QDialog *Spotkania)
    {
        if (Spotkania->objectName().isEmpty())
            Spotkania->setObjectName("Spotkania");
        Spotkania->resize(800, 600);
        Spotkania->setModal(true);
        verticalLayout = new QVBoxLayout(Spotkania);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(Spotkania);
        tableView->setObjectName("tableView");
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);


        retranslateUi(Spotkania);

        QMetaObject::connectSlotsByName(Spotkania);
    } // setupUi

    void retranslateUi(QDialog *Spotkania)
    {
        Spotkania->setWindowTitle(QCoreApplication::translate("Spotkania", "Harmonogram spotkan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spotkania: public Ui_Spotkania {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOTKANIA_H
