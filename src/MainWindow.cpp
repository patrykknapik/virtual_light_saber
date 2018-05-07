//
// Created by Patryk Knapik on 20.03.2018.
//


#include <inc/DataTypes.h>
#include "inc/MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), rotation(0) {

    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x2c3e50)));
    QWidget *container = QWidget::createWindowContainer(view);
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 20.0f, 0));
    cameraEntity->setUpVector(QVector3D(0, 0, 1));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    Qt3DCore::QEntity *m_cuboidEntity;
    // Cuboid shape data
    Qt3DExtras::QCuboidMesh *cuboid = new Qt3DExtras::QCuboidMesh();

    // CuboidMesh Transform
    cuboidTransform->setScale(4.0f);
    cuboidTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    Qt3DExtras::QPhongMaterial *cuboidMaterial = new Qt3DExtras::QPhongMaterial();
    cuboidMaterial->setDiffuse(QColor(QRgb(0xc0392b)));

    //Cuboid
    m_cuboidEntity = new Qt3DCore::QEntity(rootEntity);
    m_cuboidEntity->addComponent(cuboid);
    m_cuboidEntity->addComponent(cuboidMaterial);
    m_cuboidEntity->addComponent(cuboidTransform);

    // Set root object of the scene
    view->setRootEntity(rootEntity);

    //Widgets
    statusBar = new QStatusBar;

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

    container->setMinimumSize(600, 600);

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

    mainLayout->addWidget(container);
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

void MainWindow::rawData(MemsData::rawData data) {
    XGyroValue->setText(QString("%1").arg(data.X_G));
    YGyroValue->setText(QString("%1").arg(data.Y_G));
    ZGyroValue->setText(QString("%1").arg(data.Z_G));

    XAccValue->setText(QString("%1").arg(data.X_XL));
    YAccValue->setText(QString("%1").arg(data.Y_XL));
    ZAccValue->setText(QString("%1").arg(data.Z_XL));

}

void MainWindow::posData(MemsData::posData data) {
    XTranValue->setText(QString("%1").arg(data.X_tran));
    YTranValue->setText(QString("%1").arg(data.Y_tran));
    ZTranValue->setText(QString("%1").arg(data.Z_tran));

    XRotValue->setText(QString("%1").arg(data.X_rot));
    YRotValue->setText(QString("%1").arg(data.Y_rot));
    ZRotValue->setText(QString("%1").arg(data.Z_rot));
    cuboidTransform->setRotationX(data.X_rot);
    cuboidTransform->setRotationY(data.Y_rot);
    cuboidTransform->setRotationZ(data.Z_rot);
    //cuboidTransform->setTranslation(QVector3D(data.X_tran,data.Y_tran,data.Z_tran));
}

void MainWindow::resetPositionData() {
    XTranValue->setText(QString("%1").arg(0));
    YTranValue->setText(QString("%1").arg(0));
    ZTranValue->setText(QString("%1").arg(0));

    XRotValue->setText(QString("%1").arg(0));
    YRotValue->setText(QString("%1").arg(0));
    ZRotValue->setText(QString("%1").arg(0));
    cuboidTransform->setRotationX(0.0);
    cuboidTransform->setRotationY(0.0);
    cuboidTransform->setRotationZ(0.0);
    cuboidTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

}

void MainWindow::closeEvent(QCloseEvent *event) {
    emit quitApp();
    QWidget::closeEvent(event);
}

void MainWindow::setSerialPort(QSerialPortInfo port) {
    serialPort = port;
    statusBar->showMessage(serialPort.portName());
}

