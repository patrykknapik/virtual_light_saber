//
// Created by Patryk Knapik on 20.03.2018.
//

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent) {
    firstLayout->addWidget(firstButton);
    firstLayout->addWidget(firstLabel);
    centralWidget->setLayout(firstLayout);
    setCentralWidget(centralWidget);

    firstButton->setText(QString("HA!"));
    firstLabel->setText(QString("%1").arg(++i));
    connect(firstButton, SIGNAL(clicked()), this, SLOT(keyPressed()));
    connect(this, SIGNAL(setLabel(
                                 const QString &)), firstLabel, SLOT(setText(
                                                                             const QString &)));
    qDebug() << "Wszystko skonstruowane ane ane!!!! XD\n";
}

MainWindow::~MainWindow() {
    delete firstLabel;
    delete firstLayout;
    delete firstButton;
    delete centralWidget;
}

void MainWindow::keyPressed() {
    emit setLabel(QString("%1").arg(++i));
    qDebug() << "HEHE i == " << i << '\n';
}
