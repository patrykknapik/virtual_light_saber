//
// Created by Patryk Knapik on 20.03.2018.
//

#include "inc/MainWindow.h"


MainWindow::MainWindow(QWidget *parent) {
    setSurfaceType(QWindow::OpenGLSurface);

    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(2, 1);
    setFormat(format);

    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);
    openGLFunctions = context->functions();

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnimation()));
    timer->start(80);
    rotation = 0;
}

MainWindow::~MainWindow() {

}

void MainWindow::initializeGL() {
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glLoadIdentity();

    resizeGL(this->width(), height());
    update();
}

void MainWindow::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    qreal aspectRatio = qreal(w) / qreal(h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspectRatio, 0.1f, 400.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    update();

}

void MainWindow::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(rotation, 1.5f, 0.8f, 1.1f);

    // BACK
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, +1.0f, +1.0f); // 0
    glColor3f(+1.0f, +0.0f, +0.0f); // Colour
    glVertex3f(+1.0f, +1.0f, +1.0f); // 1
    glColor3f(+0.0f, +1.0f, +0.0f); // Colour
    glVertex3f(+1.0f, +1.0f, -1.0f); // 2
    glColor3f(+0.0f, +0.0f, +1.0f); // Colour
    glVertex3f(-1.0f, +1.0f, -1.0f); // 3
    glColor3f(+1.0f, +1.0f, +1.0f); // Colour
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, +1.0f, -1.0f); // 4
    glColor3f(+1.0f, +0.0f, +1.0f); // Colour
    glVertex3f(+1.0f, +1.0f, -1.0f); // 5
    glColor3f(+0.0f, +0.5f, +0.2f); // Colour
    glVertex3f(+1.0f, -1.0f, -1.0f); // 6
    glColor3f(+0.8f, +0.6f, +0.4f); // Colour
    glVertex3f(-1.0f, -1.0f, -1.0f); // 7
    glColor3f(+0.3f, +1.0f, +0.5f); // Colour
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(+1.0f, +1.0f, -1.0f); // 8
    glColor3f(+0.2f, +0.5f, +0.2f); // Colour
    glVertex3f(+1.0f, +1.0f, +1.0f); // 9
    glColor3f(+0.9f, +0.3f, +0.7f); // Colour
    glVertex3f(+1.0f, -1.0f, +1.0f); // 10
    glColor3f(+0.3f, +0.7f, +0.5f); // Colour
    glVertex3f(+1.0f, -1.0f, -1.0f); // 11
    glColor3f(+0.5f, +0.7f, +0.5f); // Colour
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, +1.0f, +1.0f); // 12
    glColor3f(+0.7f, +0.8f, +0.2f); // Colour
    glVertex3f(-1.0f, +1.0f, -1.0f); // 13
    glColor3f(+0.5f, +0.7f, +0.3f); // Colour
    glVertex3f(-1.0f, -1.0f, -1.0f); // 14
    glColor3f(+0.4f, +0.7f, +0.7f); // Colour
    glVertex3f(-1.0f, -1.0f, -1.0f); // 15
    glColor3f(+0.2f, +0.5f, +1.0f); // Colour
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(+1.0f, +1.0f, +1.0f); // 16
    glColor3f(+0.6f, +1.0f, +0.7f); // Colour
    glVertex3f(-1.0f, +1.0f, +1.0f); // 17
    glColor3f(+0.6f, +0.4f, +0.8f); // Colour
    glVertex3f(-1.0f, -1.0f, +1.0f); // 18
    glColor3f(+0.2f, +0.8f, +0.7f); // Colour
    glVertex3f(+1.0f, -1.0f, +1.0f); // 19
    glColor3f(+0.2f, +0.7f, +1.0f); // Colour
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.0f, +1.0f); // 22
    glColor3f(+0.5f, +0.8f, +0.5f); // Colour
    glVertex3f(-1.0f, -1.0f, -1.0f); // 21
    glColor3f(+0.9f, +1.0f, +0.2f); // Colour
    glVertex3f(+1.0f, -1.0f, -1.0f); // 20
    glColor3f(+0.8f, +0.3f, +0.7f); // Colour
    glVertex3f(+1.0f, -1.0f, +1.0f); // 23
    glColor3f(+0.8f, +0.9f, +0.5f); // Colour
    glEnd();

    glFlush();
    //makeCurrent();
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    resizeGL(width(), height());
    update();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    paintGL();
}

void MainWindow::updateAnimation() {

    rotation += 10;
    update();

}
