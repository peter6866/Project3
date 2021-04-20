#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>


#include <QFile>
#include <fstream>
#include <sstream>
#include <istream>
#include <limits>
#include <chrono>
#include "BST.h"
#include "MAP.h"
using namespace std;
using namespace chrono;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    struct dataNode {
        int passengersN, seatsN, flightsN,
        ori_populationN, des_populationN;
        dataNode(int passengersN, int seatsN, int flightsN, int ori_populationN,
                 int des_populationN) {

            this->passengersN = passengersN;
            this->seatsN = seatsN;
            this->flightsN = flightsN;
            this->ori_populationN = ori_populationN;
            this->des_populationN = des_populationN;
        }
    };

    int DSSelection;
    int selection;
    BST airport;
    Map<string, dataNode*> airport2;
    string month[12] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    string inputOriCity, inputDestCity;
    int inputYear;
    bool showChart;

    QBarSeries *series;
    QChart *chart;
    QStringList categories;
    QBarCategoryAxis *axis;
    QChartView *chartView;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void fun(int selection);
    void load();
    void showBarChartView();
    vector<string> xAxis;
    vector<string> yAxis;
    vector<dataNode*> data;
    vector<int> runningTimeBST;
    vector<int> runningTimeMap;



private:
    Ui::MainWindow *ui;

private slots :
//    void on_load_BST_clicked();
//    void on_load_map_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_loadData_clicked();
    void on_reset_clicked();
};
#endif // MAINWINDOW_H
