//
// Created by Patryk Knapik on 02.04.2018.
//

#ifndef DESKTOPAPP_CHARTSWINDOW_H
#define DESKTOPAPP_CHARTSWINDOW_H

#include <QVBoxLayout>
#include <QLineSeries>
#include <QChartView>
#include <QWidget>
#include <QChart>
#include "inc/DataTypes.h"

class ChartsWindow : public QWidget {

Q_OBJECT

public:
    explicit ChartsWindow();

    ~ChartsWindow();

private:
    qreal range;

    QtCharts::QLineSeries *XgyroSeries = new QtCharts::QLineSeries;
    QtCharts::QLineSeries *YgyroSeries = new QtCharts::QLineSeries;
    QtCharts::QLineSeries *ZgyroSeries = new QtCharts::QLineSeries;

    QtCharts::QLineSeries *XaccSeries = new QtCharts::QLineSeries;
    QtCharts::QLineSeries *YaccSeries = new QtCharts::QLineSeries;
    QtCharts::QLineSeries *ZaccSeries = new QtCharts::QLineSeries;

    QtCharts::QChart *gyroChart = new QtCharts::QChart();
    QtCharts::QChart *accChart = new QtCharts::QChart();

    QtCharts::QChartView *gyroChartView = new QtCharts::QChartView(gyroChart);
    QtCharts::QChartView *accChartView = new QtCharts::QChartView(accChart);

public slots:

    void append(MemsData::rawData data);

};


#endif //DESKTOPAPP_CHARTSWINDOW_H
