//
// Created by Patryk Knapik on 02.04.2018.
//

#ifndef DESKTOPAPP_CONTROLBUTTON_H
#define DESKTOPAPP_CONTROLBUTTON_H
#define BOX_V_SIZE 150

#include <QPushButton>

class ControlButton : public QPushButton {
Q_OBJECT
public:
    explicit ControlButton(const QString &labelText, QWidget *parent = Q_NULLPTR);

    ~ControlButton();

};


#endif //DESKTOPAPP_CONTROLBUTTON_H
