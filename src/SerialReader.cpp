//
// Created by Patryk Knapik on 15.04.2018.
//

#include <inc/DataTypes.h>
#include "inc/SerialReader.h"

SerialReader::SerialReader(QObject *parent) : QObject(parent) {
    serialPort = nullptr;
}

void SerialReader::connectToPort(QSerialPortInfo portInfo) {
    if (serialPort != nullptr) {
        serialPort->close();
        disconnect(serialPort);
        delete serialPort;
    }

    serialPort = new QSerialPort(portInfo, this);
    //serialPort->setPortName(portInfo.portName());
    serialPort->setBaudRate(QSerialPort::Baud115200);

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
    //connect(serialPort,SIGNAL(errorOcurred(QSerialPort::SerialPortError)),this, SLOT(error(QSerialPort::SerialPortError)));
    serialPort->open(QIODevice::ReadOnly);
}

void SerialReader::readData() {
    MemsData::rawData data;
    QByteArray s;
    s = serialPort->readAll();
    QTextStream stream(s);
    stream >> data.X_XL >> data.Y_XL >> data.Z_XL >> data.X_G >> data.Y_G >> data.Z_G >> data.timeStamp;
    //qDebug() << s;
    if (stream.status() == QTextStream::Ok)
            emit newData(data);
}

void SerialReader::error(QSerialPort::SerialPortError error) {
    qDebug() << "Serial port error!: " << error << '\n';
    serialPort->clearError();
    emit connectionError();
}
