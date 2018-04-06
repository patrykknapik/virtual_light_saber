//
// Created by Patryk Knapik on 02.04.2018.
//

#include "inc/ValueLabel.h"

ValueLabel::~ValueLabel() = default;

ValueLabel::ValueLabel(const QString &labelText, QWidget *parent, Qt::WindowFlags f) : QLabel(labelText, parent, f) {

}
