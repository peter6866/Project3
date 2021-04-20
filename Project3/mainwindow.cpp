#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "demo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //showBarChartView();
    showBarChartView();
    ui->DisplayResult->clear();
    runningTimeBST.clear();
    runningTimeMap.clear();
    if(series){
        chart->removeSeries(series);
        series->clear();
    }
    if(axis){
        chart->removeAxis(axis);
        axis->clear();
    }
    categories.clear();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load() {

    //initialize data source
    ifstream data("final_data2.csv");
    string temp;
    getline(data, temp);
    int date, passengers, seats, flights, ori_population,
            des_population;
    string ori_city_pre, ori_city_post, des_city_pre, des_city_post, ori_city, des_city;

    //int DSSelection;
    cout << "load data by two way" << endl;
    cout << "1. Binary Search Tree" << endl;
    cout << "2. Map with hash table" << endl;
//    cout << "Select111: ";


    //cin >> DSSelection;
    //    BST airport;
    //    Map<string, dataNode*> airport2;
    //    string month[12] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    // **************** 1**************
    //auto start = system_clock::now();
    QElapsedTimer timer;
    timer.start();
    while (data.good())
    {
        getline(data, ori_city_pre, ',');
        //cout << "data pre: " << ori_city_pre ;
        if (ori_city_pre == "")
            break;
        getline(data, ori_city_post, ',');
        //cout << "data post: " << ori_city_post ;
        getline(data, des_city_pre, ',');
        getline(data, des_city_post, ',');
        ori_city = ori_city_pre + ori_city_post;
        ori_city = ori_city.substr(1, ori_city.size() - 2);
        des_city = des_city_pre + des_city_post;
        des_city = des_city.substr(1, des_city.size() - 2);
        getline(data, temp, ',');
        passengers = stoi(temp);
        getline(data, temp, ',');
        seats = stoi(temp);
        getline(data, temp, ',');
        flights = stoi(temp);
        getline(data, temp, ',');
        date = stoi(temp);
        getline(data, temp, ',');
        ori_population = stoi(temp);
        getline(data, temp, '\n');
        des_population = stoi(temp);
        airport.insert(date, passengers, seats, flights, ori_population,
                       des_population, ori_city, des_city);
    }
    quint64 x = timer.elapsed();
    int y = static_cast<int>(x);
    qDebug() << "Insertion time using BST: " << x << "milliseconds";


    //auto end = system_clock::now();
    //auto duration = duration_cast<microseconds>(end - start);
    //cout << "Insertion time using BST: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
    data.close();
    //***************************2******************************
    //auto start = system_clock::now();
    ifstream data2("final_data2.csv");
    getline(data2, temp);
    QElapsedTimer timer2;
    timer2.start();
    while (data2.good()) {
        getline(data2, ori_city_pre, ',');
        if (ori_city_pre.empty())
            break;
        getline(data2, ori_city_post, ',');
        getline(data2, des_city_pre, ',');
        getline(data2, des_city_post, ',');
        ori_city = ori_city_pre + ori_city_post;
        ori_city = ori_city.substr(1, ori_city.size() - 2);
        des_city = des_city_pre + des_city_post;
        des_city = des_city.substr(1, des_city.size() - 2);
        getline(data2, temp, ',');
        passengers = stoi(temp);
        getline(data2, temp, ',');
        seats = stoi(temp);
        getline(data2, temp, ',');
        flights = stoi(temp);
        getline(data2, temp, ',');
        date = stoi(temp);
        getline(data2, temp, ',');
        ori_population = stoi(temp);
        getline(data2, temp, '\n');
        des_population = stoi(temp);
        dataNode* temp1 = new dataNode(passengers, seats, flights, ori_population, des_population);
        string compositeKey = ori_city.append(" ").append(des_city).append(" ").append(to_string(date));
        airport2.push(compositeKey, temp1);
    }
    //auto end = system_clock::now();
    //auto duration = duration_cast<microseconds>(end - start);
    //cout << "Insertion time using MAP: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
    quint64 x2 = timer2.elapsed();
    int y2 = static_cast<int>(x2);
    qDebug() << "Insertion time using MAP: " << x2 << "milliseconds";

    xAxis.push_back("load");
//    xAxis.push_back("Map");

    runningTimeBST.push_back(y);
    runningTimeBST.push_back(y2);
    return;
}



void MainWindow::fun(int selection){
    //int selection;
    cout << "Select Function" << endl;
    cout << "1. Number of Routes" << endl;
    cout << "2. Seat Occupancy" << endl;
    cout << "3. Population Trend" << endl;
    cout << "4. Quit" << endl;
    cout << "Select: ";
    //cin >> selection;
    cout << endl;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout <<selection << " " << DSSelection << "*******************"<< inputYear << " " << inputOriCity << " " << inputDestCity<<endl;

    while (selection != 4)
    {
        if (selection == 1)
        {
            //Test Case: Aberdeen SD, Minneapolis MN, 2000
            //            string inputOriCity, inputDestCity;
            //            int inputYear;

            cout << "Origin City: " << inputOriCity << endl;
            //getline(cin, inputOriCity);
            cout << "Destination City: " << inputDestCity << endl;
            //getline(cin, inputDestCity);
            cout << "Year: " << inputYear << endl;
            //cin >> inputYear;
            cout << endl;
            if (DSSelection == 1)
            {
                QElapsedTimer timer;
                timer.start();
                //auto start = system_clock::now();
                //BST
                //user input origin_city, des_city, and year
                vector<string> result = airport.findFlights(inputOriCity, inputDestCity, inputYear);
                //auto end = system_clock::now();
                //auto duration = duration_cast<nanoseconds>(end - start);
                //cout << "Execution time: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;

                quint64 x = timer.nsecsElapsed();
                int y = static_cast<int>(x);
                qDebug() << "Execution time: " << x << "nanoseconds";


                runningTimeBST.push_back(y);
                ui->DisplayResult->clear();
                for (size_t i = 0; i < result.size(); i++) {
                    ui->DisplayResult->append(QString::fromStdString(result[i]));
                }


            }
            if (DSSelection == 1)
            {
                //MAP
                //auto start = system_clock::now();
                QElapsedTimer timer;
                timer.start();
                int extendedDate = (inputYear * 10000) + 101;
                for (int i = 0; i < 12; i++)
                {
                    string key = inputOriCity + " " + inputDestCity + " " + to_string(extendedDate);
                    //cout << key << endl;
                    int routes;
                    try {
                        routes = airport2.at(key)->flightsN;
                    }  catch (...) {

                    }
                    cout << "Total routes " << "from " << inputOriCity << " to " << inputDestCity << " in " << month[i] << ": "<< routes << endl;
                    extendedDate += 100;
                    key = "";
                }
                //auto end = system_clock::now();
                //auto duration = duration_cast<std::chrono::nanoseconds>(end - start);
                //cout << "Execution time: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
                //qDebug() << "The slow operation took" << timer.elapsed() << "milliseconds";
                quint64 x = timer.nsecsElapsed();
                int y = static_cast<int>(x);
                qDebug() << "Execution time: " << x << "nanoseconds";
                runningTimeMap.push_back(y);
            }

            cout << endl;
        }
        else if (selection == 2)
        {
            //function 2 test
            //string ori_city, des_city, year;
            //string inputOriCity, inputDestCity;

            cout << "Origin City: " << inputOriCity << endl;
            //getline(cin, inputOriCity);
            cout << "Destination City: " << inputDestCity << endl;
            //getline(cin, inputDestCity);
            cout << endl;

            if (DSSelection == 1)
            {
                //BST
                vector<string> result;
                //auto start = system_clock::now();
                QElapsedTimer timer;
                timer.start();
                for (int i = 2001; i <= 2009; i++)
                    result.push_back(airport.seatOccupancy(inputOriCity, inputDestCity, i));
                quint64 x = timer.nsecsElapsed();
                int y = static_cast<int>(x);
                qDebug() << "Execution time: " << x << "nanoseconds";
                //auto end = system_clock::now();
                //auto duration = duration_cast<microseconds>(end - start);
                //cout << "Execution time: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
                runningTimeBST.push_back(y);
                ui->DisplayResult->clear();
                for (size_t i = 0; i < result.size(); i++) {
                    ui->DisplayResult->append(QString::fromStdString(result[i]));
                }
            }

            if (DSSelection == 1)
            {
                //auto start = system_clock::now();
                QElapsedTimer timer;
                timer.start();
                for (int i = 2001; i <= 2009; i++)
                {
                    int extendedDate = (i * 10000) + 101;
                    int passengerSum = 0, seatSum = 0;
                    float percentage = 0.0;
                    for (int j = 0; j < 12; j++)
                    {
                        string key = inputOriCity + " " + inputDestCity + " " + to_string(extendedDate);
                        try {
                            passengerSum += airport2.at(key)->passengersN;
                        }  catch (...) {

                        }
                        try {
                            seatSum += airport2.at(key)->seatsN;
                        }  catch (...) {

                        }
                        extendedDate += 100;
                    }
                    cout.precision(3);
                    percentage = ((float)passengerSum / (float)seatSum) * 100;
                    cout << "Passengers" << ": " << passengerSum << " | Seats" << ": " << seatSum << " in " << i << endl;
                    cout << "Average seat Occupancy: " << percentage << "%" << endl;
                    cout << endl;
                }
                quint64 x = timer.nsecsElapsed();
                int y = static_cast<int>(x);
                qDebug() << "Execution time: " << x << "nanoseconds";
                runningTimeMap.push_back(y);
                //auto end = system_clock::now();
                //auto duration = duration_cast<microseconds>(end - start);
                //cout << "Execution time: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
            }
        }
        else if (selection == 3)
        {
            //string inputDestCity;
            cout << "City Name: " << inputOriCity << endl;
            //getline(cin, inputDestCity);
            //X-axis: 2000 to 2009
            //store Y-axis in a vector
            vector<int> passengerNum;
            vector<int> populationNum;
            if (DSSelection == 1)
            {
//                auto start = system_clock::now();
                vector<string> result;
                QElapsedTimer timer;
                timer.start();
                for (int i = 2001; i <= 2009; i++)
                    result.push_back(airport.populationTrend(inputDestCity, i));

                quint64 x = timer.nsecsElapsed();
                int y = static_cast<int>(x);
                qDebug() << "Execution time: " << x << "nanoseconds";
                runningTimeBST.push_back(y);
                ui->DisplayResult->clear();
                for (size_t i = 0; i < result.size(); i++) {
                    ui->DisplayResult->append(QString::fromStdString(result[i]));
                }
//                auto end = system_clock::now();
//                auto duration = duration_cast<microseconds>(end - start);
//                cout << "Execution time: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << " seconds" << endl;
            }

            //MAP N/A

        }
        cout << endl;
        cout << "Selection: ";
        //cin >> selection;
        selection = 4;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Program Terminates" << endl;
    return;
}


void MainWindow::showBarChartView()
{
    ui->DisplayResult->clear();
    runningTimeBST.clear();
    runningTimeMap.clear();


    cout << "************chart*****************" << endl;
//    Box *box = new Box();
//    box->makeFriends();
//    box->makeMoney();
//    vector<string> fr = box->getFriends();
//    vector<int> mo = box->getMoney();]


    series = new QBarSeries();
    for (size_t i = 0; i < xAxis.size() ; i++) {
        QString setName = xAxis[i].c_str();
        QBarSet *set = new QBarSet(setName);
        for (size_t j = 0; j < runningTimeBST.size() ; j++) {
            *set << runningTimeBST[j];
        }
        series->append(set);
    }
//    const char* p = fr[0].c_str();
//    const char* p1 = fr[1].c_str();
//    const char* p2 = fr[2].c_str();
//    const char* p3 = fr[3].c_str();
//    const char* p4 = fr[4].c_str();

    // Assign names to the set of bars used
//    QBarSet *set0 = new QBarSet(p);
//    QBarSet *set1 = new QBarSet(p1);
//    QBarSet *set2 = new QBarSet(p2);
//    QBarSet *set3 = new QBarSet(p3);
//    QBarSet *set4 = new QBarSet(p4);

    // Assign values for each bar

//    *set0 << runningTime << mo[1] << mo[2] << mo[3] << mo[4] << mo[5];
//    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
//    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
//    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
//    *set4 << 323 << 287 << 299 << 315 << 306 << 313;

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    //QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
//    series->append(set0);
//    series->append(set1);
//    series->append(set2);
//    series->append(set3);
//    series->append(set4);

    // Used to define the bar chart to display, title
    // legend,
    chart = new QChart();

    // Add the chart
    chart->addSeries(series);


    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles

    //categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";
    for (size_t i = 0; i < xAxis.size() ; i++) {
        categories.append(QString::fromStdString(xAxis[i]));
    }

    // Adds categories to the axes
    axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart
    // chart->setAxisY(axis, series);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to display the chart
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chart);
    //chartView->hide();


    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // Apply palette changes to the application
    qApp->setPalette(pal);
}


//void MainWindow::on_load_BST_clicked()
//{
//    load();
//    QString hint2 = "load by BST success";
//    ui->Display->setText(hint2);
//    DSSelection = 1;
///*
//    vector<QBarSet*> barSet;
//    QBarSeries *series;
//    QChart *chart;
//    QStringList categories;
//    QBarCategoryAxis *axis;
//    QChartView *chartView;
//    */

//    chart->removeSeries(series);
//    chart->removeAxis(axis);
//    series->clear();
//    categories.clear();
//    axis->clear();
////    for (size_t i = 0; i < xAxis.size() ; i++) {
////        QBarSet *set = new QBarSet(xAxis[i].c_str());
////        for (size_t j = 0; j < runningTimeBST.size() ; j++) {
////            set->append(runningTimeBST[j]);
////        }
////        series->append(set);
////        barSet.push_back(set);
////    }
//    QBarSet *set1 = new QBarSet("BST");
//    QBarSet *set2 = new QBarSet("Map");

//    set1->append(runningTimeBST[0]);
//    set2->append(runningTimeBST[1]);

//    series->append(set1);
//    series->append(set2);
//    chart->addSeries(series);
//    chart->setTitle("Comparison of the time to load data between the two methods");
//    chart->setAnimationOptions(QChart::SeriesAnimations);
//    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
////    for (size_t i = 0; i < 2 ; i++) {
////        categories.append(QString::fromStdString(xAxis[i]));
////    }
//    categories << "load";
//    axis->append(categories);
//    chart->createDefaultAxes();
//    chart->addAxis(axis, Qt::AlignBottom);
//    chart->legend()->setVisible(true);
//    chart->legend()->setAlignment(Qt::AlignBottom);
//    chart->setParent(ui->chart);
//}

//void MainWindow::on_load_map_clicked()
//{
//    load();
//    QString hint2 = "Loaded successfully";
//    ui->Display->setText(hint2);
//    DSSelection = 2;
//}

void MainWindow::on_pushButton_1_clicked()
{
    ui->DisplayResult->clear();
    runningTimeBST.clear();
    runningTimeMap.clear();


    QString hint1 = "please input Origin City:";
    ui->Display->setText(hint1);
    QString fun1_1 = ui->fun1_1->text();
    QString fun1_2 = ui->fun1_2->text();
    QString fun1_3 = ui->fun1_3->text();
    inputOriCity = fun1_1.toStdString();
    inputDestCity = fun1_2.toStdString();
    inputYear = fun1_3.toInt();
    fun(1);

    // **********draw **************
    if(series){
        chart->removeSeries(series);
        series->clear();
    }
    if(axis){
        chart->removeAxis(axis);
        axis->clear();
    }
    categories.clear();

//    for (size_t i = 0; i < xAxis.size() ; i++) {
//        QBarSet *set = new QBarSet(xAxis[i].c_str());
//        for (size_t j = 0; j < runningTimeBST.size() ; j++) {
//            set->append(runningTimeBST[j]);
//        }
//        series->append(set);
//        barSet.push_back(set);
//    }
    QBarSet *set1 = new QBarSet("BST");
    QBarSet *set2 = new QBarSet("Map * 10 nanoseconds");
    for (size_t i = 0; i < runningTimeBST.size(); i++) {
        set1->append(runningTimeBST[i]);
    }
    for (size_t i = 0; i < runningTimeMap.size(); i++) {
        set2->append(runningTimeMap[i]*10);
        cout << runningTimeMap[i];
    }

    series->append(set1);
    series->append(set2);
    chart->addSeries(series);
    chart->setTitle("Comparison of the time to search data between the two methods");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
//    for (size_t i = 0; i < runningTimeBST.size() ; i++) {
//        categories.append(QString::number(i));
//    }
//    categories << "load";
    //axis->append(categories);
    chart->createDefaultAxes();
    //chart->addAxis(axis, Qt::AlignBottom);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setParent(ui->chart);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->DisplayResult->clear();
    runningTimeBST.clear();
    runningTimeMap.clear();


    QString hint1 = "please input Origin City:";
    ui->Display->setText(hint1);
    fun(2);

    // **********draw **************
    if(series){
        chart->removeSeries(series);
        series->clear();
    }
    if(axis){
        chart->removeAxis(axis);
        axis->clear();
    }
    categories.clear();

//    for (size_t i = 0; i < xAxis.size() ; i++) {
//        QBarSet *set = new QBarSet(xAxis[i].c_str());
//        for (size_t j = 0; j < runningTimeBST.size() ; j++) {
//            set->append(runningTimeBST[j]);
//        }
//        series->append(set);
//        barSet.push_back(set);
//    }
    QBarSet *set1 = new QBarSet("BST");
    QBarSet *set2 = new QBarSet("Map * 10 nanoseconds");
    for (size_t i = 0; i < runningTimeBST.size(); i++) {
        set1->append(runningTimeBST[i]);
    }
    for (size_t i = 0; i < runningTimeMap.size(); i++) {
        set2->append(runningTimeMap[i]*10);
        cout << runningTimeMap[i];
    }

    series->append(set1);
    series->append(set2);
    chart->addSeries(series);
    chart->setTitle("Comparison of the time to search data between the two methods");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
//    for (size_t i = 0; i < runningTimeBST.size() ; i++) {
//        categories.append(QString::number(i));
//    }
//    categories << "load";
    //axis->append(categories);
    chart->createDefaultAxes();
    //chart->addAxis(axis, Qt::AlignBottom);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setParent(ui->chart);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->DisplayResult->clear();
    runningTimeBST.clear();
    runningTimeMap.clear();


    QString hint1 = "function 3";
    ui->Display->setText(hint1);
    fun(3);

    // **********draw **************
    if(series){
        chart->removeSeries(series);
        series->clear();
    }
    if(axis){
        chart->removeAxis(axis);
        axis->clear();
    }
    categories.clear();

//    for (size_t i = 0; i < xAxis.size() ; i++) {
//        QBarSet *set = new QBarSet(xAxis[i].c_str());
//        for (size_t j = 0; j < runningTimeBST.size() ; j++) {
//            set->append(runningTimeBST[j]);
//        }
//        series->append(set);
//        barSet.push_back(set);
//    }
    QBarSet *set1 = new QBarSet("BST");
    //QBarSet *set2 = new QBarSet("Map * 100 nanoseconds");
    for (size_t i = 0; i < runningTimeBST.size(); i++) {
        set1->append(runningTimeBST[i]);
    }
//    for (size_t i = 0; i < runningTimeMap.size(); i++) {
//        set2->append(runningTimeMap[i]*100);
//        cout << runningTimeMap[i];
//    }

    series->append(set1);
    //series->append(set2);
    chart->addSeries(series);
    chart->setTitle("Comparison of the time to search data between the two methods");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
//    for (size_t i = 0; i < runningTimeBST.size() ; i++) {
//        categories.append(QString::number(i));
//    }
//    categories << "load";
    //axis->append(categories);
    chart->createDefaultAxes();
    //chart->addAxis(axis, Qt::AlignBottom);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setParent(ui->chart);
}


void MainWindow::on_loadData_clicked()
{
    ui->DisplayResult->clear();
    runningTimeBST.clear();
    runningTimeMap.clear();


    if(isLoaded == true){
        return;
    }
    load();
    isLoaded = true;
    QString hint2 = "load by BST success";
    ui->Display->setText(hint2);
    DSSelection = 1;
/*
    vector<QBarSet*> barSet;
    QBarSeries *series;
    QChart *chart;
    QStringList categories;
    QBarCategoryAxis *axis;
    QChartView *chartView;
    */

    if(series){
        chart->removeSeries(series);
        series->clear();
    }
    if(axis){
        chart->removeAxis(axis);
        axis->clear();
    }
    categories.clear();

//    for (size_t i = 0; i < xAxis.size() ; i++) {
//        QBarSet *set = new QBarSet(xAxis[i].c_str());
//        for (size_t j = 0; j < runningTimeBST.size() ; j++) {
//            set->append(runningTimeBST[j]);
//        }
//        series->append(set);
//        barSet.push_back(set);
//    }
    QBarSet *set1 = new QBarSet("BST");
    QBarSet *set2 = new QBarSet("Map");

    set1->append(runningTimeBST[0]);
    set2->append(runningTimeBST[1]);

    series->append(set1);
    series->append(set2);
    chart->addSeries(series);
    chart->setTitle("Comparison of the time to load data between the two methods");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
//    for (size_t i = 0; i < 2 ; i++) {
//        categories.append(QString::fromStdString(xAxis[i]));
//    }
    categories << "load";
    axis->append(categories);
    chart->createDefaultAxes();
    chart->addAxis(axis, Qt::AlignBottom);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setParent(ui->chart);
    runningTimeBST.clear();
}

void MainWindow::on_reset_clicked()
{
    ui->DisplayResult->clear();
    runningTimeBST.clear();
    runningTimeMap.clear();
    if(series){
        chart->removeSeries(series);
        series->clear();
    }
    if(axis){
        chart->removeAxis(axis);
        axis->clear();
    }
    categories.clear();
//    for (size_t i = 0; i < xAxis.size() ; i++) {
//        QBarSet *set = new QBarSet(xAxis[i].c_str());
//        for (size_t j = 0; j < runningTimeBST.size() ; j++) {
//            set->append(runningTimeBST[j]);
//        }
//        series->append(set);
//        barSet.push_back(set);
//    }
    QBarSet *set1 = new QBarSet("BST");
    QBarSet *set2 = new QBarSet("Map");

    series->append(set1);
    series->append(set2);
    chart->addSeries(series);
    chart->setTitle("Comparison of the time to load data between the two methods");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
//    for (size_t i = 0; i < 2 ; i++) {
//        categories.append(QString::fromStdString(xAxis[i]));
//    }
    categories << "load";
    axis->append(categories);
    chart->createDefaultAxes();
    chart->addAxis(axis, Qt::AlignBottom);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setParent(ui->chart);
    runningTimeBST.clear();
}
