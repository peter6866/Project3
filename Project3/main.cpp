#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1080,720);
    w.show();
    cout << "here" << endl;

    return a.exec();
}

