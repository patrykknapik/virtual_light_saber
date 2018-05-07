//
// Created by Patryk Knapik on 23.04.2018.
//

#include <inc/DataTypes.h>
#include "inc/Calculator.h"


void Calculator::rawData(MemsData::rawData data) {

    output.Z_rot += ((data.Z_G + ZGprev) / 2000.0f) * (data.timeStamp / 1000.0f);// * (3,1416/180) ;
    ZGprev = data.Z_G;
    output.Y_rot += ((data.Y_G + YGprev) / 2000.0f) * (data.timeStamp / 1000.0f);// * (3,1416/180) ;
    YGprev = data.Y_G;
    output.X_rot += ((data.X_G + XGprev) / 1000.0f) * (data.timeStamp / 1000.0f);// * (3,1416/180) ;
    XGprev = data.X_G;
    output.Z_tran = 0L;
    output.Y_tran = 0;
    output.X_tran = 0;

    emit newData(output);
};

void Calculator::reset() {
    output.Z_rot = 0;
    output.Y_rot = 0;
    output.X_rot = 0;
    output.Z_tran = 0.0;
    output.Y_tran = 0.0;
    output.X_tran = 0.0;
}