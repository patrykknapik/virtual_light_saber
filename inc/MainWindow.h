//
// Created by Patryk Knapik on 20.03.2018.
//

#ifndef DESKTOPAPP_MAINWINDOW_H
#define DESKTOPAPP_MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <QTimer>
#include <QHBoxLayout>
#include <QvBoxLayout>
#include <QGridLayout>
#include "inc/ControlButton.h"
#include "inc/AxisLabel.h"
#include "inc/DescriptionLabel.h"
#include <QLabel>
#include <QGroupBox>
#include <QStatusBar>
#include "inc/ValueLabel.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    ValueLabel *XGyroValue = new ValueLabel(QString("0.0XG"));
    ValueLabel *YGyroValue = new ValueLabel(QString("0.0YG"));
    ValueLabel *ZGyroValue = new ValueLabel(QString("0.0ZG"));

    ValueLabel *XAccValue = new ValueLabel(QString("0.0XA"));
    ValueLabel *YAccValue = new ValueLabel(QString("0.0YA"));
    ValueLabel *ZAccValue = new ValueLabel(QString("0.0ZA"));

    ValueLabel *XTranValue = new ValueLabel(QString("0.0XT"));
    ValueLabel *YTranValue = new ValueLabel(QString("0.0YT"));
    ValueLabel *ZTranValue = new ValueLabel(QString("0.0ZT"));

    ValueLabel *XRotValue = new ValueLabel(QString("0.0XR"));
    ValueLabel *YRotValue = new ValueLabel(QString("0.0YR"));
    ValueLabel *ZRotValue = new ValueLabel(QString("0.0ZR"));

public slots:

    void rawData(qreal accData[3], qreal gyroData[3]);

    void positionData(qreal tran[3], qreal rot[3]);

    void resetPositionData();

private:
    QWidget *openGLSurfaceWidget = new QWidget;

signals:

    void invokeCharts();

    void invokeSettings();

    void quitApp();

    void resetPosition();

};


#endif //DESKTOPAPP_MAINWINDOW_H
