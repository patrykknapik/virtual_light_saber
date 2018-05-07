//
// Created by Patryk Knapik on 02.04.2018.
//


#include "inc/ChartsWindow.h"

ChartsWindow::ChartsWindow() : QWidget(), range(0) {
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
    gyroChart->axisY()->setRange(-500000, 500000);
    gyroChart->setTitle("Żyroskop");

    //accChart->legend()->hide();
    accChart->addSeries(XaccSeries);
    accChart->addSeries(YaccSeries);
    accChart->addSeries(ZaccSeries);
    accChart->createDefaultAxes();
    accChart->axisX()->setRange(0, 5);
    accChart->axisY()->setRange(-4000, 4000);
    accChart->setTitle("Akcelerometr");

    gyroChartView->setRenderHint(QPainter::Antialiasing);
    accChartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(accChartView);
    mainLayout->addWidget(gyroChartView);

    setLayout(mainLayout);

    setWindowTitle(tr("Wykresy"));
    setMinimumSize(640, 480);

}

void ChartsWindow::append(MemsData::rawData data) {
    range += (qreal) data.timeStamp / 1000.0;
    if (range < 10.0) {
        gyroChart->axisX()->setRange(0, QVariant(range));
        accChart->axisX()->setRange(0, QVariant(range));
    } else {
        gyroChart->axisX()->setRange(QVariant(range - 10.0), QVariant(range));
        accChart->axisX()->setRange(QVariant(range - 10.0), QVariant(range));
    }
    if (XaccSeries->count() > 350)
        XaccSeries->removePoints(0, 50);
    if (YaccSeries->count() > 350)
        YaccSeries->removePoints(0, 50);
    if (ZaccSeries->count() > 350)
        ZaccSeries->removePoints(0, 50);

    if (XgyroSeries->count() > 350)
        XgyroSeries->removePoints(0, 50);
    if (YgyroSeries->count() > 350)
        YgyroSeries->removePoints(0, 50);
    if (ZgyroSeries->count() > 350)
        ZgyroSeries->removePoints(0, 50);

    XgyroSeries->append(range, data.X_G);
    YgyroSeries->append(range, data.Y_G);
    ZgyroSeries->append(range, data.Z_G);

    XaccSeries->append(range, data.X_XL);
    YaccSeries->append(range, data.Y_XL);
    ZaccSeries->append(range, data.Z_XL);



}

ChartsWindow::~ChartsWindow() = default;
