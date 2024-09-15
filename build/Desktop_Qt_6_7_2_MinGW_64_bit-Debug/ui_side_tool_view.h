/********************************************************************************
** Form generated from reading UI file 'side_tool_view.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDE_TOOL_VIEW_H
#define UI_SIDE_TOOL_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideToolView
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_2;
    QLabel *label;
    QSpinBox *spinBox_4;
    QLabel *label_4;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QComboBox *comboBox_4;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *SideToolView)
    {
        if (SideToolView->objectName().isEmpty())
            SideToolView->setObjectName("SideToolView");
        SideToolView->resize(402, 974);
        horizontalLayout = new QHBoxLayout(SideToolView);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(SideToolView);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(12);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        comboBox = new QComboBox(groupBox_4);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setFont(font);

        verticalLayout_3->addWidget(comboBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        checkBox = new QCheckBox(groupBox_4);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font);

        horizontalLayout_6->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);

        horizontalLayout_7->addWidget(label_5);

        lineEdit_4 = new QLineEdit(groupBox_4);
        lineEdit_4->setObjectName("lineEdit_4");
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);
        lineEdit_4->setFont(font);

        horizontalLayout_7->addWidget(lineEdit_4);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label = new QLabel(groupBox_3);
        label->setObjectName("label");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        spinBox_4 = new QSpinBox(groupBox_3);
        spinBox_4->setObjectName("spinBox_4");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_4);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        spinBox_3 = new QSpinBox(groupBox_3);
        spinBox_3->setObjectName("spinBox_3");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBox_3);


        verticalLayout_4->addLayout(formLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_3);

        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName("textEdit");
        textEdit->setReadOnly(true);

        verticalLayout_4->addWidget(textEdit);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName("lineEdit");
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setFont(font);
        lineEdit->setDragEnabled(false);
        lineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName("comboBox_4");
        sizePolicy.setHeightForWidth(comboBox_4->sizePolicy().hasHeightForWidth());
        comboBox_4->setSizePolicy(sizePolicy);
        comboBox_4->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_4);

        doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox->setObjectName("doubleSpinBox");
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox);

        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName("spinBox_2");
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);
        spinBox_2->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox_2);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName("spinBox");
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox);


        verticalLayout_2->addLayout(formLayout);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName("pushButton_4");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setFont(font);

        verticalLayout_2->addWidget(pushButton_4);


        verticalLayout->addWidget(groupBox_2);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setFont(font);

        verticalLayout->addWidget(pushButton_5);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(SideToolView);

        QMetaObject::connectSlotsByName(SideToolView);
    } // setupUi

    void retranslateUi(QWidget *SideToolView)
    {
        SideToolView->setWindowTitle(QCoreApplication::translate("SideToolView", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SideToolView", "\347\272\277\350\267\257\346\237\245\350\257\242", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("SideToolView", "\347\272\277\350\267\257", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SideToolView", "\346\234\252\351\200\211\346\213\251", nullptr));

        checkBox->setText(QCoreApplication::translate("SideToolView", "\347\216\257\347\272\277", nullptr));
        label_5->setText(QCoreApplication::translate("SideToolView", "\347\272\277\350\267\257\345\220\215\347\247\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SideToolView", "\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("SideToolView", "\350\265\267\347\202\271\347\274\226\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("SideToolView", "\347\273\210\347\202\271\347\274\226\345\217\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SideToolView", "\346\234\200\347\237\255\350\267\235\347\246\273\350\267\257", nullptr));
        pushButton->setText(QCoreApplication::translate("SideToolView", "\346\234\200\345\260\221\346\215\242\344\271\230\350\267\257", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SideToolView", "\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("SideToolView", "\347\274\226\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("SideToolView", "\350\276\271\351\225\277", nullptr));
        label_7->setText(QCoreApplication::translate("SideToolView", "\350\276\271\345\275\242", nullptr));
        label_6->setText(QCoreApplication::translate("SideToolView", "\350\265\267\347\202\271", nullptr));
        label_8->setText(QCoreApplication::translate("SideToolView", "\347\273\210\347\202\271", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SideToolView", "\345\210\240\351\231\244", nullptr));
        pushButton_5->setText(QCoreApplication::translate("SideToolView", "\346\217\220\347\244\272\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideToolView: public Ui_SideToolView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDE_TOOL_VIEW_H
