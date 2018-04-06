#include <QApplication>
#include <QWindow>
#include <QDebug>
#include "inc/MainWindow.h"
#include "inc/ChartsWindow.h"
#include "inc/SettingsWindow.h"

int main(int argc, char *argv[]) {
    QApplication myApp(argc, argv);
    MainWindow mWindow;
    ChartsWindow charts;
    SettingsWindow settings;

    QObject::connect(&mWindow, SIGNAL(invokeCharts()), &charts, SLOT(raise()));
    QObject::connect(&mWindow, SIGNAL(invokeCharts()), &charts, SLOT(showNormal()));
    QObject::connect(&mWindow, SIGNAL(invokeSettings()), &settings, SLOT(show()));
    QObject::connect(&mWindow, SIGNAL(quitApp()), &myApp, SLOT(quit()));

    qreal tmp[] = {1, 2, 3, 4, 5, 6};
    mWindow.rawData(tmp, &tmp[3]);
    mWindow.positionData(&tmp[3], tmp);
    charts.append(nullptr, nullptr);
    mWindow.show();


    return myApp.exec();
}