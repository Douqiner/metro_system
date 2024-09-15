#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    f = new QFileDialog(this);
    f->setAcceptMode(QFileDialog::AcceptOpen);
    f->setFileMode(QFileDialog::ExistingFile);
    f->setNameFilter("地铁线路文件 (*.mtr)");
    f->setWindowTitle("打开现有文件");
    connect(f, &QFileDialog::accepted, this, &StartWindow::open_existing_file);
}

StartWindow::~StartWindow()
{
    delete ui;
    delete f;
}

void StartWindow::on_pbtn_open_clicked()
{
    f->exec();
}

void StartWindow::on_pbtn_create_clicked()
{
    the_w_main->setWindowTitle("无标题");
    filePath = "";
    the_w_main->show();
    the_w_main->showMaximized();
    this->close();
}

void StartWindow::open_existing_file()
{
    // f->selectedUrls();
    if (f->selectedFiles().count() == 1)
    {
        filePath = f->selectedFiles().at(0);
        the_w_main->setWindowTitle(filePath);
        the_w_main->askRead();
        the_w_main->show();
        the_w_main->showMaximized();
        this->close();
    }
}
