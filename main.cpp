#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{   //Main window
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
