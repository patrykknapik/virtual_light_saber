//
// Created by Patryk Knapik on 02.04.2018.
//



#include "inc/SettingsWindow.h"

SettingsWindow::SettingsWindow() : QWidget() {

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QPushButton *okButton = new QPushButton(tr("OK"));
    QPushButton *cancelButton = new QPushButton(tr("Anuluj"));

    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addWidget(okButton);

    mainLayout->addWidget(serialPortLineEdit);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    setWindowTitle(tr("Ustawienia"));
    setWindowModality(Qt::WindowModal);

    //connections
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(gatherAndSend()));
}

void SettingsWindow::gatherAndSend() {
    if (serialPortLineEdit->isModified()) {
        emit newSerialPath(serialPortLineEdit->text());
    }

    close();
}

SettingsWindow::~SettingsWindow() = default;
