#include "mainwindow.h"
#include "startwindow.h"

#include <QApplication>

MainWindow* the_w_main;
QString filePath;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow s;
    s.show();
    MainWindow w;
    the_w_main = &w;

    return a.exec();
}
