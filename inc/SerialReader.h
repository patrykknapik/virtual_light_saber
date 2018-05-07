//
// Created by Patryk Knapik on 15.04.2018.
//

#ifndef DESKTOPAPP_SERIALREADER_H
#define DESKTOPAPP_SERIALREADER_H


#include <QObject>
#include <QSerialPort>
#include <QDebug>
#include <QSerialPortInfo>
#include "inc/DataTypes.h"

class SerialReader : public QObject {
Q_OBJECT

public:
    explicit SerialReader(QObject *parent = nullptr);

    ~SerialReader() = default;

private:
    QSerialPort *serialPort;

private slots:

    void readData();

    void error(QSerialPort::SerialPortError error);

public slots:

    void connectToPort(QSerialPortInfo portInfo);

signals:

    void newData(MemsData::rawData data);

    void connectionError();

};


#endif //DESKTOPAPP_SERIALREADER_H
