#include "mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QStringList>
#include <QApplication>
#include "mythread.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(400,200);
    w.show();
    return a.exec();
}
