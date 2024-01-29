/********************************************************************************
** Form generated from reading UI file 'dodajogloszenie.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJOGLOSZENIE_H
#define UI_DODAJOGLOSZENIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DodajOgloszenie
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *DodajOgloszenie)
    {
        if (DodajOgloszenie->objectName().isEmpty())
            DodajOgloszenie->setObjectName("DodajOgloszenie");
        DodajOgloszenie->resize(669, 597);
        DodajOgloszenie->setModal(true);
        verticalLayout_2 = new QVBoxLayout(DodajOgloszenie);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        plainTextEdit = new QPlainTextEdit(DodajOgloszenie);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(DodajOgloszenie);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(DodajOgloszenie);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DodajOgloszenie);

        QMetaObject::connectSlotsByName(DodajOgloszenie);
    } // setupUi

    void retranslateUi(QDialog *DodajOgloszenie)
    {
        DodajOgloszenie->setWindowTitle(QCoreApplication::translate("DodajOgloszenie", "Dodaj ogloszenie", nullptr));
        pushButton->setText(QCoreApplication::translate("DodajOgloszenie", "Dodaj og\305\202oszenie", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DodajOgloszenie", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DodajOgloszenie: public Ui_DodajOgloszenie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJOGLOSZENIE_H
