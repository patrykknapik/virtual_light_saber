#include <QApplication>
#include <QWindow>
#include <QDebug>
#include "inc/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication mojaAppka(argc, argv);
    MainWindow mWindow;
    mWindow.setTitle(QString("6 Ścian"));
    mWindow.resize(640, 480);
    mWindow.show();

    return mojaAppka.exec();
}