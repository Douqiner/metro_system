#include "side_tool_edit.h"
#include "ui_side_tool_edit.h"

SideToolEdit::SideToolEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SideToolEdit)
{
    ui->setupUi(this);

    ui->lineBox->addItem("未选择", 0);

    //颜色
    colorButton = new myColorBotton(this);
    colorButton->setText("颜色");
    ui->horizontalLayout_6->addWidget(colorButton);

    colorDialog = new QColorDialog(this);
    colorDialog->setWindowTitle("选择颜色");

    connect(colorButton, &myColorBotton::clicked, this, &SideToolEdit::send_to_dialog);
    connect(colorDialog, &QColorDialog::accepted, this, &SideToolEdit::send_to_button);

    //信息栏
    information = new QStackedWidget(this);
    infoSation = new InfoSation(information);
    infoEdge = new InfoEdge(information);

    information->addWidget(infoSation);
    information->addWidget(infoEdge);
    // information->setMaximumWidth(260);


    ui->verticalLayout_2->addWidget(information);
    information->hide();

    //添加边
    connect(ui->addEdgeButton, &QPushButton::clicked, this, &SideToolEdit::addEdge);
    //线路请求
    connect(ui->addLineButton, &QPushButton::clicked, this, &SideToolEdit::askAddLine);
    connect(ui->lineBox, &QComboBox::currentIndexChanged, this, &SideToolEdit::askLineChange);
    connect(ui->nameEdit, &QLineEdit::editingFinished, this, &SideToolEdit::askSetLineInfo);
    connect(ui->circleCheck, &QCheckBox::checkStateChanged, this, &SideToolEdit::askSetLineInfo);
    connect(ui->deleteLineButton, &QPushButton::clicked, this, &SideToolEdit::askDeleteLine);
    //查询请求
    connect(ui->lowDistanceButton, &QPushButton::clicked, this, &SideToolEdit::askLowDistancePath);
    connect(ui->lowChangeButton, &QPushButton::clicked, this, &SideToolEdit::askLowChangePath);
    //提示
    connect(ui->tipsButton, &QPushButton::clicked, this, &SideToolEdit::showTips);
}

SideToolEdit::~SideToolEdit()
{
    delete ui;
}

void SideToolEdit::setModeEdit()
{
    ui->useBox->setVisible(false);
    ui->addEdgeGroup->setVisible(true);

    //信息栏
    infoSation->setModeEdit();
    infoEdge->setModeEdit();

    //线路栏
    ui->addLineButton->setVisible(true);
    ui->deleteLineButton->setVisible(true);
    colorButton->setEnabled(true);
    ui->circleCheck->setEnabled(true);
    ui->nameEdit->setReadOnly(false);

}

void SideToolEdit::setModeUse()
{
    ui->addEdgeGroup->setVisible(false);
    ui->useBox->setVisible(true);

    //信息栏
    infoSation->setModeUse();
    infoEdge->setModeUse();

    //线路栏
    ui->addLineButton->setVisible(false);
    ui->deleteLineButton->setVisible(false);
    colorButton->setEnabled(false);
    ui->circleCheck->setEnabled(false);
    ui->nameEdit->setReadOnly(true);

}

void SideToolEdit::send_to_dialog()
{
    QColor from_btn(colorButton->r, colorButton->g, colorButton->b);
    colorDialog->setCurrentColor(from_btn);
    colorDialog->exec();
}

void SideToolEdit::send_to_button()
{
    QColor from_dlg = colorDialog->currentColor();
    colorButton->set_rgb(from_dlg.red(), from_dlg.green(), from_dlg.blue());

    int id = ui->lineBox->currentData().toInt();
    if (id != 0)
        emit sendAskSetLineInfo(id, ui->nameEdit->text(), QColor(colorButton->r, colorButton->g, colorButton->b), ui->circleCheck->isChecked());
}

void SideToolEdit::setInfoSation(int id, QString name, int size, QPointF center)
{
    infoSation->setInfo(id, name, size, center);
    information->setCurrentIndex(0);
    information->show();
    ui->addEdgeButton->setEnabled(true);
}

void SideToolEdit::setInfoEdge(int id, qreal weight, int style, int from, int to, QString line0, QString line1)
{
    infoEdge->setInfo(id, weight, style, from, to, line0, line1);
    information->setCurrentIndex(1);
    information->show();
    ui->addEdgeButton->setEnabled(false);
}

void SideToolEdit::setInfoClose()
{
    information->hide();
    ui->addEdgeButton->setEnabled(false);
}

void SideToolEdit::addLine(int index, QString name)
{
    ui->lineBox->addItem(name, index);
}

void SideToolEdit::lineChange(QString name, QColor color, int isCircle)
{
    ui->nameEdit->setText(name);
    colorButton->set_rgb(color.red(), color.green(), color.blue());
    ui->circleCheck->setChecked(isCircle);
}

void SideToolEdit::setPathText(QString way)
{
    ui->wayTextEdit->setPlainText(way);
}

void SideToolEdit::showTips()
{
    QMessageBox message(this);
    message.setWindowTitle("提示");
    message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
    message.setText("模式：编辑模式和查询模式\n\n"
                    "操作：左键单击空白添加站点，点或边则选中查看信息\n"
                    "可以修改部分信息；左键拖动站点，滚轮放缩，右键拖动界面\n"
                    "选中点时，才可以根据此点添加边\n"
                    "未选择线路时才可以添加线路，选中线路时将线路虚线标出\n"
                    "可以修改线路信息，单击边设置边是否属于这条线路\n"
                    "查询时将路线虚线标出\n\n"
                    "注意：直接关闭不会提示未保存\n"
                    "准备了上海的线路图参考\n\n"
                    "一个好的地铁图：\n"
                    "线路本质是边的集合，请保证线路是一条单向不分支路径\n"
                    "一般日常称线路是由两个方向的线路组成\n"
                    "如果有分支线路，可以一条边设置花桥和嘉定北方向两条线路\n"
                    "尽量不要重边，一条边可设置3号线4号线，而且它们确实是一个隧道\n"
                    "除非边权确实不同，设置不同边形避免图形重叠\n"
                    "一般没有三条线路共用一个隧道的情况，如果有，那就重边吧");
    message.exec();
}

void SideToolEdit::addEdge()
{
    if(!(information->isVisible() && information->currentIndex() == 0))
        return;

    int from, to;
    if (ui->directBox->currentIndex() == 0) {
        from = infoSation->id;
        to = ui->vexBox->value();
    }
    else {
        from = ui->vexBox->value();
        to = infoSation->id;
    }

    emit sendAddEdge(from, to, ui->styleBox->currentIndex(), ui->lengthSpinBox->value());
}

void SideToolEdit::askAddLine()
{
    if (ui->lineBox->currentData().toInt() == 0){
        if (ui->nameEdit->text().isEmpty()){
            QMessageBox message(this);
            message.setWindowTitle("警告");
            message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
            message.setText("线路名称不能为空");
            message.exec();
            return;
        }
        emit sendAskAddLine(ui->nameEdit->text(), QColor(colorButton->r, colorButton->g, colorButton->b), ui->circleCheck->isChecked());

    }
}

void SideToolEdit::askLineChange()
{
    int id = ui->lineBox->currentData().toInt();
    emit sendAskLineChange(id);

}

void SideToolEdit::askSetLineInfo()
{
    int id = ui->lineBox->currentData().toInt();
    if (id != 0){
        ui->lineBox->setItemText(ui->lineBox->currentIndex(), ui->nameEdit->text());
        emit sendAskSetLineInfo(id, ui->nameEdit->text(), QColor(colorButton->r, colorButton->g, colorButton->b), ui->circleCheck->isChecked());
    }
}

void SideToolEdit::askDeleteLine()
{
    int id = ui->lineBox->currentData().toInt();
    if (id != 0){
        //自身删除
        int lastIndex = ui->lineBox->currentIndex();
        ui->lineBox->setCurrentIndex(0);
        ui->lineBox->removeItem(lastIndex);
        //通知删除
        emit sendAskDeleteLine(id);
    }
}

void SideToolEdit::askLowDistancePath()
{
    ui->lineBox->setCurrentIndex(0);
    emit sendAskLineChange(0);
    emit sendAskLowDistancePath(ui->useStartBox->value(), ui->useEndBox->value());
}

void SideToolEdit::askLowChangePath()
{
    ui->lineBox->setCurrentIndex(0);
    emit sendAskLineChange(0);
    emit sendAskLowChangePath(ui->useStartBox->value(), ui->useEndBox->value());
}
