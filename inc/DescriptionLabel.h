//
// Created by Patryk Knapik on 02.04.2018.
//

#ifndef DESKTOPAPP_DESCRIPTIONLABEL_H
#define DESKTOPAPP_DESCRIPTIONLABEL_H


#include <QLabel>

class DescriptionLabel : public QLabel {
Q_OBJECT
public:
    explicit DescriptionLabel(const QString &labelText, QWidget *parent = Q_NULLPTR,
                              Qt::WindowFlags f = Qt::WindowFlags());

    ~DescriptionLabel();
};


#endif //DESKTOPAPP_DESCRIPTIONLABEL_H
