#ifndef SIDE_TOOL_EDIT_H
#define SIDE_TOOL_EDIT_H

#include <QWidget>
#include <QPushButton>
#include <QColorDialog>
#include <QStackedWidget>
#include <QMessageBox>

#include "info_sation.h"
#include "info_edge.h"

namespace Ui {
class SideToolEdit;
}

//加入颜色属性的按钮
class myColorBotton : public QPushButton
{
public:
    int r;
    int g;
    int b;

    explicit myColorBotton(QWidget *parent = nullptr) : QPushButton(parent)
    {
        r = 0;
        g = 0;
        b = 0;
    }

    void set_rgb(int rr, int gg, int bb)
    {
        r = rr;
        g = gg;
        b = bb;
        QString style = "color: rgb(";
        style += QString::number(r);
        style += " ,";
        style += QString::number(g);
        style += " ,";
        style += QString::number(b);
        style += ");";
        style += "font: 9pt \"Microsoft YaHei UI\";";
        this->setStyleSheet(QString::fromUtf8(style.toStdString()));
    }
};

class SideToolEdit : public QWidget
{
    Q_OBJECT

public:
    explicit SideToolEdit(QWidget *parent = nullptr);
    ~SideToolEdit();
    //切换模式
    void setModeEdit();
    void setModeUse();

    InfoSation* infoSation;
    InfoEdge* infoEdge;
private:
    Ui::SideToolEdit *ui;
    myColorBotton *colorButton;
    QColorDialog *colorDialog;
    QStackedWidget* information;

private slots:
    //自用
    //颜色按钮
    void send_to_dialog();
    void send_to_button();
    //发出添加边信息
    void addEdge();
    //发出线路请求
    void askAddLine();
    void askLineChange();
    void askSetLineInfo();
    void askDeleteLine();
    //发出查询请求
    void askLowDistancePath();
    void askLowChangePath();

public slots:
    //接受信息
    void setInfoSation(int id, QString name, int size, QPointF center);
    void setInfoEdge(int id, qreal weight, int style, int from, int to, QString line0, QString line1);
    void setInfoClose();
    //接受线路信息
    void addLine(int index, QString name);
    void lineChange(QString name, QColor color, int isCircle);
    //接受换乘指南
    void setPathText(QString way);
    //提示
    void showTips();

signals:
    //添加边
    void sendAddEdge(int from, int to, int style, qreal weight);
    //线路
    void sendAskAddLine(QString name, QColor color, int isCircle);
    void sendAskLineChange(int id);
    void sendAskSetLineInfo(int id, QString name, QColor color, int isCircle);
    void sendAskDeleteLine(int id);
    //查询信号
    void sendAskLowDistancePath(int from, int to);
    void sendAskLowChangePath(int from, int to);
};

#endif // SIDE_TOOL_EDIT_H
