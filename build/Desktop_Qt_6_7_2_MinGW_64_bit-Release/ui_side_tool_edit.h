/********************************************************************************
** Form generated from reading UI file 'side_tool_edit.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDE_TOOL_EDIT_H
#define UI_SIDE_TOOL_EDIT_H

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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideToolEdit
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *lineGroup;
    QVBoxLayout *verticalLayout_3;
    QComboBox *lineBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addLineButton;
    QPushButton *deleteLineButton;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *circleCheck;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *nameEdit;
    QGroupBox *addEdgeGroup;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addEdgeButton;
    QComboBox *styleBox;
    QComboBox *directBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QDoubleSpinBox *lengthSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *vexBox;
    QGroupBox *useBox;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QSpinBox *useStartBox;
    QLabel *label_4;
    QSpinBox *useEndBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *lowDistanceButton;
    QPushButton *lowChangeButton;
    QTextEdit *wayTextEdit;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QPushButton *tipsButton;

    void setupUi(QWidget *SideToolEdit)
    {
        if (SideToolEdit->objectName().isEmpty())
            SideToolEdit->setObjectName("SideToolEdit");
        SideToolEdit->resize(334, 733);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideToolEdit->sizePolicy().hasHeightForWidth());
        SideToolEdit->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SideToolEdit);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(SideToolEdit);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 300, 733));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        groupBox = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName("verticalLayout_6");
        lineGroup = new QGroupBox(groupBox);
        lineGroup->setObjectName("lineGroup");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineGroup->sizePolicy().hasHeightForWidth());
        lineGroup->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(lineGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lineBox = new QComboBox(lineGroup);
        lineBox->setObjectName("lineBox");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineBox->sizePolicy().hasHeightForWidth());
        lineBox->setSizePolicy(sizePolicy3);
        lineBox->setFont(font);

        verticalLayout_3->addWidget(lineBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        addLineButton = new QPushButton(lineGroup);
        addLineButton->setObjectName("addLineButton");
        sizePolicy3.setHeightForWidth(addLineButton->sizePolicy().hasHeightForWidth());
        addLineButton->setSizePolicy(sizePolicy3);
        addLineButton->setFont(font);

        horizontalLayout_4->addWidget(addLineButton);

        deleteLineButton = new QPushButton(lineGroup);
        deleteLineButton->setObjectName("deleteLineButton");
        sizePolicy3.setHeightForWidth(deleteLineButton->sizePolicy().hasHeightForWidth());
        deleteLineButton->setSizePolicy(sizePolicy3);
        deleteLineButton->setFont(font);

        horizontalLayout_4->addWidget(deleteLineButton);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        circleCheck = new QCheckBox(lineGroup);
        circleCheck->setObjectName("circleCheck");
        circleCheck->setFont(font);

        horizontalLayout_6->addWidget(circleCheck);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_5 = new QLabel(lineGroup);
        label_5->setObjectName("label_5");
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setFont(font);

        horizontalLayout_7->addWidget(label_5);

        nameEdit = new QLineEdit(lineGroup);
        nameEdit->setObjectName("nameEdit");
        sizePolicy3.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy3);
        nameEdit->setFont(font);

        horizontalLayout_7->addWidget(nameEdit);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_6->addWidget(lineGroup);

        addEdgeGroup = new QGroupBox(groupBox);
        addEdgeGroup->setObjectName("addEdgeGroup");
        addEdgeGroup->setEnabled(true);
        sizePolicy2.setHeightForWidth(addEdgeGroup->sizePolicy().hasHeightForWidth());
        addEdgeGroup->setSizePolicy(sizePolicy2);
        verticalLayout_4 = new QVBoxLayout(addEdgeGroup);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addEdgeButton = new QPushButton(addEdgeGroup);
        addEdgeButton->setObjectName("addEdgeButton");
        sizePolicy3.setHeightForWidth(addEdgeButton->sizePolicy().hasHeightForWidth());
        addEdgeButton->setSizePolicy(sizePolicy3);
        addEdgeButton->setFont(font);

        horizontalLayout_3->addWidget(addEdgeButton);

        styleBox = new QComboBox(addEdgeGroup);
        styleBox->addItem(QString());
        styleBox->addItem(QString());
        styleBox->addItem(QString());
        styleBox->setObjectName("styleBox");
        sizePolicy3.setHeightForWidth(styleBox->sizePolicy().hasHeightForWidth());
        styleBox->setSizePolicy(sizePolicy3);
        styleBox->setFont(font);

        horizontalLayout_3->addWidget(styleBox);

        directBox = new QComboBox(addEdgeGroup);
        directBox->addItem(QString());
        directBox->addItem(QString());
        directBox->setObjectName("directBox");
        sizePolicy3.setHeightForWidth(directBox->sizePolicy().hasHeightForWidth());
        directBox->setSizePolicy(sizePolicy3);
        directBox->setFont(font);

        horizontalLayout_3->addWidget(directBox);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_13 = new QLabel(addEdgeGroup);
        label_13->setObjectName("label_13");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy4);
        label_13->setFont(font);

        horizontalLayout_8->addWidget(label_13);

        lengthSpinBox = new QDoubleSpinBox(addEdgeGroup);
        lengthSpinBox->setObjectName("lengthSpinBox");
        sizePolicy3.setHeightForWidth(lengthSpinBox->sizePolicy().hasHeightForWidth());
        lengthSpinBox->setSizePolicy(sizePolicy3);
        lengthSpinBox->setFont(font);
        lengthSpinBox->setDecimals(3);

        horizontalLayout_8->addWidget(lengthSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(addEdgeGroup);
        label->setObjectName("label");
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        vexBox = new QSpinBox(addEdgeGroup);
        vexBox->setObjectName("vexBox");
        sizePolicy3.setHeightForWidth(vexBox->sizePolicy().hasHeightForWidth());
        vexBox->setSizePolicy(sizePolicy3);
        vexBox->setFont(font);
        vexBox->setMaximum(10000);

        horizontalLayout_2->addWidget(vexBox);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_6->addWidget(addEdgeGroup);

        useBox = new QGroupBox(groupBox);
        useBox->setObjectName("useBox");
        sizePolicy3.setHeightForWidth(useBox->sizePolicy().hasHeightForWidth());
        useBox->setSizePolicy(sizePolicy3);
        verticalLayout_5 = new QVBoxLayout(useBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_2 = new QLabel(useBox);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        useStartBox = new QSpinBox(useBox);
        useStartBox->setObjectName("useStartBox");
        useStartBox->setMaximum(10000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, useStartBox);

        label_4 = new QLabel(useBox);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        useEndBox = new QSpinBox(useBox);
        useEndBox->setObjectName("useEndBox");
        useEndBox->setMaximum(10000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, useEndBox);


        verticalLayout_5->addLayout(formLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lowDistanceButton = new QPushButton(useBox);
        lowDistanceButton->setObjectName("lowDistanceButton");

        horizontalLayout_5->addWidget(lowDistanceButton);

        lowChangeButton = new QPushButton(useBox);
        lowChangeButton->setObjectName("lowChangeButton");

        horizontalLayout_5->addWidget(lowChangeButton);


        verticalLayout_5->addLayout(horizontalLayout_5);

        wayTextEdit = new QTextEdit(useBox);
        wayTextEdit->setObjectName("wayTextEdit");
        sizePolicy.setHeightForWidth(wayTextEdit->sizePolicy().hasHeightForWidth());
        wayTextEdit->setSizePolicy(sizePolicy);
        wayTextEdit->setMaximumSize(QSize(16777215, 100));
        wayTextEdit->setReadOnly(true);

        verticalLayout_5->addWidget(wayTextEdit);


        verticalLayout_6->addWidget(useBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");

        verticalLayout_2->addWidget(widget);


        verticalLayout_6->addLayout(verticalLayout_2);

        tipsButton = new QPushButton(groupBox);
        tipsButton->setObjectName("tipsButton");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tipsButton->sizePolicy().hasHeightForWidth());
        tipsButton->setSizePolicy(sizePolicy5);
        QFont font1;
        font1.setPointSize(12);
        tipsButton->setFont(font1);

        verticalLayout_6->addWidget(tipsButton);


        verticalLayout_7->addWidget(groupBox);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(SideToolEdit);

        QMetaObject::connectSlotsByName(SideToolEdit);
    } // setupUi

    void retranslateUi(QWidget *SideToolEdit)
    {
        SideToolEdit->setWindowTitle(QCoreApplication::translate("SideToolEdit", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SideToolEdit", "\345\267\245\345\205\267", nullptr));
        lineGroup->setTitle(QCoreApplication::translate("SideToolEdit", "\347\272\277\350\267\257", nullptr));
        addLineButton->setText(QCoreApplication::translate("SideToolEdit", "\346\267\273\345\212\240\347\272\277\350\267\257", nullptr));
        deleteLineButton->setText(QCoreApplication::translate("SideToolEdit", "\345\210\240\351\231\244\345\275\223\345\211\215\347\272\277\350\267\257", nullptr));
        circleCheck->setText(QCoreApplication::translate("SideToolEdit", "\347\216\257\347\272\277", nullptr));
        label_5->setText(QCoreApplication::translate("SideToolEdit", "\347\272\277\350\267\257\345\220\215\347\247\260", nullptr));
        addEdgeGroup->setTitle(QCoreApplication::translate("SideToolEdit", "\346\267\273\345\212\240\350\276\271", nullptr));
        addEdgeButton->setText(QCoreApplication::translate("SideToolEdit", "\346\267\273\345\212\240", nullptr));
        styleBox->setItemText(0, QCoreApplication::translate("SideToolEdit", "\346\226\234", nullptr));
        styleBox->setItemText(1, QCoreApplication::translate("SideToolEdit", "\346\250\252\347\253\226", nullptr));
        styleBox->setItemText(2, QCoreApplication::translate("SideToolEdit", "\347\253\226\346\250\252", nullptr));

        directBox->setItemText(0, QCoreApplication::translate("SideToolEdit", "\345\207\272\350\276\271", nullptr));
        directBox->setItemText(1, QCoreApplication::translate("SideToolEdit", "\345\205\245\350\276\271", nullptr));

        label_13->setText(QCoreApplication::translate("SideToolEdit", "\350\276\271\346\235\203", nullptr));
        label->setText(QCoreApplication::translate("SideToolEdit", "\350\277\236\346\216\245\345\210\260\347\202\271", nullptr));
        useBox->setTitle(QCoreApplication::translate("SideToolEdit", "\346\237\245\350\257\242", nullptr));
        label_2->setText(QCoreApplication::translate("SideToolEdit", "\350\265\267\347\202\271\347\274\226\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("SideToolEdit", "\347\273\210\347\202\271\347\274\226\345\217\267", nullptr));
        lowDistanceButton->setText(QCoreApplication::translate("SideToolEdit", "\346\234\200\347\237\255\350\267\235\347\246\273\350\267\257", nullptr));
        lowChangeButton->setText(QCoreApplication::translate("SideToolEdit", "\346\234\200\345\260\221\346\215\242\344\271\230\350\267\257", nullptr));
        tipsButton->setText(QCoreApplication::translate("SideToolEdit", "\346\217\220\347\244\272\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideToolEdit: public Ui_SideToolEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDE_TOOL_EDIT_H
