#include "info_sation.h"
#include "ui_info_sation.h"

InfoSation::InfoSation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoSation)
{
    ui->setupUi(this);

    //发出修改信息
    connect(ui->nameLineEdit, &QLineEdit::editingFinished, this, &InfoSation::setVexName);
    connect(ui->xSpinBox, &QSpinBox::editingFinished, this, &InfoSation::setVexCenter);
    connect(ui->ySpinBox, &QSpinBox::editingFinished, this, &InfoSation::setVexCenter);
    connect(ui->sizeBox, &QComboBox::currentIndexChanged, this, &InfoSation::setVexSize);
    connect(ui->deleteButton, &QPushButton::clicked, this, &InfoSation::deleteVex);
}

InfoSation::~InfoSation()
{
    delete ui;
}

void InfoSation::setInfo(int id, QString name, int size, QPointF center)
{
    ui->idLineEdit->setText(QString::number(id));
    this->id = id;
    ui->nameLineEdit->setText(name);
    ui->sizeBox->setCurrentIndex(size);
    ui->xSpinBox->setValue(center.x());
    ui->ySpinBox->setValue(center.y());
}

void InfoSation::setModeEdit()
{
    ui->nameLineEdit->setReadOnly(false);
    ui->sizeBox->setEnabled(true);
    ui->xSpinBox->setReadOnly(false);
    ui->ySpinBox->setReadOnly(false);
    ui->deleteButton->setVisible(true);
}

void InfoSation::setModeUse()
{
    ui->nameLineEdit->setReadOnly(true);
    ui->sizeBox->setEnabled(false);
    ui->xSpinBox->setReadOnly(true);
    ui->ySpinBox->setReadOnly(true);
    ui->deleteButton->setVisible(false);
}

void InfoSation::setVexName()
{
    emit sendSetVexName(this->id, ui->nameLineEdit->text());
}

void InfoSation::setVexCenter()
{
    emit sendSetVexCenter(this->id, QPointF(ui->xSpinBox->value(), ui->ySpinBox->value()));
}

void InfoSation::setVexSize()
{
    emit sendSetVexSize(this->id, ui->sizeBox->currentIndex());
}

void InfoSation::deleteVex()
{
    emit sendDeleteVex(this->id);
}
