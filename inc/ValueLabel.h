//
// Created by Patryk Knapik on 02.04.2018.
//

#ifndef DESKTOPAPP_VALUELABEL_H
#define DESKTOPAPP_VALUELABEL_H


#include <QLabel>

class ValueLabel : public QLabel {

Q_OBJECT
public:
    explicit ValueLabel(const QString &labelText, QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

    ~ValueLabel();
};


#endif //DESKTOPAPP_VALUELABEL_H
