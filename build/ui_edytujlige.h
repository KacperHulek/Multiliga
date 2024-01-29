/********************************************************************************
** Form generated from reading UI file 'edytujlige.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDYTUJLIGE_H
#define UI_EDYTUJLIGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EdytujLige
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;

    void setupUi(QDialog *EdytujLige)
    {
        if (EdytujLige->objectName().isEmpty())
            EdytujLige->setObjectName("EdytujLige");
        EdytujLige->resize(762, 654);
        EdytujLige->setModal(true);
        verticalLayout_3 = new QVBoxLayout(EdytujLige);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(EdytujLige);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(EdytujLige);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout->addWidget(dateTimeEdit);

        pushButton_3 = new QPushButton(EdytujLige);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        tableView = new QTableView(EdytujLige);
        tableView->setObjectName("tableView");
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->setGridStyle(Qt::NoPen);
        tableView->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(EdytujLige);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(EdytujLige);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(EdytujLige);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(EdytujLige);

        QMetaObject::connectSlotsByName(EdytujLige);
    } // setupUi

    void retranslateUi(QDialog *EdytujLige)
    {
        EdytujLige->setWindowTitle(QCoreApplication::translate("EdytujLige", "Zarzadzanie liga", nullptr));
        label->setText(QCoreApplication::translate("EdytujLige", "Data nast\304\231pnej kolejki", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EdytujLige", "Zmie\305\204", nullptr));
        pushButton->setText(QCoreApplication::translate("EdytujLige", "Edytuj gracza", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EdytujLige", "Dodaj gracza", nullptr));
        pushButton_4->setText(QCoreApplication::translate("EdytujLige", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdytujLige: public Ui_EdytujLige {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDYTUJLIGE_H
