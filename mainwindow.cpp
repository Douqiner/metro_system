#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //切换两大模式
    QObject::connect(ui->action_use, &QAction::triggered, this, &MainWindow::setSideToolView);
    QObject::connect(ui->action_edit, &QAction::triggered, this, &MainWindow::setSideToolEdit);
    //发出信息更新需求
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::showSationInfo, ui->sideToolEdit, &SideToolEdit::setInfoSation);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::showEdgeInfo, ui->sideToolEdit, &SideToolEdit::setInfoEdge);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::unshow, ui->sideToolEdit, &SideToolEdit::setInfoClose);
    //添加边
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAddEdge, ui->myGraphicsView, &MyGraphicsView::checkAddEdge);
    //信息修改
    QObject::connect(ui->sideToolEdit->infoSation, &InfoSation::sendSetVexName, ui->myGraphicsView, &MyGraphicsView::setSationName);
    QObject::connect(ui->sideToolEdit->infoSation, &InfoSation::sendSetVexCenter, ui->myGraphicsView, &MyGraphicsView::setSationCenter);
    QObject::connect(ui->sideToolEdit->infoSation, &InfoSation::sendSetVexSize, ui->myGraphicsView, &MyGraphicsView::setSationSize);
    QObject::connect(ui->sideToolEdit->infoSation, &InfoSation::sendDeleteVex, ui->myGraphicsView, &MyGraphicsView::deleteSation);

    QObject::connect(ui->sideToolEdit->infoEdge, &InfoEdge::sendSetEdgeWeight, ui->myGraphicsView, &MyGraphicsView::setEdgeWeight);
    QObject::connect(ui->sideToolEdit->infoEdge, &InfoEdge::sendSetEdgeStyle, ui->myGraphicsView, &MyGraphicsView::setEdgeStyle);
    QObject::connect(ui->sideToolEdit->infoEdge, &InfoEdge::sendDeleteEdge, ui->myGraphicsView, &MyGraphicsView::deleteEdge);
    //线路信息
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskAddLine, ui->myGraphicsView, &MyGraphicsView::replyAddLine);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::sendReplyAddLine, ui->sideToolEdit, &SideToolEdit::addLine);
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskLineChange, ui->myGraphicsView, &MyGraphicsView::replyLineChange);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::sendLineInfo, ui->sideToolEdit, &SideToolEdit::lineChange);
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskSetLineInfo, ui->myGraphicsView, &MyGraphicsView::setLineInfo);
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskDeleteLine, ui->myGraphicsView, &MyGraphicsView::deleteLine);
    //是否编辑过
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::sendSetTitleEdited, this, &MainWindow::setTitleEdited);
    //文件
    QObject::connect(ui->action_save, &QAction::triggered, this, &MainWindow::askSave);
    QObject::connect(ui->action_other, &QAction::triggered, this, &MainWindow::askOther);
    QObject::connect(this, &MainWindow::sendAskSave, ui->myGraphicsView, &MyGraphicsView::replySave);
    QObject::connect(this, &MainWindow::sendAskOther, ui->myGraphicsView, &MyGraphicsView::replyOther);
    QObject::connect(this, &MainWindow::sendAskRead, ui->myGraphicsView, &MyGraphicsView::replyRead);
    //换乘指南
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskLowDistancePath, ui->myGraphicsView, &MyGraphicsView::replyLowDistance);
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskLowChangePath, ui->myGraphicsView, &MyGraphicsView::replyLowChange);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::sendPathText, ui->sideToolEdit, &SideToolEdit::setPathText);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::askRead()
{
    emit sendAskRead(filePath);
}

void MainWindow::setSideToolView()
{
    ui->action_use->setDisabled(true);
    ui->action_edit->setDisabled(false);
    //切换工作
    //view进行切换
    ui->myGraphicsView->changeToUse();
    //side_tool进行切换
    ui->sideToolEdit->setModeUse();
}

void MainWindow::setSideToolEdit()
{
    ui->action_use->setDisabled(false);
    ui->action_edit->setDisabled(true);
    //切换工作
    //view进行切换
    ui->myGraphicsView->changeToEdit();
    //side_tool进行切换
    ui->sideToolEdit->setModeEdit();
}

void MainWindow::setTitleEdited(bool edited)
{
    if (edited) {
        if (filePath.isEmpty())
            this->setWindowTitle("无标题*");
        else
            this->setWindowTitle(filePath + "*");
    }
    else {
        if (filePath.isEmpty())
            this->setWindowTitle("无标题");
        else
            this->setWindowTitle(filePath);
    }
}

void MainWindow::askSave()
{
    if (ui->myGraphicsView->EDITED) {
        if (filePath.isEmpty()) {
            QFileDialog f(this);
            filePath =  QFileDialog::getSaveFileName(this, "保存文件位置", QString(), "地铁线路文件 (*.mtr)");
            if (!filePath.isEmpty()) {
                emit sendAskSave(filePath);
            }
        }
        else
            emit sendAskSave(filePath);
    }
}

void MainWindow::askOther()
{
    QFileDialog f(this);
    QString otherPath =  QFileDialog::getSaveFileName(this, "另存文件位置", QString(), "地铁线路文件 (*.mtr)");
    if (!filePath.isEmpty()) {
        emit sendAskOther(otherPath);
    }
}
