//
// Created by Patryk Knapik on 02.04.2018.
//

#ifndef DESKTOPAPP_AXISLABEL_H
#define DESKTOPAPP_AXISLABEL_H


#include <QLabel>

class AxisLabel : public QLabel {
Q_OBJECT
public:
    explicit AxisLabel(const QString &labelText, QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags())
            : QLabel(labelText, parent, f) {

    }

    ~AxisLabel();
};


#endif //DESKTOPAPP_AXISLABEL_H
