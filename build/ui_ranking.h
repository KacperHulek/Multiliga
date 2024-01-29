/********************************************************************************
** Form generated from reading UI file 'ranking.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKING_H
#define UI_RANKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Ranking
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView;
    QTableView *tableView;

    void setupUi(QDialog *Ranking)
    {
        if (Ranking->objectName().isEmpty())
            Ranking->setObjectName("Ranking");
        Ranking->resize(946, 624);
        Ranking->setModal(true);
        verticalLayout = new QVBoxLayout(Ranking);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Ranking);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        listView = new QListView(Ranking);
        listView->setObjectName("listView");
        listView->setMaximumSize(QSize(16777215, 150));

        verticalLayout->addWidget(listView);

        tableView = new QTableView(Ranking);
        tableView->setObjectName("tableView");
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);


        retranslateUi(Ranking);

        QMetaObject::connectSlotsByName(Ranking);
    } // setupUi

    void retranslateUi(QDialog *Ranking)
    {
        Ranking->setWindowTitle(QCoreApplication::translate("Ranking", "Ranking", nullptr));
        label->setText(QCoreApplication::translate("Ranking", "Wybierz Lig\304\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ranking: public Ui_Ranking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKING_H
