//
// Created by Patryk Knapik on 02.04.2018.
//



#include "inc/ChartsWindow.h"

ChartsWindow::ChartsWindow() : QWidget() {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    XgyroSeries->setName(tr("X"));
    YgyroSeries->setName(tr("Y"));
    ZgyroSeries->setName(tr("Z"));

    XaccSeries->setName(tr("X"));
    YaccSeries->setName(tr("Y"));
    ZaccSeries->setName(tr("Z"));

    gyroChart->addSeries(XgyroSeries);
    gyroChart->addSeries(YgyroSeries);
    gyroChart->addSeries(ZgyroSeries);
    gyroChart->createDefaultAxes();
    gyroChart->axisX()->setRange(0, 5);
    gyroChart->axisY()->setRange(0, 10);
    gyroChart->setTitle("Żyroskop");

    //accChart->legend()->hide();
    accChart->addSeries(XaccSeries);
    accChart->addSeries(YaccSeries);
    accChart->addSeries(ZaccSeries);
    accChart->createDefaultAxes();
    accChart->axisX()->setRange(0, 5);
    accChart->axisY()->setRange(0, 10);
    accChart->setTitle("Akcelerometr");

    gyroChartView->setRenderHint(QPainter::Antialiasing);
    accChartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(accChartView);
    mainLayout->addWidget(gyroChartView);

    setLayout(mainLayout);

    setWindowTitle(tr("Wykresy"));
    setMinimumSize(640, 480);


}

void ChartsWindow::append(qreal accData[3], qreal gyroData[3]) {

    XgyroSeries->append(0, 1);
    YgyroSeries->append(0, 4);
    ZgyroSeries->append(0, 2);
    XgyroSeries->append(1, 6);
    YgyroSeries->append(1, 3);
    ZgyroSeries->append(1, 1);
    XgyroSeries->append(2, 4);
    YgyroSeries->append(2, 5);
    ZgyroSeries->append(2, 2);
    XgyroSeries->append(3, 1);
    YgyroSeries->append(3, 4);
    ZgyroSeries->append(3, 2);
    XgyroSeries->append(4, 6);
    YgyroSeries->append(4, 3);
    ZgyroSeries->append(4, 1);
    XgyroSeries->append(5, 4);
    YgyroSeries->append(5, 5);
    ZgyroSeries->append(5, 2);

    XaccSeries->append(0, 1);
    YaccSeries->append(0, 4);
    ZaccSeries->append(0, 2);
    XaccSeries->append(1, 6);
    YaccSeries->append(1, 3);
    ZaccSeries->append(1, 1);
    XaccSeries->append(2, 4);
    YaccSeries->append(2, 5);
    ZaccSeries->append(2, 2);
    XaccSeries->append(3, 1);
    YaccSeries->append(3, 4);
    ZaccSeries->append(3, 2);
    XaccSeries->append(4, 6);
    YaccSeries->append(4, 3);
    ZaccSeries->append(4, 1);
    XaccSeries->append(5, 4);
    YaccSeries->append(5, 5);
    ZaccSeries->append(5, 2);
    //TODO implement this properly

}

ChartsWindow::~ChartsWindow() = default;
