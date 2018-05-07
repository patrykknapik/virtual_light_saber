//
// Created by Patryk Knapik on 23.04.2018.
//

#ifndef DESKTOPAPP_CALCULATOR_H
#define DESKTOPAPP_CALCULATOR_H

#include <QObject>
#include <inc/DataTypes.h>
#include "DataTypes.h"

class Calculator : public QObject {
Q_OBJECT

public:
    explicit Calculator(QObject *parent = nullptr) : QObject(parent), XGprev(0), ZGprev(0), YGprev(0) {}

    ~Calculator() = default;

    MemsData::posData output;
    MemsData::type XGprev;
    MemsData::type YGprev;
    MemsData::type ZGprev;

public slots:

    void rawData(MemsData::rawData data);

    void reset();

signals:

    void newData(MemsData::posData data);

};


#endif //DESKTOPAPP_CALCULATOR_H
