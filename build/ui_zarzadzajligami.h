/********************************************************************************
** Form generated from reading UI file 'zarzadzajligami.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZARZADZAJLIGAMI_H
#define UI_ZARZADZAJLIGAMI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ZarzadzajLigami
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ZarzadzajLigami)
    {
        if (ZarzadzajLigami->objectName().isEmpty())
            ZarzadzajLigami->setObjectName("ZarzadzajLigami");
        ZarzadzajLigami->resize(746, 591);
        ZarzadzajLigami->setModal(true);
        verticalLayout_2 = new QVBoxLayout(ZarzadzajLigami);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        listView = new QListView(ZarzadzajLigami);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);

        pushButton = new QPushButton(ZarzadzajLigami);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(ZarzadzajLigami);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ZarzadzajLigami);

        QMetaObject::connectSlotsByName(ZarzadzajLigami);
    } // setupUi

    void retranslateUi(QDialog *ZarzadzajLigami)
    {
        ZarzadzajLigami->setWindowTitle(QCoreApplication::translate("ZarzadzajLigami", "Wybierz Lige", nullptr));
        pushButton->setText(QCoreApplication::translate("ZarzadzajLigami", "Wybierz", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ZarzadzajLigami", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZarzadzajLigami: public Ui_ZarzadzajLigami {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZARZADZAJLIGAMI_H
