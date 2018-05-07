//
// Created by Patryk Knapik on 02.04.2018.
//

#ifndef DESKTOPAPP_SETTINGSWINDOW_H
#define DESKTOPAPP_SETTINGSWINDOW_H


#include <QVBoxLayout>
#include <QComboBox>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSerialPortInfo>
#include <QList>

class SettingsWindow : public QWidget {

Q_OBJECT
private:
    QComboBox *serialPortEdit;
    int portIndex;
    QList<QSerialPortInfo> portsList;

    void showEvent(QShowEvent *event) override;

public:
    explicit SettingsWindow();

    ~SettingsWindow();

private slots:

    void gatherAndSend();

    void serialPortPicked(int index);

signals:

    void newSerialPort(QSerialPortInfo port);
};


#endif //DESKTOPAPP_SETTINGSWINDOW_H
