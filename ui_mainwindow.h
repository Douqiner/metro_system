#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>

#include <QtWidgets/QStackedWidget>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>

#include <QtWidgets/QWidget>

#include "side_tool_edit.h"

#include "mygraph_view.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_use;
    QAction *action_edit;
    QAction *action_save;
    QAction *action_other;

    MyGraphicsView *myGraphicsView;

    SideToolEdit *sideToolEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        //窗口设置
        MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 910);
        // QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        // sizePolicy.setHorizontalStretch(0);
        // sizePolicy.setVerticalStretch(0);
        // sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        // MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/img/day.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        // MainWindow->setStyleSheet(QString::fromUtf8(""));
        //顶部菜单栏
        action_use = new QAction(MainWindow);
        action_edit = new QAction(MainWindow);
        action_save = new QAction(MainWindow);
        action_save->setShortcut(QKeySequence::Save);
        action_other = new QAction(MainWindow);

        action_use->setObjectName("action_use");
        action_edit->setObjectName("action_edit");
        action_save->setObjectName("action_save");
        action_other->setObjectName("action_other");

        action_use->setText("线路查询");
        action_edit->setText("线路编辑");
        action_save->setText("保存");
        action_other->setText("另存为");

        QStatusBar *statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        QMenuBar *menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 24));
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 255, 213);"));

        QMenu *menu_mode = new QMenu(menubar);
        menu_mode->setTitle("模式");
        menu_mode->setObjectName("menu_mode");
        menu_mode->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 131, 255);"));
        QMenu *menu_file = new QMenu(menubar);
        menu_file->setTitle("文件");
        menu_file->setObjectName("menu_file");
        menu_file->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 131, 255);"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_mode->menuAction());
        menubar->addAction(menu_file->menuAction());
        menu_mode->addAction(action_use);
        menu_mode->addAction(action_edit);
        menu_file->addAction(action_save);
        menu_file->addAction(action_other);
        //主体
        QWidget *centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");

        QHBoxLayout *horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");

        //主体左
        myGraphicsView = new MyGraphicsView(centralwidget);
        myGraphicsView->setObjectName("graphicsView");

        horizontalLayout->addWidget(myGraphicsView);
        //主体右
        sideToolEdit = new SideToolEdit(centralwidget);
        action_edit->setDisabled(true);

        sideToolEdit->setMaximumWidth(334);

        sideToolEdit->setModeEdit();

        horizontalLayout->addWidget(sideToolEdit);

        MainWindow->setCentralWidget(centralwidget);
    }
};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
