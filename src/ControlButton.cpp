//
// Created by Patryk Knapik on 02.04.2018.
//

#include "inc/ControlButton.h"

ControlButton::~ControlButton() = default;

ControlButton::ControlButton(const QString &labelText, QWidget *parent) : QPushButton(labelText, parent) {
    setFixedSize(250, 60);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
}
