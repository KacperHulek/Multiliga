/********************************************************************************
** Form generated from reading UI file 'edytujgraczawlidze.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDYTUJGRACZAWLIDZE_H
#define UI_EDYTUJGRACZAWLIDZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EdytujGraczaWLidze
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *EdytujGraczaWLidze)
    {
        if (EdytujGraczaWLidze->objectName().isEmpty())
            EdytujGraczaWLidze->setObjectName("EdytujGraczaWLidze");
        EdytujGraczaWLidze->resize(288, 191);
        EdytujGraczaWLidze->setModal(true);
        verticalLayout_2 = new QVBoxLayout(EdytujGraczaWLidze);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(EdytujGraczaWLidze);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(EdytujGraczaWLidze);
        spinBox->setObjectName("spinBox");
        spinBox->setReadOnly(false);
        spinBox->setMinimum(1);
        spinBox->setMaximum(3);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(EdytujGraczaWLidze);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(EdytujGraczaWLidze);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(EdytujGraczaWLidze);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(EdytujGraczaWLidze);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(EdytujGraczaWLidze);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(EdytujGraczaWLidze);

        QMetaObject::connectSlotsByName(EdytujGraczaWLidze);
    } // setupUi

    void retranslateUi(QDialog *EdytujGraczaWLidze)
    {
        EdytujGraczaWLidze->setWindowTitle(QCoreApplication::translate("EdytujGraczaWLidze", "Edytowanie informacji gracza", nullptr));
        label->setText(QCoreApplication::translate("EdytujGraczaWLidze", "Poziom", nullptr));
        label_2->setText(QCoreApplication::translate("EdytujGraczaWLidze", "Czy op\305\202acono?", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("EdytujGraczaWLidze", "Nie", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("EdytujGraczaWLidze", "Tak", nullptr));

        pushButton->setText(QCoreApplication::translate("EdytujGraczaWLidze", "Zatwierd\305\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EdytujGraczaWLidze", "Usu\305\204 gracza", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EdytujGraczaWLidze", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdytujGraczaWLidze: public Ui_EdytujGraczaWLidze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDYTUJGRACZAWLIDZE_H
