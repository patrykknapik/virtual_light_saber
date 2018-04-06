//
// Created by Patryk Knapik on 20.03.2018.
//


#include "inc/MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QStatusBar *statusBar = new QStatusBar;

    QSpacerItem *interObjectSpacer = new QSpacerItem(250, 10, QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
    QSpacerItem *interBoxSpacer = new QSpacerItem(250, 10, QSizePolicy::Fixed, QSizePolicy::Fixed);

    QWidget *centralWidget = new QWidget;

    QGroupBox *rawDataBox = new QGroupBox(tr("Surowe dane:"));
    QGroupBox *objectPositionBox = new QGroupBox(tr("Pozycja obiektu:"));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *dataControlsLayout = new QVBoxLayout;
    QGridLayout *rawDataLayout = new QGridLayout;
    QGridLayout *objectPositionLayout = new QGridLayout;

    ControlButton *chartsButton = new ControlButton(tr("Wykresy"));
    ControlButton *settingsButton = new ControlButton(tr("Ustawienia"));
    ControlButton *resetPositionButton = new ControlButton(tr("Zerowanie pozycji"));
    ControlButton *endButton = new ControlButton(tr("Koniec"));

    DescriptionLabel *accDescription = new DescriptionLabel(tr("Akcelerometr:"));
    DescriptionLabel *gyroDescription = new DescriptionLabel(tr("Żyroskop:"));
    DescriptionLabel *tranDescription = new DescriptionLabel(tr("Translacja:"));
    DescriptionLabel *rotDescription = new DescriptionLabel(tr("Rotacja:"));

    QLabel *statusBarSerialPort = new QLabel(tr("Proszę wybrać port szeregowy w ustawieniach."));

    AxisLabel *XlabelRaw = new AxisLabel(QString("X:"));
    AxisLabel *YlabelRaw = new AxisLabel(QString("Y:"));
    AxisLabel *ZlabelRaw = new AxisLabel(QString("Z:"));

    AxisLabel *XlabelPos = new AxisLabel(QString("X:"));
    AxisLabel *YlabelPos = new AxisLabel(QString("Y:"));
    AxisLabel *ZlabelPos = new AxisLabel(QString("Z:"));

    openGLSurfaceWidget->setMinimumSize(600, 600);

    rawDataLayout->addWidget(accDescription, 0, 1, Qt::AlignLeft);
    rawDataLayout->addWidget(gyroDescription, 0, 2, Qt::AlignLeft);
    rawDataLayout->addWidget(XlabelRaw, 1, 0, Qt::AlignLeft);
    rawDataLayout->addWidget(YlabelRaw, 2, 0, Qt::AlignLeft);
    rawDataLayout->addWidget(ZlabelRaw, 3, 0, Qt::AlignLeft);
    rawDataLayout->addWidget(XAccValue, 1, 1, Qt::AlignCenter);
    rawDataLayout->addWidget(YAccValue, 2, 1, Qt::AlignCenter);
    rawDataLayout->addWidget(ZAccValue, 3, 1, Qt::AlignCenter);
    rawDataLayout->addWidget(XGyroValue, 1, 2, Qt::AlignCenter);
    rawDataLayout->addWidget(YGyroValue, 2, 2, Qt::AlignCenter);
    rawDataLayout->addWidget(ZGyroValue, 3, 2, Qt::AlignCenter);
    rawDataLayout->setColumnMinimumWidth(1, 100);
    rawDataLayout->setColumnMinimumWidth(2, 100);

    objectPositionLayout->addWidget(tranDescription, 0, 1, Qt::AlignLeft);
    objectPositionLayout->addWidget(rotDescription, 0, 2, Qt::AlignLeft);
    objectPositionLayout->addWidget(XlabelPos, 1, 0, Qt::AlignLeft);
    objectPositionLayout->addWidget(YlabelPos, 2, 0, Qt::AlignLeft);
    objectPositionLayout->addWidget(ZlabelPos, 3, 0, Qt::AlignLeft);
    objectPositionLayout->addWidget(XTranValue, 1, 1, Qt::AlignCenter);
    objectPositionLayout->addWidget(YTranValue, 2, 1, Qt::AlignCenter);
    objectPositionLayout->addWidget(ZTranValue, 3, 1, Qt::AlignCenter);
    objectPositionLayout->addWidget(XRotValue, 1, 2, Qt::AlignCenter);
    objectPositionLayout->addWidget(YRotValue, 2, 2, Qt::AlignCenter);
    objectPositionLayout->addWidget(ZRotValue, 3, 2, Qt::AlignCenter);
    objectPositionLayout->setColumnMinimumWidth(1, 100);
    objectPositionLayout->setColumnMinimumWidth(2, 100);

    rawDataBox->setLayout(rawDataLayout);
    rawDataBox->setFixedSize(250, BOX_V_SIZE);
    rawDataBox->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    objectPositionBox->setLayout(objectPositionLayout);
    objectPositionBox->setFixedSize(250, BOX_V_SIZE);
    objectPositionBox->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    dataControlsLayout->addWidget(rawDataBox);
    dataControlsLayout->addSpacerItem(interBoxSpacer);
    dataControlsLayout->addWidget(objectPositionBox);
    dataControlsLayout->addSpacerItem(interObjectSpacer);
    dataControlsLayout->addWidget(chartsButton);
    dataControlsLayout->addWidget(settingsButton);
    dataControlsLayout->addWidget(resetPositionButton);
    dataControlsLayout->addWidget(endButton);

    mainLayout->addWidget(openGLSurfaceWidget);
    mainLayout->addLayout(dataControlsLayout);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setWindowTitle(QString(MainWindow::tr("Wirtualny Miecz Świetlny!")));

    //status bar

    statusBar->addWidget(statusBarSerialPort);
    setStatusBar(statusBar);

    //connections

    connect(endButton, SIGNAL(clicked()), this, SIGNAL(quitApp()));
    connect(chartsButton, SIGNAL(clicked()), this, SIGNAL(invokeCharts()));
    connect(settingsButton, SIGNAL(clicked()), this, SIGNAL(invokeSettings()));
    connect(resetPositionButton, SIGNAL(clicked()), this, SLOT(resetPositionData()));
    connect(resetPositionButton, SIGNAL(clicked()), this, SIGNAL(resetPosition()));

}

MainWindow::~MainWindow() {

}

void MainWindow::rawData(qreal *accData, qreal *gyroData) {
    XGyroValue->setText(QString("%1").arg(gyroData[0]));
    YGyroValue->setText(QString("%1").arg(gyroData[1]));
    ZGyroValue->setText(QString("%1").arg(gyroData[2]));

    XAccValue->setText(QString("%1").arg(accData[0]));
    YAccValue->setText(QString("%1").arg(accData[1]));
    ZAccValue->setText(QString("%1").arg(accData[2]));

}

void MainWindow::positionData(qreal *tran, qreal *rot) {
    XTranValue->setText(QString("%1").arg(tran[0]));
    YTranValue->setText(QString("%1").arg(tran[1]));
    ZTranValue->setText(QString("%1").arg(tran[2]));

    XRotValue->setText(QString("%1").arg(rot[0]));
    YRotValue->setText(QString("%1").arg(rot[1]));
    ZRotValue->setText(QString("%1").arg(rot[2]));
}

void MainWindow::resetPositionData() {
    XTranValue->setText(QString("%1").arg(0));
    YTranValue->setText(QString("%1").arg(0));
    ZTranValue->setText(QString("%1").arg(0));

    XRotValue->setText(QString("%1").arg(0));
    YRotValue->setText(QString("%1").arg(0));
    ZRotValue->setText(QString("%1").arg(0));
}

