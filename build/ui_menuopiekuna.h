/********************************************************************************
** Form generated from reading UI file 'menuopiekuna.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUOPIEKUNA_H
#define UI_MENUOPIEKUNA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuOpiekuna
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *harmonogramButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *rankingButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *tablicaButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *analizujButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *zarzadzajButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *wylogujButton;
    QPushButton *edytujButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MenuOpiekuna)
    {
        if (MenuOpiekuna->objectName().isEmpty())
            MenuOpiekuna->setObjectName("MenuOpiekuna");
        MenuOpiekuna->resize(800, 200);
        verticalLayout_4 = new QVBoxLayout(MenuOpiekuna);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        harmonogramButton = new QPushButton(MenuOpiekuna);
        harmonogramButton->setObjectName("harmonogramButton");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(harmonogramButton->sizePolicy().hasHeightForWidth());
        harmonogramButton->setSizePolicy(sizePolicy);
        harmonogramButton->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(harmonogramButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        rankingButton = new QPushButton(MenuOpiekuna);
        rankingButton->setObjectName("rankingButton");
        rankingButton->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(rankingButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        tablicaButton = new QPushButton(MenuOpiekuna);
        tablicaButton->setObjectName("tablicaButton");
        tablicaButton->setMinimumSize(QSize(0, 50));

        horizontalLayout->addWidget(tablicaButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        analizujButton = new QPushButton(MenuOpiekuna);
        analizujButton->setObjectName("analizujButton");
        analizujButton->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(analizujButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        zarzadzajButton = new QPushButton(MenuOpiekuna);
        zarzadzajButton->setObjectName("zarzadzajButton");
        zarzadzajButton->setMinimumSize(QSize(0, 50));

        horizontalLayout_2->addWidget(zarzadzajButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        wylogujButton = new QPushButton(MenuOpiekuna);
        wylogujButton->setObjectName("wylogujButton");
        wylogujButton->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(wylogujButton);

        edytujButton = new QPushButton(MenuOpiekuna);
        edytujButton->setObjectName("edytujButton");
        edytujButton->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(edytujButton);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(MenuOpiekuna);

        QMetaObject::connectSlotsByName(MenuOpiekuna);
    } // setupUi

    void retranslateUi(QWidget *MenuOpiekuna)
    {
        MenuOpiekuna->setWindowTitle(QCoreApplication::translate("MenuOpiekuna", "Menu", nullptr));
        harmonogramButton->setText(QCoreApplication::translate("MenuOpiekuna", "Harmonogram spotka\305\204", nullptr));
        rankingButton->setText(QCoreApplication::translate("MenuOpiekuna", "Ranking", nullptr));
        tablicaButton->setText(QCoreApplication::translate("MenuOpiekuna", "Tablica og\305\202osze\305\204", nullptr));
        analizujButton->setText(QCoreApplication::translate("MenuOpiekuna", "Aktualizuj wyniki", nullptr));
        zarzadzajButton->setText(QCoreApplication::translate("MenuOpiekuna", "Zarz\304\205dzaj ligami", nullptr));
        wylogujButton->setText(QCoreApplication::translate("MenuOpiekuna", "Wyloguj", nullptr));
        edytujButton->setText(QCoreApplication::translate("MenuOpiekuna", "Edytuj moje dane", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuOpiekuna: public Ui_MenuOpiekuna {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUOPIEKUNA_H
