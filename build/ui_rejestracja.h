/********************************************************************************
** Form generated from reading UI file 'rejestracja.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REJESTRACJA_H
#define UI_REJESTRACJA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Rejestracja
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QLineEdit *loginText;
    QLineEdit *hasloText;
    QLineEdit *powtorzhasloText;
    QLineEdit *emailText;
    QLineEdit *imieText;
    QLineEdit *nazwiskoText;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *Rejestracja)
    {
        if (Rejestracja->objectName().isEmpty())
            Rejestracja->setObjectName("Rejestracja");
        Rejestracja->resize(361, 250);
        Rejestracja->setModal(true);
        verticalLayout_4 = new QVBoxLayout(Rejestracja);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(Rejestracja);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(Rejestracja);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(Rejestracja);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(Rejestracja);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(Rejestracja);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(Rejestracja);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(Rejestracja);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        loginText = new QLineEdit(Rejestracja);
        loginText->setObjectName("loginText");

        verticalLayout->addWidget(loginText);

        hasloText = new QLineEdit(Rejestracja);
        hasloText->setObjectName("hasloText");
        hasloText->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(hasloText);

        powtorzhasloText = new QLineEdit(Rejestracja);
        powtorzhasloText->setObjectName("powtorzhasloText");
        powtorzhasloText->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(powtorzhasloText);

        emailText = new QLineEdit(Rejestracja);
        emailText->setObjectName("emailText");

        verticalLayout->addWidget(emailText);

        imieText = new QLineEdit(Rejestracja);
        imieText->setObjectName("imieText");

        verticalLayout->addWidget(imieText);

        nazwiskoText = new QLineEdit(Rejestracja);
        nazwiskoText->setObjectName("nazwiskoText");

        verticalLayout->addWidget(nazwiskoText);

        comboBox = new QComboBox(Rejestracja);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton = new QPushButton(Rejestracja);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Rejestracja);

        QMetaObject::connectSlotsByName(Rejestracja);
    } // setupUi

    void retranslateUi(QDialog *Rejestracja)
    {
        Rejestracja->setWindowTitle(QCoreApplication::translate("Rejestracja", "Ekran rejestracji", nullptr));
        label->setText(QCoreApplication::translate("Rejestracja", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("Rejestracja", "Has\305\202o", nullptr));
        label_3->setText(QCoreApplication::translate("Rejestracja", "Powt\303\263rz has\305\202o", nullptr));
        label_4->setText(QCoreApplication::translate("Rejestracja", "Adres e-mail", nullptr));
        label_5->setText(QCoreApplication::translate("Rejestracja", "Imi\304\231", nullptr));
        label_6->setText(QCoreApplication::translate("Rejestracja", "Nazwisko", nullptr));
        label_7->setText(QCoreApplication::translate("Rejestracja", "Uprawnienia", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Rejestracja", "opiekun", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Rejestracja", "gracz", nullptr));

        pushButton->setText(QCoreApplication::translate("Rejestracja", "Zarejestruj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rejestracja: public Ui_Rejestracja {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REJESTRACJA_H
