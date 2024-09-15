#ifndef MYGRAPH_VIEW_H
#define MYGRAPH_VIEW_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QColor>

#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>

#include <QDebug>
#include <QSet>
#include <QFile>

class MySationItem;
class MyEdgeItem;
class MyGraphicsView;
const QColor nullColor = QColor(172, 172, 172);
// 边型
enum myShape {
    straight,
    cross_down,
    down_cross
};
const int sizeToRadius[2] = {8, 10};

//点信息
struct vNode {
    bool isExist = false;
    //拓扑信息
    int posFirst = -1;  // 正邻接表第一条边编号
    int invFirst = -1;  // 逆邻接表第一条边编号 // 删除时上一个被删除的编号
    int inDegree = 0;  // 入度
    int outDegree = 0; // 出度
    //其它信息
    MySationItem* sationAt;
};

struct eNode{
    bool isExist = false;
    //拓扑信息
    int from = -1;   // 来自点 // 删除时上一个被删除的编号
    int to = -1;     // 到达点
    qreal weight;
    //线路信息
    int belongLine[2] = {0, 0};
    int getLineNum() {
        int cnt = 0;
        if (belongLine[0])
            ++cnt;
        if (belongLine[1])
            ++cnt;
        return cnt;
    }
    QSet<int> getLineSet() {
        QSet<int> line;
        switch(getLineNum()) {
        case 0:
            line.insert(0);
            break;
        case 1:
            if (belongLine[0])
                line.insert(belongLine[0]);
            else
                line.insert(belongLine[1]);
            break;
        case 2:
            line.insert(belongLine[0]);
            line.insert(belongLine[1]);
            break;
        }
        return line;
    }
    //其它信息
    MyEdgeItem* edgeAt;
};

struct lNode
{
    bool isExist = false;
    //拓扑信息
    QSet<int> contain; //包含的边
    //其它信息
    int isCircle = -1; // 是否环线 // 删除时上一个被删除的编号
    QString name = "未选择";
    QColor color = QColor(0, 0, 0);
};

class AbstractGraph
{
public:
    MyGraphicsView* view;

    //图
    int vMaxId = -1;
    int vNum = 0;
    int vLastDelete = -1;

    int eMaxId = -1;
    int eNum = 0;
    int eLastDelete = -1;

    QVector<vNode> vInfo;  // 下标为点id
    QVector<eNode> eInfo;  // 下标为边id

    QVector<int> posList;  // 正邻接表 下标为边id 内容为指向下一条边
    QVector<int> invList;  // 逆邻接表 下标为边id 内容为指向下一条边

    //线路
    int lMaxId = -1;
    int lNum = 0;
    int lLastDelete = -1;
    QVector<lNode> lInfo;  //下标为线路id

    AbstractGraph(MyGraphicsView* view);
    //图操作
    MySationItem* addVex(QPointF center, int size, QString name);

    MyEdgeItem* addEdge(int from, int to, enum myShape style, qreal weight);
    bool checkExist(int from, int to);
    bool checkNoLoop(int from, int to);
    bool checkNoRepetition(int from, int to);

    void setEdgeWeidght(int id, qreal weight);

    void deleteVex(int id);
    void deleteEdge(int id);
    //线路操作
    int addLine(QString name, QColor color, int isCircle);
    void setLineInfo(int id, QString name, QColor color, int isCircle);
    int edgeAddToLine(int idEdge, int idLine);//-1失败0成功
    int edgeDeleteFromLine(int idEdge, int idLine);//-1失败0成功
    void deleteLine(int id);
    //保存和读取
    int save(QString filePath);
    int read(QString filePath);//只能在初始化后使用
    //算法
    QVector<int> lowDistance(int from, int to);
    QVector<int> lowChange(int from, int to);
    QString pathToText(QVector<int> path);
};


//MyGraphicsView（滚轮缩放/右键拖动移动）
class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    //场景
    QGraphicsScene* myGraphicsScene;
    //拓扑结构
    AbstractGraph tupo = AbstractGraph(this);
    //模式
    enum MODE {
        Edit,
        Use
    };
    int mode = Edit;
    //事件相关变量
    QPointF lastPos;
    bool onRightPress = false;//是否正在移动
    bool onLeftPress = false;//是否正在拖动点

    bool SELECTED;//是否有图元在选中
    QGraphicsItem *selectItem = nullptr;//选中的图元
    void setNewSelected(QGraphicsItem *newSelectItem);

    explicit MyGraphicsView(QWidget *parent = nullptr);
    //模式切换
    enum Qt::CursorShape backModeCurser();
    void changeToUse();
    void changeToEdit();

    //图操作
    MySationItem* addSation(QPointF center);

    //当前线路
    int currentLine = 0;
    bool SHOWING = false;
    QVector<int> showPath;
    //编辑状态
    bool EDITED = false;
    void setEdited(bool edited);

    ~MyGraphicsView();

protected:
    //鼠标事件重写
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

signals:
    //信息栏
    void showSationInfo(int id, QString name, int size, QPointF center);
    void showEdgeInfo(int id, qreal weight, int style, int from, int to, QString line0, QString line1);
    void unshow();
    //线路返回信号
    void sendReplyAddLine(int index, QString name);
    void sendLineInfo(QString name, QColor color, int isCircle);
    //主界面信号
    void sendSetTitleEdited(bool edited);
    //发送换乘指南
    void sendPathText(QString way);

public slots:
    void checkAddEdge(int from, int to, int style, qreal weight);
    //接受信息修改
    void setSationName(int id, QString name);
    void setSationCenter(int id, QPointF center);
    void setSationSize(int id, int size);
    void setEdgeWeight(int id, qreal weight);
    void setEdgeStyle(int id, int style);

    void deleteSation(int id) {
        setNewSelected(nullptr);
        tupo.deleteVex(id);
        // 更改信号
        setEdited(true);
    }
    void deleteEdge(int id) {
        setNewSelected(nullptr);
        tupo.deleteEdge(id);
        // 更改信号
        setEdited(true);
    }
    //接受线路请求
    void replyAddLine(QString name, QColor color, int isCircle);
    void tellAddLine(int index, QString name);
    void replyLineChange(int id);
    void setLineInfo(int id, QString name, QColor color, int isCircle);
    void deleteLine(int id);
    //接受文件请求
    void replySave(QString filePath);
    void replyOther(QString otherPath);
    void replyRead(QString filePath);
    //接受查询请求
    void replyLowDistance(int from, int to);
    void replyLowChange(int from, int to);
};

enum myType {
    mySationItem = QGraphicsItem::UserType + 1,
    myEdgeItem = QGraphicsItem::UserType + 2
};


class MySationItem : public QGraphicsEllipseItem
{
public:
    explicit MySationItem(int id, QPointF center, int size, QString name, MyGraphicsView* view);
    ~MySationItem();
    void rePaint(QPointF center);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    int type() const override {return myType::mySationItem;};
    QPointF getCenter();

    //信息
    int id;
    int size;
    QString name;
    QGraphicsTextItem* text = nullptr;

    MyGraphicsView* view;
    //状态
    bool SELECTED = false;

private:
    //设置
    int fontSize = 10;
    QBrush myBrush = QBrush(nullColor);
    QPen myPen = QPen(QColor(0, 0, 0), 2);
    QFont myFont = QFont("Microsoft YaHei UI", 10);
};


class MyEdgeItem : public QGraphicsPathItem
{
public:
    explicit MyEdgeItem(int id, enum myShape style, MyGraphicsView* view);
    int type() const override {return myType::myEdgeItem;};
    void reSetStyle();
    void reSetPath();
    void setChoosed(bool choosed);

    //信息
    int id;
    enum myShape style;
    MyGraphicsView* view;
    //状态
    bool SELECTED = false;//点击选中
    bool CHOOSED = false; //线路选中

private:
    //图形
    QGraphicsPathItem* secondLine = nullptr;
    //设置
    int edgeSpace = 3;
    int myPenWidth = 6;
    int arrowWidth = 2;
    int arrowLength = 6;
    qreal arrowAngle = M_PI / 6;

};

#endif // MYGRAPH_VIEW_H
