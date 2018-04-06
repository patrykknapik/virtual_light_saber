//
// Created by Patryk Knapik on 02.04.2018.
//

#ifndef DESKTOPAPP_SETTINGSWINDOW_H
#define DESKTOPAPP_SETTINGSWINDOW_H


#include <QVBoxLayout>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>

class SettingsWindow : public QWidget {

Q_OBJECT
private:
    QLineEdit *serialPortLineEdit = new QLineEdit("/serial/port/path");

public:
    explicit SettingsWindow();

    ~SettingsWindow();;

private slots:

    void gatherAndSend();

signals:

    void newSerialPath(QString path);
};


#endif //DESKTOPAPP_SETTINGSWINDOW_H
