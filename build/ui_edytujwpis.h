/********************************************************************************
** Form generated from reading UI file 'edytujwpis.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDYTUJWPIS_H
#define UI_EDYTUJWPIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EdytujWpis
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *EdytujWpis)
    {
        if (EdytujWpis->objectName().isEmpty())
            EdytujWpis->setObjectName("EdytujWpis");
        EdytujWpis->resize(754, 635);
        EdytujWpis->setModal(true);
        verticalLayout_2 = new QVBoxLayout(EdytujWpis);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        plainTextEdit = new QPlainTextEdit(EdytujWpis);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(EdytujWpis);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(EdytujWpis);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EdytujWpis);

        QMetaObject::connectSlotsByName(EdytujWpis);
    } // setupUi

    void retranslateUi(QDialog *EdytujWpis)
    {
        EdytujWpis->setWindowTitle(QCoreApplication::translate("EdytujWpis", "Edytuj wpis", nullptr));
        pushButton->setText(QCoreApplication::translate("EdytujWpis", "Zatwierd\305\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EdytujWpis", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdytujWpis: public Ui_EdytujWpis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDYTUJWPIS_H
