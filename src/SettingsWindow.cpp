//
// Created by Patryk Knapik on 02.04.2018.
//




#include "inc/SettingsWindow.h"

SettingsWindow::SettingsWindow() : QWidget() {
    portsList = QSerialPortInfo::availablePorts();

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QHBoxLayout *serialPickerLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QPushButton *okButton = new QPushButton(tr("OK"));
    QPushButton *cancelButton = new QPushButton(tr("Anuluj"));

    QLabel *serialPickerLabel = new QLabel(tr("Port:"));

    serialPortEdit = new QComboBox();

    for (auto port : portsList) {
        serialPortEdit->addItem(port.portName());
    }

    serialPickerLayout->addWidget(serialPickerLabel);
    serialPickerLayout->addWidget(serialPortEdit);

    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addWidget(okButton);

    mainLayout->addLayout(serialPickerLayout);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    setWindowTitle(tr("Ustawienia"));
    setWindowModality(Qt::WindowModal);

    //connections
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(gatherAndSend()));
    connect(serialPortEdit, SIGNAL(activated(int)), this, SLOT(serialPortPicked(int)));
}

void SettingsWindow::gatherAndSend() {
    emit newSerialPort(portsList.at(portIndex));
    close();
}

void SettingsWindow::serialPortPicked(int index) {
    portIndex = index;
}

void SettingsWindow::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    portsList = QSerialPortInfo::availablePorts();
    serialPortEdit->clear();
    for (auto port : portsList) {
        serialPortEdit->addItem(port.portName());
    }
}

SettingsWindow::~SettingsWindow() = default;
