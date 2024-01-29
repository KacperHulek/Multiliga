/********************************************************************************
** Form generated from reading UI file 'zmianahasla.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZMIANAHASLA_H
#define UI_ZMIANAHASLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ZmianaHasla
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *stareHasloText;
    QLineEdit *noweHasloText;
    QLineEdit *powtorzHasloText;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ZmianaHasla)
    {
        if (ZmianaHasla->objectName().isEmpty())
            ZmianaHasla->setObjectName("ZmianaHasla");
        ZmianaHasla->resize(298, 157);
        ZmianaHasla->setModal(true);
        verticalLayout_4 = new QVBoxLayout(ZmianaHasla);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(ZmianaHasla);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(ZmianaHasla);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(ZmianaHasla);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        stareHasloText = new QLineEdit(ZmianaHasla);
        stareHasloText->setObjectName("stareHasloText");
        stareHasloText->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(stareHasloText);

        noweHasloText = new QLineEdit(ZmianaHasla);
        noweHasloText->setObjectName("noweHasloText");
        noweHasloText->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(noweHasloText);

        powtorzHasloText = new QLineEdit(ZmianaHasla);
        powtorzHasloText->setObjectName("powtorzHasloText");
        powtorzHasloText->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(powtorzHasloText);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(ZmianaHasla);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(ZmianaHasla);

        QMetaObject::connectSlotsByName(ZmianaHasla);
    } // setupUi

    void retranslateUi(QDialog *ZmianaHasla)
    {
        ZmianaHasla->setWindowTitle(QCoreApplication::translate("ZmianaHasla", "Ekran zmiany hasla", nullptr));
        label->setText(QCoreApplication::translate("ZmianaHasla", "Stare has\305\202o", nullptr));
        label_2->setText(QCoreApplication::translate("ZmianaHasla", "Nowe has\305\202o", nullptr));
        label_3->setText(QCoreApplication::translate("ZmianaHasla", "Powt\303\263rz has\305\202o", nullptr));
        pushButton->setText(QCoreApplication::translate("ZmianaHasla", "Zmie\305\204 has\305\202o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZmianaHasla: public Ui_ZmianaHasla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZMIANAHASLA_H
