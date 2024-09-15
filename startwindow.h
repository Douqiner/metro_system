#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <mainwindow.h>

#include <QWidget>
#include <QFileDialog>

extern MainWindow * the_w_main;
extern QString filePath;

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_pbtn_open_clicked();

    void on_pbtn_create_clicked();

    void open_existing_file();

private:
    Ui::StartWindow *ui;
    QFileDialog *f;
};

#endif // STARTWINDOW_H
