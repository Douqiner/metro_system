#include "mygraph_view.h"
#include <queue>
#include <algorithm>

AbstractGraph::AbstractGraph(MyGraphicsView* view) {
    this->view = view;

    //初始有一条默认线路“未选择”,标识所有未选择线路
    lInfo.append(lNode());
    lMaxId = 0;
    lNum += 1;

    lInfo[0].isExist = false;
    lInfo[0].color = nullColor;
    lInfo[0].isCircle = -1;
    lInfo[0].name = "未选择";

}

MySationItem* AbstractGraph::addVex(QPointF center, int size, QString name) {
    // 确定id
    int id;
    if (vMaxId + 1 == vNum) {
        id = vNum;
        vMaxId += 1;
        vInfo.append(vNode());
    } else {
        id = vLastDelete;
        vLastDelete = vInfo[id].invFirst;
    }
    ++vNum;
    name += QString::number(id);
    // 设置信息
    vInfo[id].isExist = true;
    vInfo[id].inDegree = 0;
    vInfo[id].outDegree = 0;
    vInfo[id].posFirst = -1;
    vInfo[id].invFirst = -1;
    // 新建item
    vInfo[id].sationAt = new MySationItem(id, center, size, name, view);
    return vInfo[id].sationAt;
}

MyEdgeItem* AbstractGraph::addEdge(int from,
                                   int to,
                                   enum myShape style,
                                   qreal weight) {
    // 默认已经检查好
    // 确定id
    int id;
    if (eMaxId + 1 == eNum) {
        id = eNum;
        eMaxId += 1;
        eInfo.append(eNode());
        posList.append(-1);
        invList.append(-1);
    } else {
        id = eLastDelete;
        eLastDelete = eInfo[id].from;
    }
    ++eNum;
    // 设置信息
    eInfo[id].isExist = true;
    eInfo[id].from = from;
    eInfo[id].to = to;
    eInfo[id].weight = weight;
    // 线路
    eInfo[id].belongLine[0] = 0;
    eInfo[id].belongLine[1] = 0;
    // 修改正逆邻接表(头插法)
    posList[id] = vInfo[from].posFirst;
    vInfo[from].posFirst = id;
    ++vInfo[from].outDegree;

    invList[id] = vInfo[to].invFirst;
    vInfo[to].invFirst = id;
    ++vInfo[to].inDegree;

    // 新建item
    eInfo[id].edgeAt = new MyEdgeItem(id, style, view);
    return eInfo[id].edgeAt;
}

bool AbstractGraph::checkExist(int from, int to) {
    if (from > vMaxId || to > vMaxId)
        return false;
    if (!vInfo[from].isExist || !vInfo[to].isExist)
        return false;
    return true;
}

bool AbstractGraph::checkNoLoop(int from, int to) {
    if (from == to)
        return false;
    else
        return true;
}

bool AbstractGraph::checkNoRepetition(int from, int to) {
    for (int e = vInfo[from].posFirst; e != -1; e = posList[e]) {
        if (eInfo[e].to == to)
            return false;
    }
    return true;
}

void AbstractGraph::setEdgeWeidght(int id, qreal weight) {
    eInfo[id].weight = weight;
}

void AbstractGraph::deleteVex(int id) {
    // 删除出边、入边
    for (int e = vInfo[id].posFirst; e != -1; e = posList[e]) {
        deleteEdge(e);
    }
    for (int e = vInfo[id].invFirst; e != -1; e = invList[e]) {
        deleteEdge(e);
    }
    // 删除点
    --vNum;
    vInfo[id].isExist = false;
    vInfo[id].invFirst = vLastDelete;
    vLastDelete = id;
    // 移除图元
    view->myGraphicsScene->removeItem(vInfo[id].sationAt);
    delete vInfo[id].sationAt;
}

void AbstractGraph::deleteEdge(int id) {
    // 邻接表中删除边
    // 正邻接表
    int e;
    e = vInfo[eInfo[id].from].posFirst;
    if (e == id) {
        // 第一条边
        vInfo[eInfo[id].from].posFirst = posList[e];
        --vInfo[eInfo[id].from].outDegree;
    } else {
        for (; posList[e] != id; e = posList[e])
            ;
        posList[e] = posList[id];
        --vInfo[eInfo[id].from].outDegree;
    }
    // 逆邻接表
    e = vInfo[eInfo[id].to].invFirst;
    if (e == id) {
        // 第一条边
        vInfo[eInfo[id].to].invFirst = invList[e];
        --vInfo[eInfo[id].to].inDegree;
    } else {
        for (; invList[e] != id; e = invList[e])
            ;
        invList[e] = invList[id];
        --vInfo[eInfo[id].to].inDegree;
    }
    // 移除图元
    view->myGraphicsScene->removeItem(eInfo[id].edgeAt);
    delete eInfo[id].edgeAt;
    // 维护信息
    --eNum;
    eInfo[id].isExist = false;
    eInfo[id].from = eLastDelete;
    eLastDelete = id;
    //维护线路
    if (eInfo[id].belongLine[0])
        lInfo[eInfo[id].belongLine[0]].contain.remove(id);
    if (eInfo[id].belongLine[1])
        lInfo[eInfo[id].belongLine[1]].contain.remove(id);
}

int AbstractGraph::addLine(QString name, QColor color, int isCircle)
{
    // 确定id
    int id;
    if (lMaxId + 1 == lNum) {
        id = lNum;
        lMaxId += 1;
        lInfo.append(lNode());
    } else {
        id = lLastDelete;
        lLastDelete = lInfo[id].isCircle;
    }
    ++lNum;
    // 设置信息
    lInfo[id].isExist = true;
    lInfo[id].name = name;
    lInfo[id].color = color;
    lInfo[id].isCircle = isCircle;

    return id;
}

void AbstractGraph::setLineInfo(int id, QString name, QColor color, int isCircle)
{
    lInfo[id].name = name;
    lInfo[id].color = color;
    lInfo[id].isCircle = isCircle;
}

int AbstractGraph::edgeAddToLine(int idEdge, int idLine)
{
    if (eInfo[idEdge].getLineNum() == 2)
        return -1;
    if (eInfo[idEdge].belongLine[0] == idLine || eInfo[idEdge].belongLine[1] == idLine)
        return -1;
    // 线路进行插入
    lInfo[idLine].contain.insert(idEdge);
    // 边记录插入
    if (eInfo[idEdge].belongLine[0])
        eInfo[idEdge].belongLine[1] = idLine;
    else
        eInfo[idEdge].belongLine[0] = idLine;

    return 0;
}

int AbstractGraph::edgeDeleteFromLine(int idEdge, int idLine)
{
    if (eInfo[idEdge].getLineNum() == 0)
        return -1;
    // 边记录删除
    if (eInfo[idEdge].belongLine[0] == idLine)
        eInfo[idEdge].belongLine[0] = 0;
    else if (eInfo[idEdge].belongLine[1] == idLine)
        eInfo[idEdge].belongLine[1] = 0;
    else
        return -1;
    // 线路进行删除
    lInfo[idLine].contain.remove(idEdge);
    return 0;
}


void AbstractGraph::deleteLine(int id)
{
    for (int e : lInfo[id].contain) {
        edgeDeleteFromLine(e, id);
        //只能在这里写了
        eInfo[e].edgeAt->reSetStyle();
    }
    //线路清除
    --lNum;
    // lInfo[id].contain.clear();
    lInfo[id].isExist = false;
    lInfo[id].isCircle = lLastDelete;
    lLastDelete = id;
}

int AbstractGraph::save(QString filePath)
{
    QFile out(filePath);
    if (out.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream ts(&out);
        //点
        ts << vMaxId << " " << vLastDelete << Qt::endl;
        for (vNode v : vInfo) {
            ts << v.isExist << " " ;
            if (v.isExist){
                ts << v.sationAt->name << " " << v.sationAt->size<< " " ;
                QPointF center = v.sationAt->getCenter();
                ts << center.x() << " " << center.y() << Qt::endl;
            }
            else
                ts << v.invFirst << Qt::endl;
        }
        //线路
        ts << lMaxId << " " << lLastDelete << " " << Qt::endl;
        for (lNode l : lInfo) {
            ts << l.isExist << " " ;
            if (l.isExist){
                ts << l.name << " " << l.isCircle << " " << l.color.red() << " " << l.color.green() << " " << l.color.blue() << Qt::endl;
            }
            else
                ts << l.isCircle << Qt::endl;
        }
        //边
        ts << eMaxId << " " << eLastDelete <<Qt::endl;
        for (eNode e : eInfo) {
            ts << e.isExist << " " ;
            if (e.isExist){
                ts << e.from << " " << e.to << " " << e.weight << " " << e.belongLine[0] << " " << e.belongLine[1] << " " ;
                ts << (int)e.edgeAt->style << Qt::endl;
            }
            else
                ts << e.from << Qt::endl;
        }

        out.close();
        return 0;
    }
    else {
        return -1;
    }
}

int AbstractGraph::read(QString filePath)
{
    QFile in(filePath);
    if (in.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream ts(&in);
        int isExist;
        //点
        ts >> vMaxId >> vLastDelete;
        vInfo.resize(vMaxId + 1);
        for (int i = 0; i <= vMaxId; ++i) {
            ts >> isExist;
            vNode v;
            v.isExist = isExist;
            if (isExist){
                QString name;
                int size;
                qreal x, y;

                ts >> name >> size >> x >> y;
                // 新建item
                v.sationAt = new MySationItem(i, QPointF(x, y), size, name, view);
                view->myGraphicsScene->addItem(v.sationAt);
                vInfo[i] = v;

                ++vNum;
            }
            else {
                ts >> v.invFirst;
                vInfo[i] = v;
            }
        }
        //线路
        ts >> lMaxId >> lLastDelete;
        lInfo.resize(lMaxId + 1);
        for (int i = 0; i <= lMaxId; ++i) {
            ts >> isExist;
            lNode l;
            l.isExist = isExist;
            if (isExist){
                int r, g, b;
                ts >> l.name >> l.isCircle >> r >> g >> b;
                l.color = QColor(r, g, b);
                lInfo[i] = l;

                ++lNum;
                view->tellAddLine(i, l.name);
            }
            else {
                ts >> l.isCircle;
                if (i != 0) {
                    lInfo[i] = l;
                }
            }
        }
        //边
        ts >> eMaxId >> eLastDelete;
        eInfo.resize(eMaxId + 1);
        posList.resize(eMaxId + 1);
        invList.resize(eMaxId + 1);
        for (int i = 0; i <= eMaxId; ++i) {
            ts >> isExist;
            eNode e;
            e.isExist = isExist;
            if (isExist){
                int style;
                ts >> e.from >> e.to >> e.weight >> e.belongLine[0] >> e.belongLine[1] >> style;

                // 修改正逆邻接表(头插法)
                posList[i] = vInfo[e.from].posFirst;
                vInfo[e.from].posFirst = i;
                ++vInfo[e.from].outDegree;

                invList[i] = vInfo[e.to].invFirst;
                vInfo[e.to].invFirst = i;
                ++vInfo[e.to].inDegree;

                //修改线路
                if (e.belongLine[0])
                    lInfo[e.belongLine[0]].contain.insert(i);
                if (e.belongLine[1])
                    lInfo[e.belongLine[1]].contain.insert(i);

                eInfo[i] = e;

                // 新建item
                eInfo[i].edgeAt = new MyEdgeItem(i, (enum myShape)style, view);
                eInfo[i].edgeAt->setZValue(-1);
                view->myGraphicsScene->addItem(eInfo[i].edgeAt);

                ++eNum;
            }
            else {
                ts >> e.from;
                eInfo[i] = e;
            }
        }

        in.close();
        return 0;
    }
    else {
        return -1;
    }
}


QVector<int> AbstractGraph::lowDistance(int from, int to)
{
    //用于搜索的结构体
    struct disNode {
        int v;        // 当前点编号
        double g;     // 当前走过路径
        int edgeFrom; // 此节点来自哪条边
        bool operator<(const disNode &b) const
        {
            return g > b.g;
        }
    };

    // 优先队列
    std::priority_queue<disNode> q;
    // 路径记录 某个点来自哪条边
    QVector<int> path(vMaxId + 1, -1);
    // 路径 顺序边记录
    QVector<int> ans;
    // 起点
    disNode startNode;
    startNode.v      = from;
    startNode.g        = 0;
    startNode.edgeFrom = -2;
    q.push(startNode);

    while (!q.empty()) {
        disNode curNode = q.top();
        q.pop();

        // 判断是否拓展
        if (path[curNode.v] != -1)
            continue;
        else
            path[curNode.v] = curNode.edgeFrom;

        if (curNode.v == to) {
            // 找到终点 计算路径
            int cur      = curNode.v;
            int edgeFrom = curNode.edgeFrom;

            while (path[cur] != -2) {
                ans.push_back(edgeFrom);
                cur      = eInfo[path[cur]].from;
                edgeFrom = path[cur];
            }
            std::reverse(ans.begin(), ans.end());
            break;
        }

        // 拓展节点
        for (int i = vInfo[curNode.v].posFirst; i != -1; i = posList[i]) {
            disNode nextNode;
            nextNode.v        = eInfo[i].to;
            nextNode.g        = curNode.g + eInfo[i].weight;
            nextNode.edgeFrom = i;

            q.push(nextNode);
        }
    }

    return ans;
}


QVector<int> AbstractGraph::lowChange(int from, int to)
{
    //用于搜索的结构体
    struct chgNode {
        int v;        // 当前点编号
        int change;   // 当前换乘次数(包括第一次)
        int l;        // 当前线路
        int edgeFrom; // 此节点来自哪条边
        int pathFrom; // 此节点来自哪个路径记录节点
        bool operator<(const chgNode &b) const
        {
            return change > b.change;
        }
    };
    //用于路径记录的结构体
    struct chgPath {
        int edgeFrom; // 此节点来自哪条边
        int pathFrom; // 此节点来自哪个路径记录节点
        chgPath(int e, int p) {
            edgeFrom = e;
            pathFrom = p;
        }
    };

    // 优先队列
    std::priority_queue<chgNode> q;
    // 访问记录 某个点未访问为-1，访问过记录换乘数
    QVector<int> vis(vMaxId + 1, -1);
    // 路径记录 某个搜索节点来自哪条边和哪个路径记录节点
    QVector<chgPath> path;
    // 路径 顺序边记录
    QVector<int> ans;
    // 起点
    chgNode startNode;
    startNode.v      = from;
    startNode.change = 0;
    startNode.l      = -1;
    startNode.edgeFrom = -2;
    startNode.pathFrom = -1;
    q.push(startNode);

    while (!q.empty()) {
        chgNode curNode = q.top();
        q.pop();

        // 判断是否拓展
        //换乘具有特殊性，到达同一点可能位于不同线路，因此相等情况不能直接跳过
        if (vis[curNode.v] != -1 && curNode.change > vis[curNode.v])
            continue;
        else {
            vis[curNode.v] = curNode.change;

            chgPath nowPath(curNode.edgeFrom, curNode.pathFrom);
            path.append(nowPath);
        }

        if (curNode.v == to) {
            // 找到终点 计算路径
            int curPathId = path.size() - 1;
            int edgeFrom  = path[curPathId].edgeFrom;

            while (path[curPathId].pathFrom != -1) {
                ans.push_back(edgeFrom);
                curPathId = path[curPathId].pathFrom;
                edgeFrom = path[curPathId].edgeFrom;
            }
            std::reverse(ans.begin(), ans.end());
            break;
        }

        // 拓展节点
        for (int i = vInfo[curNode.v].posFirst; i != -1; i = posList[i]) {
            QSet nextLine = eInfo[i].getLineSet();
            chgNode nextNode;
            for (int l : nextLine) {
                nextNode.v        = eInfo[i].to;
                nextNode.l        = l;
                nextNode.edgeFrom = i;
                nextNode.pathFrom = path.size() - 1;
                if (curNode.l != l)
                    nextNode.change = curNode.change + 1;
                else
                    nextNode.change = curNode.change;
                q.push(nextNode);
            }
        }
    }

    return ans;
}

QString AbstractGraph::pathToText(QVector<int> path)
{
    if (path.size() == 0)
        return "无路可走";

    qreal distance = eInfo[path[0]].weight;

    QSet<int> line = eInfo[path[0]].getLineSet();
    int change = 0;

    QString text;

    for (int i = 1; i < path.size(); ++i) {
        int e = path[i];
        distance += eInfo[e].weight;

        //换乘检测
        QSet<int> nextLine = eInfo[path[i]].getLineSet();
        const QSet<int> copyLine = line;

        for (int l : copyLine) {
            //若无法接着走，选择换乘
            if (nextLine.find(l) == nextLine.end()) {
                if (line.size() >= 2)
                    line.remove(l);
                else {
                    //进行换乘 输出文本
                    text += QString::number(change + 1);
                    text += ": 换乘 ";
                    bool huo = false;
                    for (int t : copyLine) {
                        if (copyLine.size() >= 2) {
                            if (huo)
                                text += " 或 ";
                            else
                                huo = true;
                        }
                        text += lInfo[t].name;
                    }
                    text += " 至 ";
                    text += vInfo[eInfo[e].from].sationAt->name;
                    text += ";\n";

                    line = nextLine;
                    ++change;
                }
            }
        }
    }

    //最后一站
    text += QString::number(change + 1);
    text += ": 换乘 ";
    bool huo = false;
    for (int t : line) {
        if (line.size() >= 2) {
            if (huo)
                text += " 或 ";
            else
                huo = true;
        }
        text += lInfo[t].name;
    }
    text += " 至 ";
    text += vInfo[eInfo[path[path.size() - 1]].to].sationAt->name;
    text += ";\n";


    text += "总路程公里: ";
    text += QString::number(distance);
    text += ",总换乘次数: ";
    text += QString::number(change);

    return text;
}

void MyGraphicsView::setNewSelected(QGraphicsItem* newSelectItem) {
    if (newSelectItem) {
        newSelectItem->setSelected(true);

        // 发出更新信息
        if (newSelectItem->type() == myType::mySationItem) {
            MySationItem* sation = (MySationItem*)newSelectItem;
            emit showSationInfo(sation->id, sation->name, sation->size,
                                sation->getCenter());
        } else if (newSelectItem->type() == myType::myEdgeItem) {
            MyEdgeItem* edge = (MyEdgeItem*)newSelectItem;
            int id = edge->id;
            QString line0, line1;
            line0 = tupo.lInfo[tupo.eInfo[id].belongLine[0]].name;
            line1 = tupo.lInfo[tupo.eInfo[id].belongLine[1]].name;

            emit showEdgeInfo(id, tupo.eInfo[id].weight, edge->style,
                              tupo.eInfo[id].from, tupo.eInfo[id].to, line0,
                              line1);
        }

        SELECTED = true;
        if (selectItem && newSelectItem != selectItem) {
            selectItem->setSelected(false);
        }
        selectItem = newSelectItem;
    } else {
        SELECTED = false;

        // 发出无需显示信息
        emit unshow();

        if (selectItem) {
            selectItem->setSelected(false);
        }
        selectItem = newSelectItem;
    }
}

MyGraphicsView::MyGraphicsView(QWidget* parent) : QGraphicsView{parent} {
    myGraphicsScene = new QGraphicsScene(parent);

    this->setScene(myGraphicsScene);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->setSceneRect(this->rect());
    this->centerOn(0, 0);

    // this->setMouseTracking(true);

    // 无滑轮
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 抗锯齿
    this->setRenderHint(QPainter::Antialiasing);

    // 指针
    this->setCursor(backModeCurser());

    // this->show();
}

enum Qt::CursorShape MyGraphicsView::backModeCurser() {
    if (mode == Edit)
        return Qt::CrossCursor;
    else
        return Qt::ArrowCursor;
}

void MyGraphicsView::changeToUse()
{
    for (vNode v : tupo.vInfo) {
        if (v.isExist)
            v.sationAt->setFlag(QGraphicsItem::ItemIsMovable, false);
    }
    mode = MODE::Use;

}

void MyGraphicsView::changeToEdit()
{
    if (SHOWING) {
        for (int e : showPath) {
            tupo.eInfo[e].edgeAt->setChoosed(false);
        }
        showPath.clear();
        SHOWING = false;
    }
    for (vNode v : tupo.vInfo) {
        if (v.isExist)
            v.sationAt->setFlag(QGraphicsItem::ItemIsMovable);
    }
    mode = MODE::Edit;
}

MySationItem* MyGraphicsView::addSation(QPointF center) {
    MySationItem* newStation = tupo.addVex(center, 0, "未命名站点");
    myGraphicsScene->addItem(newStation);
    // 更改信号
    setEdited(true);
    return newStation;
}


void MyGraphicsView::setEdited(bool edited)
{
    if (edited ^ EDITED){
        EDITED = edited;
        emit sendSetTitleEdited(EDITED);
    }
}


MyGraphicsView::~MyGraphicsView() {
    myGraphicsScene->clear();
}

void MyGraphicsView::wheelEvent(QWheelEvent* event) {
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    QPointF cursorPoint = event->position();
#else
    QPointF cursorPoint = event->posF();
#endif
    QPointF scenePos =
        this->mapToScene(QPoint(cursorPoint.x(), cursorPoint.y()));

    qreal scaleFactor = this->transform().m11();
    int wheelDeltaValue = event->angleDelta().y();
    if (wheelDeltaValue > 0) {
        if (scaleFactor > 2)
            return;
        this->scale(1.1, 1.1);
    } else {
        if (scaleFactor < 0.5)
            return;
        this->scale(1.0 / 1.1, 1.0 / 1.1);
    }
    this->centerOn(scenePos);
}

void MyGraphicsView::mousePressEvent(QMouseEvent* event) {
    setNewSelected(nullptr);
    if (event->button() == Qt::RightButton) {
        onRightPress = true;
        lastPos = mapToScene(event->pos());
        setCursor(Qt::ClosedHandCursor);
    } else if (!onRightPress && event->button() == Qt::LeftButton) {
        QGraphicsItem* find = nullptr;
        QList<QGraphicsItem*> finds = this->items(event->pos());
        foreach (QGraphicsItem* i, finds) {
            if (i && (i->type() == myType::mySationItem ||
                      i->type() == myType::myEdgeItem)) {
                find = i;
                break;
            }
        }

        if (find) {
            //如果正在某线路下点击边,进行线路增删
            if (mode == MODE::Edit && currentLine != 0 && find->type() == myType::myEdgeItem){
                MyEdgeItem* edge = (MyEdgeItem*)find;
                if (edge->CHOOSED){
                    tupo.edgeDeleteFromLine(edge->id, currentLine);
                    edge->setChoosed(false);
                    edge->reSetStyle();
                }
                else {
                    if (tupo.edgeAddToLine(edge->id, currentLine) != -1){
                        edge->setChoosed(true);
                        edge->reSetStyle();
                    }
                }
            }

            // 正在点击图元设置选中
            onLeftPress = true;
            setCursor(Qt::ClosedHandCursor);
            setNewSelected(find);

        } else {
            if (mode == MODE::Edit) {
                // 去除选中，产生新点
                MySationItem* newStation = addSation(mapToScene(event->pos()));
                setNewSelected(newStation);
            }
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    if (onRightPress && !(event->buttons() & Qt::RightButton)) {
        onRightPress = false;
        setCursor(backModeCurser());
    }
    if (onLeftPress && !(event->buttons() & Qt::LeftButton)) {
        onLeftPress = false;
        setCursor(backModeCurser());
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    if (mode == MODE::Edit && SELECTED && onLeftPress && selectItem->type() == myType::mySationItem) {
        // 发出更新信息
        MySationItem* sation = (MySationItem*)selectItem;
        emit showSationInfo(sation->id, sation->name, sation->size,
                            sation->getCenter());
    }
    if (onRightPress) {
        QPointF dp = mapToScene(event->pos()) - lastPos;
        setSceneRect(sceneRect().x() - dp.x(), sceneRect().y() - dp.y(),
                     sceneRect().width(), sceneRect().height());
        lastPos = mapToScene(event->pos());
    }
    QGraphicsView::mouseMoveEvent(event);
}

void MyGraphicsView::checkAddEdge(int from, int to, int style, qreal weight) {
    QMessageBox message(this);
    message.setWindowTitle("警告");
    message.setIconPixmap(QPixmap(":/icon/img/warn.png"));

    if (!tupo.checkExist(from, to)) {
        message.setText("指定的点不存在");
        message.exec();
        return;
    }

    if (!tupo.checkNoLoop(from, to)) {
        message.setText("点到点不能有环");
        message.exec();
        return;
    }

    if (!tupo.checkNoRepetition(from, to)) {
        message.setText("刚刚添加了一条重边！确认是否必要");
        message.exec();
    }

    MyEdgeItem* newEdge = tupo.addEdge(from, to, (enum myShape)style, weight);
    newEdge->setZValue(-1);
    myGraphicsScene->addItem(newEdge);
    setEdited(true);
}

void MyGraphicsView::setSationName(int id, QString name) {
    tupo.vInfo[id].sationAt->name = name;
    tupo.vInfo[id].sationAt->text->setPlainText(name);
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::setSationCenter(int id, QPointF center) {
    MySationItem* sation = tupo.vInfo[id].sationAt;
    sation->rePaint(center);
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::setSationSize(int id, int size) {
    MySationItem* sation = tupo.vInfo[id].sationAt;
    QPointF center = sation->getCenter();
    sation->size = size;
    sation->rePaint(center);
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::setEdgeWeight(int id, qreal weight) {
    tupo.setEdgeWeidght(id, weight);
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::setEdgeStyle(int id, int style) {
    tupo.eInfo[id].edgeAt->style = (enum myShape)style;
    tupo.eInfo[id].edgeAt->reSetPath();
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::replyAddLine(QString name, QColor color, int isCircle)
{
    int id = tupo.addLine(name, color, isCircle);
    emit sendReplyAddLine(id, name);
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::tellAddLine(int index, QString name)
{
    emit sendReplyAddLine(index, name);
}

void MyGraphicsView::replyLineChange(int id)
{
    //线路切换相关工作
    if (id != currentLine) {
        //通知信息
        if (id != 0)
            emit sendLineInfo(tupo.lInfo[id].name, tupo.lInfo[id].color, tupo.lInfo[id].isCircle);
        //切换工作
        //清除旧的
        if (SHOWING) {
            for (int e : showPath) {
                tupo.eInfo[e].edgeAt->setChoosed(false);
            }
            showPath.clear();
            SHOWING = false;
        }
        for (int e : tupo.lInfo[currentLine].contain){
            tupo.eInfo[e].edgeAt->setChoosed(false);
        }
        //标记新的
        for (int e : tupo.lInfo[id].contain){
            tupo.eInfo[e].edgeAt->setChoosed(true);
        }
        currentLine = id;
    }
}

void MyGraphicsView::setLineInfo(int id, QString name, QColor color, int isCircle)
{
    QColor oldColor = tupo.lInfo[id].color;
    tupo.setLineInfo(id, name, color, isCircle);

    if (oldColor != color){
        for (int e : tupo.lInfo[id].contain) {
            tupo.eInfo[e].edgeAt->reSetStyle();
        }
    }
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::deleteLine(int id)
{
    //取消标记
    currentLine = 0;
    for (int e : tupo.lInfo[id].contain) {
        tupo.eInfo[e].edgeAt->CHOOSED = false;
    }
    tupo.deleteLine(id);
    // 更改信号
    setEdited(true);
}

void MyGraphicsView::replySave(QString filePath)
{
    tupo.save(filePath);
    setEdited(false);
}

void MyGraphicsView::replyOther(QString otherPath)
{
    tupo.save(otherPath);
}

void MyGraphicsView::replyRead(QString filePath)
{
    tupo.read(filePath);
}

void MyGraphicsView::replyLowDistance(int from, int to)
{
    QMessageBox message(this);
    message.setWindowTitle("警告");
    message.setIconPixmap(QPixmap(":/icon/img/warn.png"));

    if (!tupo.checkExist(from, to)) {
        message.setText("指定的点不存在");
        message.exec();
        return;
    }

    if (!tupo.checkNoLoop(from, to)) {
        message.setText("已经到了");
        message.exec();
        return;
    }

    if (SHOWING) {
        for (int e : showPath) {
            tupo.eInfo[e].edgeAt->setChoosed(false);
        }
        showPath.clear();
        SHOWING = false;
    }

    // 调用查找函数
    showPath = tupo.lowDistance(from, to);
    // 标亮查找到的边
    for (int e : showPath) {
        tupo.eInfo[e].edgeAt->setChoosed(true);
    }
    SHOWING = true;
    // 回复文本
    QString info = "起点站: " + tupo.vInfo[from].sationAt->name + ",终点站: " + tupo.vInfo[to].sationAt->name + "\n";
    emit sendPathText(info + tupo.pathToText(showPath));
}

void MyGraphicsView::replyLowChange(int from, int to)
{
    QMessageBox message(this);
    message.setWindowTitle("警告");
    message.setIconPixmap(QPixmap(":/icon/img/warn.png"));

    if (!tupo.checkExist(from, to)) {
        message.setText("指定的点不存在");
        message.exec();
        return;
    }

    if (!tupo.checkNoLoop(from, to)) {
        message.setText("已经到了");
        message.exec();
        return;
    }

    if (SHOWING) {
        for (int e : showPath) {
            tupo.eInfo[e].edgeAt->setChoosed(false);
        }
        showPath.clear();
        SHOWING = false;
    }

    // 调用查找函数
    showPath = tupo.lowChange(from, to);
    // 标亮查找到的边
    for (int e : showPath) {
        tupo.eInfo[e].edgeAt->setChoosed(true);
    }
    SHOWING = true;

    // 回复文本
    QString info = "起点站: " + tupo.vInfo[from].sationAt->name + ",终点站: " + tupo.vInfo[to].sationAt->name + "\n";
    emit sendPathText(info + tupo.pathToText(showPath));
}



/*------------------------------MySationItem------------------------------*/

MySationItem::MySationItem(int id,
                           QPointF center,
                           int size,
                           QString name,
                           MyGraphicsView* view)
    : QGraphicsEllipseItem() {
    this->id = id;
    this->size = size;
    this->name = name;
    this->view = view;

    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsScenePositionChanges);

    setPen(myPen);
    // 画刷 - 背景色
    setBrush(myBrush);

    setRect(QRect(center.x() - sizeToRadius[size],
                  center.y() - sizeToRadius[size], 2 * sizeToRadius[size],
                  2 * sizeToRadius[size]));
    // 文字
    this->text = new QGraphicsTextItem(name, this);
    text->setFont(myFont);
    text->setPos(this->rect().x() + 2 * sizeToRadius[size],
                 this->rect().y() - sizeToRadius[size] - fontSize - 2);
}

MySationItem::~MySationItem()
{
    if (text)
        delete text;
}

void MySationItem::rePaint(QPointF center) {
    setRect(QRect(-sizeToRadius[size], -sizeToRadius[size],
                  2 * sizeToRadius[size], 2 * sizeToRadius[size]));
    setPos(center.x(), center.y());
    // 文字
    text->setPlainText(name);
    text->setPos(this->rect().x() + 2 * sizeToRadius[size],
                 this->rect().y() - sizeToRadius[size] - fontSize - 2);
    itemChange(ItemScenePositionHasChanged, QVariant());
}

QVariant MySationItem::itemChange(GraphicsItemChange change,
                                  const QVariant& value) {
    if (change == ItemScenePositionHasChanged) {
        for (int e = view->tupo.vInfo[id].posFirst; e != -1;
             e = view->tupo.posList[e])
            view->tupo.eInfo[e].edgeAt->reSetPath();
        for (int e = view->tupo.vInfo[id].invFirst; e != -1;
             e = view->tupo.invList[e])
            view->tupo.eInfo[e].edgeAt->reSetPath();
        // 更改信号
        view->setEdited(true);
    }
    return QGraphicsItem::itemChange(change, value);
}

QPointF MySationItem::getCenter() {
    return mapToScene(rect().center());
}

/*------------------------------MyEdgeItem------------------------------*/
MyEdgeItem::MyEdgeItem(int id, enum myShape style, MyGraphicsView* view)
    : QGraphicsPathItem() {
    this->id = id;
    this->view = view;
    this->style = style;

    secondLine = new QGraphicsPathItem(this);

    setFlag(ItemIsSelectable);
    setFlag(ItemIsMovable, false);

    reSetStyle();
    reSetPath();
}

void MyEdgeItem::reSetStyle() {
    // 颜色
    QColor color0 = view->tupo.lInfo[view->tupo.eInfo[id].belongLine[0]].color;
    QColor color1 = view->tupo.lInfo[view->tupo.eInfo[id].belongLine[1]].color;
    Qt::PenStyle style = Qt::SolidLine;

    if (CHOOSED)
        style = Qt::DashLine;

    switch (view->tupo.eInfo[id].getLineNum()) {
        case 0:
            break;
        case 1:
            if (view->tupo.eInfo[id].belongLine[0])
                color1 = color0;
            else
                color0 = color1;
            break;
        case 2:
            break;
        default:
            break;
    }
    this->setPen(QPen(color0, myPenWidth / 2, style));
    secondLine->setPen(QPen(color1, myPenWidth / 2, style));
}

void MyEdgeItem::reSetPath() {
    // 获取起点和终点
    QPointF startCenter =
        view->tupo.vInfo[view->tupo.eInfo[id].from].sationAt->getCenter();
    QPointF endCenter =
        view->tupo.vInfo[view->tupo.eInfo[id].to].sationAt->getCenter();

    QPainterPath pathL;
    QPainterPath pathR;

    switch((int)style){
    case (int)myShape::straight:{
        // 线样式
        qreal len = sqrt(
            (startCenter.x() - endCenter.x()) * (startCenter.x() - endCenter.x()) +
            (startCenter.y() - endCenter.y()) * (startCenter.y() - endCenter.y()));
        qreal sina = (endCenter.x() - startCenter.x()) / len;
        qreal cosa = (endCenter.y() - startCenter.y()) / len;
        // 一直线
        QPointF startL = QPointF(startCenter.x() - edgeSpace * cosa,
                                 startCenter.y() + edgeSpace * sina);
        QPointF endL = QPointF(endCenter.x() - edgeSpace * cosa,
                               endCenter.y() + edgeSpace * sina);
        QPointF leftArrowPos = (startL + endL * 2) / 3;
        pathL.moveTo(startL);
        pathL.lineTo(endL);
        // 加左箭头
        QPointF leftArrowEnd =
            QPointF(leftArrowPos.x() - (sina * cos(arrowAngle) - cosa * sin(arrowAngle)) * arrowLength,
                    leftArrowPos.y() - (cosa * cos(arrowAngle) + sina * sin(arrowAngle)) * arrowLength);
        pathL.moveTo(leftArrowEnd);
        pathL.lineTo(leftArrowPos);
        // this->setPath(pathL);

        // 二直线
        QPointF startR =
            QPointF(startCenter.x() - (edgeSpace + myPenWidth / 2) * cosa,
                    startCenter.y() + (edgeSpace + myPenWidth / 2) * sina);
        QPointF endR = QPointF(endCenter.x() - (edgeSpace + myPenWidth / 2) * cosa,
                               endCenter.y() + (edgeSpace + myPenWidth / 2) * sina);
        QPointF rightArrowPos = (startR + endR * 2) / 3;
        pathR.moveTo(startR);
        pathR.lineTo(endR);
        // 加右箭头
        QPointF rightArrowEnd =
            QPointF(rightArrowPos.x() - (sina * cos(arrowAngle) + cosa * sin(arrowAngle)) * arrowLength,
                    rightArrowPos.y() - (cosa * cos(arrowAngle) - sina * sin(arrowAngle)) * arrowLength);
        pathR.moveTo(rightArrowEnd);
        pathR.lineTo(rightArrowPos);
        secondLine->setPath(pathR);

        // 碰撞范围
        pathL.addPath(pathR);
        this->setPath(pathL);
    }
        break;

    case (int)myShape::cross_down: {
        //先横后竖
        // 一折线
        QPointF startL;
        if (startCenter.x() < endCenter.x())
            startL = QPointF(startCenter.x(), startCenter.y() + edgeSpace);
        else
            startL = QPointF(startCenter.x(), startCenter.y() - edgeSpace);

        QPointF endL;
        if (startCenter.y() < endCenter.y())
            endL = QPointF(endCenter.x() - edgeSpace, endCenter.y());
        else
            endL = QPointF(endCenter.x() + edgeSpace, endCenter.y());

        QPointF midL = QPointF(endL.x(), startL.y());

        QPointF leftArrowPos = (midL + endL) / 2;
        pathL.moveTo(startL);
        pathL.lineTo(midL);
        pathL.moveTo(midL);
        pathL.lineTo(endL);
        // 加左箭头
        qreal a;
        if (startCenter.y() < endCenter.y())
            a = M_PI / 2;
        else
            a = -M_PI / 2;

        QPointF leftArrowEnd =
            QPointF(leftArrowPos.x() - (cos(a) * cos(arrowAngle) - sin(a) * sin(arrowAngle)) * arrowLength,
                    leftArrowPos.y() - (sin(a) * cos(arrowAngle) + cos(a) * sin(arrowAngle)) * arrowLength);
        pathL.moveTo(leftArrowEnd);
        pathL.lineTo(leftArrowPos);
        // this->setPath(pathL);

        // 二折线
        QPointF startR;
        if (startCenter.x() < endCenter.x())
            startR = QPointF(startCenter.x(), startCenter.y() + (edgeSpace + myPenWidth / 2));
        else
            startR = QPointF(startCenter.x(), startCenter.y() - (edgeSpace + myPenWidth / 2));

        QPointF endR;
        if (startCenter.y() < endCenter.y())
            endR = QPointF(endCenter.x() - (edgeSpace + myPenWidth / 2), endCenter.y());
        else
            endR = QPointF(endCenter.x() + (edgeSpace + myPenWidth / 2), endCenter.y());

        QPointF midR = QPointF(endR.x(), startR.y());

        QPointF rightArrowPos = (midR + endR) / 2;
        rightArrowPos.setY(leftArrowPos.y());
        pathR.moveTo(startR);
        pathR.lineTo(midR);
        pathR.moveTo(midR);
        pathR.lineTo(endR);

        // 加右箭头
        QPointF rightArrowEnd =
            QPointF(rightArrowPos.x() - (cos(a) * cos(arrowAngle) + sin(a) * sin(arrowAngle)) * arrowLength,
                    rightArrowPos.y() - (sin(a) * cos(arrowAngle) - cos(a) * sin(arrowAngle)) * arrowLength);
        pathR.moveTo(rightArrowEnd);
        pathR.lineTo(rightArrowPos);
        secondLine->setPath(pathR);

        // 碰撞范围
        pathL.addPath(pathR);
        this->setPath(pathL);
    }
        break;

    case (int)myShape::down_cross: {
        //先横后竖
        // 一折线
        QPointF startL;
        if (startCenter.y() < endCenter.y())
            startL = QPointF(startCenter.x() - edgeSpace, startCenter.y());
        else
            startL = QPointF(startCenter.x() + edgeSpace, startCenter.y());

        QPointF endL;
        if (startCenter.x() < endCenter.x())
            endL = QPointF(endCenter.x(), endCenter.y() + edgeSpace);
        else
            endL = QPointF(endCenter.x(), endCenter.y() - edgeSpace);

        QPointF midL = QPointF(startL.x(), endL.y());

        QPointF leftArrowPos = (midL + endL) / 2;
        pathL.moveTo(startL);
        pathL.lineTo(midL);
        pathL.moveTo(midL);
        pathL.lineTo(endL);
        // 加左箭头
        qreal a;
        if (startCenter.x() < endCenter.x())
            a = 0;
        else
            a = M_PI;

        QPointF leftArrowEnd =
            QPointF(leftArrowPos.x() - (cos(a) * cos(arrowAngle) - sin(a) * sin(arrowAngle)) * arrowLength,
                    leftArrowPos.y() - (sin(a) * cos(arrowAngle) + cos(a) * sin(arrowAngle)) * arrowLength);
        pathL.moveTo(leftArrowEnd);
        pathL.lineTo(leftArrowPos);
        // this->setPath(pathL);

        // 二折线
        QPointF startR;
        if (startCenter.y() < endCenter.y())
            startR = QPointF(startCenter.x() - (edgeSpace + myPenWidth / 2), startCenter.y());
        else
            startR = QPointF(startCenter.x() + (edgeSpace + myPenWidth / 2), startCenter.y());

        QPointF endR;
        if (startCenter.x() < endCenter.x())
            endR = QPointF(endCenter.x(), endCenter.y() + (edgeSpace + myPenWidth / 2));
        else
            endR = QPointF(endCenter.x(), endCenter.y() - (edgeSpace + myPenWidth / 2));

        QPointF midR = QPointF(startR.x(), endR.y());

        QPointF rightArrowPos = (midR + endR) / 2;
        rightArrowPos.setX(leftArrowPos.x());
        pathR.moveTo(startR);
        pathR.lineTo(midR);
        pathR.moveTo(midR);
        pathR.lineTo(endR);
        // 加右箭头
        QPointF rightArrowEnd =
            QPointF(rightArrowPos.x() - (cos(a) * cos(arrowAngle) + sin(a) * sin(arrowAngle)) * arrowLength,
                    rightArrowPos.y() - (sin(a) * cos(arrowAngle) - cos(a) * sin(arrowAngle)) * arrowLength);
        pathR.moveTo(rightArrowEnd);
        pathR.lineTo(rightArrowPos);
        secondLine->setPath(pathR);

        // 碰撞范围
        pathL.addPath(pathR);
        this->setPath(pathL);
    }
        break;

    }
}

void MyEdgeItem::setChoosed(bool choosed)
{
    if (CHOOSED ^ choosed) {
        CHOOSED = choosed;
        reSetStyle();
    }
}
