//
// Created by Patryk Knapik on 15.04.2018.
//

#ifndef DESKTOPAPP_MEMSRAWDATATYPES_H
#define DESKTOPAPP_MEMSRAWDATATYPES_H

#include <QObject>

namespace MemsData {
    typedef qint32 type;
    typedef struct {
        type X_XL, Y_XL, Z_XL, X_G, Y_G, Z_G, timeStamp;
    } rawData;
    typedef struct {
        type X_tran, Y_tran, Z_tran, X_rot, Y_rot, Z_rot;
    } posData;
    typedef struct {
        qint64 X_XLrange, Y_XLrange, X_Grange, Y_Grange;
    } range;

}


#endif //DESKTOPAPP_MEMSRAWDATATYPES_H
