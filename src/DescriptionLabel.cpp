//
// Created by Patryk Knapik on 02.04.2018.
//

#include "inc/DescriptionLabel.h"

DescriptionLabel::~DescriptionLabel() = default;

DescriptionLabel::DescriptionLabel(const QString &labelText, QWidget *parent, Qt::WindowFlags f) : QLabel(labelText,
                                                                                                          parent, f) {

}
