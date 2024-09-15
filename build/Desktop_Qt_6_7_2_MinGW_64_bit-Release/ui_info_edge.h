/********************************************************************************
** Form generated from reading UI file 'info_edge.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_EDGE_H
#define UI_INFO_EDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoEdge
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *idLineEdit;
    QLabel *label_3;
    QDoubleSpinBox *lengthSpinBox;
    QLabel *label_7;
    QComboBox *styleBox;
    QLabel *label_6;
    QSpinBox *startSpinBox;
    QLabel *label_8;
    QSpinBox *endSpinBox;
    QLabel *label_9;
    QLineEdit *lineEdit0;
    QLabel *label_10;
    QLineEdit *lineEdit1;
    QPushButton *deleteButton;

    void setupUi(QWidget *InfoEdge)
    {
        if (InfoEdge->objectName().isEmpty())
            InfoEdge->setObjectName("InfoEdge");
        InfoEdge->resize(179, 343);
        verticalLayout = new QVBoxLayout(InfoEdge);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(InfoEdge);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(9);
        label_2->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        idLineEdit = new QLineEdit(groupBox);
        idLineEdit->setObjectName("idLineEdit");
        sizePolicy.setHeightForWidth(idLineEdit->sizePolicy().hasHeightForWidth());
        idLineEdit->setSizePolicy(sizePolicy);
        idLineEdit->setFont(font);
        idLineEdit->setDragEnabled(false);
        idLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, idLineEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lengthSpinBox = new QDoubleSpinBox(groupBox);
        lengthSpinBox->setObjectName("lengthSpinBox");
        sizePolicy.setHeightForWidth(lengthSpinBox->sizePolicy().hasHeightForWidth());
        lengthSpinBox->setSizePolicy(sizePolicy);
        lengthSpinBox->setFont(font);
        lengthSpinBox->setDecimals(3);

        formLayout->setWidget(1, QFormLayout::FieldRole, lengthSpinBox);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        styleBox = new QComboBox(groupBox);
        styleBox->addItem(QString());
        styleBox->addItem(QString());
        styleBox->addItem(QString());
        styleBox->setObjectName("styleBox");
        sizePolicy.setHeightForWidth(styleBox->sizePolicy().hasHeightForWidth());
        styleBox->setSizePolicy(sizePolicy);
        styleBox->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, styleBox);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        startSpinBox = new QSpinBox(groupBox);
        startSpinBox->setObjectName("startSpinBox");
        startSpinBox->setEnabled(true);
        sizePolicy.setHeightForWidth(startSpinBox->sizePolicy().hasHeightForWidth());
        startSpinBox->setSizePolicy(sizePolicy);
        startSpinBox->setFont(font);
        startSpinBox->setReadOnly(true);
        startSpinBox->setMaximum(10000);

        formLayout->setWidget(3, QFormLayout::FieldRole, startSpinBox);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        endSpinBox = new QSpinBox(groupBox);
        endSpinBox->setObjectName("endSpinBox");
        sizePolicy.setHeightForWidth(endSpinBox->sizePolicy().hasHeightForWidth());
        endSpinBox->setSizePolicy(sizePolicy);
        endSpinBox->setFont(font);
        endSpinBox->setReadOnly(true);
        endSpinBox->setMaximum(10000);

        formLayout->setWidget(4, QFormLayout::FieldRole, endSpinBox);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        lineEdit0 = new QLineEdit(groupBox);
        lineEdit0->setObjectName("lineEdit0");
        sizePolicy.setHeightForWidth(lineEdit0->sizePolicy().hasHeightForWidth());
        lineEdit0->setSizePolicy(sizePolicy);
        lineEdit0->setFont(font);
        lineEdit0->setDragEnabled(false);
        lineEdit0->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit0);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_10);

        lineEdit1 = new QLineEdit(groupBox);
        lineEdit1->setObjectName("lineEdit1");
        sizePolicy.setHeightForWidth(lineEdit1->sizePolicy().hasHeightForWidth());
        lineEdit1->setSizePolicy(sizePolicy);
        lineEdit1->setFont(font);
        lineEdit1->setDragEnabled(false);
        lineEdit1->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit1);


        verticalLayout_2->addLayout(formLayout);

        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName("deleteButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        deleteButton->setFont(font);

        verticalLayout_2->addWidget(deleteButton);


        verticalLayout->addWidget(groupBox);


        retranslateUi(InfoEdge);

        QMetaObject::connectSlotsByName(InfoEdge);
    } // setupUi

    void retranslateUi(QWidget *InfoEdge)
    {
        InfoEdge->setWindowTitle(QCoreApplication::translate("InfoEdge", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("InfoEdge", "\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("InfoEdge", "\347\274\226\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("InfoEdge", "\350\276\271\351\225\277", nullptr));
        label_7->setText(QCoreApplication::translate("InfoEdge", "\350\276\271\345\275\242", nullptr));
        styleBox->setItemText(0, QCoreApplication::translate("InfoEdge", "\346\226\234", nullptr));
        styleBox->setItemText(1, QCoreApplication::translate("InfoEdge", "\346\250\252\347\253\226", nullptr));
        styleBox->setItemText(2, QCoreApplication::translate("InfoEdge", "\347\253\226\346\250\252", nullptr));

        label_6->setText(QCoreApplication::translate("InfoEdge", "\350\265\267\347\202\271", nullptr));
        label_8->setText(QCoreApplication::translate("InfoEdge", "\347\273\210\347\202\271", nullptr));
        label_9->setText(QCoreApplication::translate("InfoEdge", "\347\272\277\350\267\2571", nullptr));
        label_10->setText(QCoreApplication::translate("InfoEdge", "\347\272\277\350\267\2572", nullptr));
        deleteButton->setText(QCoreApplication::translate("InfoEdge", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoEdge: public Ui_InfoEdge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_EDGE_H
