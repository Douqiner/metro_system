/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pbtn_open;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pbtn_create;

    void setupUi(QWidget *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(1080, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/img/day.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        StartWindow->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(StartWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(StartWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";\n"
"background-image: url(:/back/img/use.png);"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        pbtn_open = new QPushButton(groupBox);
        pbtn_open->setObjectName("pbtn_open");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbtn_open->sizePolicy().hasHeightForWidth());
        pbtn_open->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        pbtn_open->setFont(font);
        pbtn_open->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pbtn_open->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 255);\n"
"font: 700 20pt \"Microsoft YaHei UI\";"));
        pbtn_open->setFlat(false);

        verticalLayout->addWidget(pbtn_open);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(StartWindow);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";\n"
"background-image: url(:/back/img/edit.png);"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        pbtn_create = new QPushButton(groupBox_2);
        pbtn_create->setObjectName("pbtn_create");
        sizePolicy.setHeightForWidth(pbtn_create->sizePolicy().hasHeightForWidth());
        pbtn_create->setSizePolicy(sizePolicy);
        pbtn_create->setFont(font);
        pbtn_create->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pbtn_create->setStyleSheet(QString::fromUtf8("color: rgb(69, 255, 215);\n"
"font: 700 20pt \"Microsoft YaHei UI\";\n"
""));

        verticalLayout_2->addWidget(pbtn_create);


        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QWidget *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "\345\234\260\351\223\201\347\263\273\347\273\237\347\273\210\347\253\257_\350\246\203\345\243\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StartWindow", "\346\211\223\345\274\200\347\216\260\346\234\211\346\226\207\344\273\266", nullptr));
        pbtn_open->setText(QCoreApplication::translate("StartWindow", "\346\211\223\345\274\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("StartWindow", "\345\210\233\345\273\272\346\226\260\346\226\207\344\273\266", nullptr));
        pbtn_create->setText(QCoreApplication::translate("StartWindow", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
