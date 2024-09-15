#include "info_edge.h"
#include "ui_info_edge.h"

InfoEdge::InfoEdge(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoEdge)
{
    ui->setupUi(this);

    //发出修改信息
    connect(ui->lengthSpinBox, &QDoubleSpinBox::editingFinished, this, &InfoEdge::setEdgeWeight);
    connect(ui->styleBox, &QComboBox::currentIndexChanged, this, &InfoEdge::setEdgeStyle);
    connect(ui->deleteButton, &QPushButton::clicked, this, &InfoEdge::deleteEdge);
}

InfoEdge::~InfoEdge()
{
    delete ui;
}

void InfoEdge::setInfo(int id, qreal weight, int style, int from, int to, QString line0, QString line1)
{
    ui->idLineEdit->setText(QString::number(id));
    this->id = id;
    ui->lengthSpinBox->setValue(weight);
    ui->styleBox->setCurrentIndex(style);
    ui->startSpinBox->setValue(from);
    ui->endSpinBox->setValue(to);
    ui->lineEdit0->setText(line0);
    ui->lineEdit1->setText(line1);
}

void InfoEdge::setModeEdit()
{
    ui->lengthSpinBox->setReadOnly(false);
    ui->styleBox->setEnabled(true);
    ui->deleteButton->setVisible(true);
}

void InfoEdge::setModeUse()
{
    ui->lengthSpinBox->setReadOnly(true);
    ui->styleBox->setEnabled(false);
    ui->deleteButton->setVisible(false);
}

void InfoEdge::setEdgeWeight()
{
    emit sendSetEdgeWeight(this->id, ui->lengthSpinBox->value());
}

void InfoEdge::setEdgeStyle()
{
    emit sendSetEdgeStyle(this->id, ui->styleBox->currentIndex());
}

void InfoEdge::deleteEdge()
{
    emit sendDeleteEdge(this->id);
}
