#include <QApplication>
#include <QWindow>
#include <QDebug>
#include "inc/MainWindow.h"
#include "inc/ChartsWindow.h"
#include "inc/SettingsWindow.h"
#include "inc/SerialReader.h"
#include "inc/Calculator.h"

int main(int argc, char *argv[]) {

    QApplication myApp(argc, argv);
    MainWindow mWindow;
    ChartsWindow charts;
    SettingsWindow settings;
    SerialReader reader;
    Calculator calc;

    QObject::connect(&mWindow, SIGNAL(invokeCharts()), &charts, SLOT(raise()));
    QObject::connect(&mWindow, SIGNAL(invokeCharts()), &charts, SLOT(showNormal()));
    QObject::connect(&mWindow, SIGNAL(invokeSettings()), &settings, SLOT(show()));
    QObject::connect(&mWindow, SIGNAL(resetPosition()), &calc, SLOT(reset()));
    QObject::connect(&mWindow, SIGNAL(quitApp()), &myApp, SLOT(quit()));
    QObject::connect(&settings, SIGNAL(newSerialPort(QSerialPortInfo)), &mWindow, SLOT(setSerialPort(QSerialPortInfo)));
    QObject::connect(&settings, SIGNAL(newSerialPort(QSerialPortInfo)), &reader, SLOT(connectToPort(QSerialPortInfo)));
    QObject::connect(&reader, SIGNAL(newData(MemsData::rawData)), &mWindow, SLOT(rawData(MemsData::rawData)));
    QObject::connect(&reader, SIGNAL(newData(MemsData::rawData)), &calc, SLOT(rawData(MemsData::rawData)));
    QObject::connect(&calc, SIGNAL(newData(MemsData::posData)), &mWindow, SLOT(posData(MemsData::posData)));
    QObject::connect(&reader, SIGNAL(newData(MemsData::rawData)), &charts, SLOT(append(MemsData::rawData)));

    mWindow.show();


    return myApp.exec();
}