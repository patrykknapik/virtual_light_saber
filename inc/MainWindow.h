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

namespace Ui {
    class MainWindow;
}

class MainWindow : public QOpenGLWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

protected:
    virtual void initializeGL();

    virtual void resizeGL(int w, int h);

    virtual void paintGL();

    void resizeEvent(QResizeEvent *event);

    void paintEvent(QPaintEvent *event);

public slots:

    void updateAnimation();

private:
    float rotation;
    QOpenGLContext *context;
    QOpenGLFunctions *openGLFunctions;


};


#endif //DESKTOPAPP_MAINWINDOW_H
