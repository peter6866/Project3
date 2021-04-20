/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *DisplayResult;
    QLineEdit *fun2_2;
    QPushButton *loadData;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_11;
    QLineEdit *fun3_1;
    QFrame *chart;
    QHBoxLayout *horizontalLayout;
    QLineEdit *fun1_1;
    QLineEdit *fun2_1;
    QLineEdit *lineEdit_13;
    QLineEdit *fun1_2;
    QLineEdit *fun1_3;
    QLineEdit *lineEdit;
    QLineEdit *Display;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *reset;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        DisplayResult = new QTextEdit(centralwidget);
        DisplayResult->setObjectName(QString::fromUtf8("DisplayResult"));
        DisplayResult->setReadOnly(true);

        gridLayout->addWidget(DisplayResult, 8, 0, 1, 2);

        fun2_2 = new QLineEdit(centralwidget);
        fun2_2->setObjectName(QString::fromUtf8("fun2_2"));

        gridLayout->addWidget(fun2_2, 4, 3, 1, 1);

        loadData = new QPushButton(centralwidget);
        loadData->setObjectName(QString::fromUtf8("loadData"));

        gridLayout->addWidget(loadData, 1, 0, 1, 6);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(8);
        lineEdit_3->setFont(font);
        lineEdit_3->setFrame(false);
        lineEdit_3->setReadOnly(true);

        gridLayout->addWidget(lineEdit_3, 4, 0, 1, 1);

        lineEdit_9 = new QLineEdit(centralwidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setFont(font);
        lineEdit_9->setFrame(false);
        lineEdit_9->setReadOnly(true);

        gridLayout->addWidget(lineEdit_9, 3, 2, 1, 1);

        lineEdit_11 = new QLineEdit(centralwidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setFont(font);
        lineEdit_11->setFrame(false);
        lineEdit_11->setReadOnly(true);

        gridLayout->addWidget(lineEdit_11, 4, 2, 1, 1);

        fun3_1 = new QLineEdit(centralwidget);
        fun3_1->setObjectName(QString::fromUtf8("fun3_1"));

        gridLayout->addWidget(fun3_1, 4, 5, 1, 1);

        chart = new QFrame(centralwidget);
        chart->setObjectName(QString::fromUtf8("chart"));
        horizontalLayout = new QHBoxLayout(chart);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addWidget(chart, 8, 2, 1, 4);

        fun1_1 = new QLineEdit(centralwidget);
        fun1_1->setObjectName(QString::fromUtf8("fun1_1"));

        gridLayout->addWidget(fun1_1, 2, 1, 1, 1);

        fun2_1 = new QLineEdit(centralwidget);
        fun2_1->setObjectName(QString::fromUtf8("fun2_1"));

        gridLayout->addWidget(fun2_1, 3, 3, 1, 1);

        lineEdit_13 = new QLineEdit(centralwidget);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setFont(font);
        lineEdit_13->setFrame(false);
        lineEdit_13->setReadOnly(true);

        gridLayout->addWidget(lineEdit_13, 4, 4, 1, 1);

        fun1_2 = new QLineEdit(centralwidget);
        fun1_2->setObjectName(QString::fromUtf8("fun1_2"));

        gridLayout->addWidget(fun1_2, 3, 1, 1, 1);

        fun1_3 = new QLineEdit(centralwidget);
        fun1_3->setObjectName(QString::fromUtf8("fun1_3"));

        gridLayout->addWidget(fun1_3, 4, 1, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);
        lineEdit->setFrame(false);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        Display->setFrame(false);
        Display->setReadOnly(true);

        gridLayout->addWidget(Display, 0, 0, 1, 6);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);
        lineEdit_2->setFrame(false);
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 3, 0, 1, 1);

        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));

        gridLayout->addWidget(pushButton_1, 7, 0, 1, 2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 2, 1, 2);

        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));

        gridLayout->addWidget(reset, 2, 5, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 7, 4, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(Display, loadData);
        QWidget::setTabOrder(loadData, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, fun1_1);
        QWidget::setTabOrder(fun1_1, fun1_2);
        QWidget::setTabOrder(fun1_2, fun1_3);
        QWidget::setTabOrder(fun1_3, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, lineEdit_11);
        QWidget::setTabOrder(lineEdit_11, fun2_1);
        QWidget::setTabOrder(fun2_1, fun2_2);
        QWidget::setTabOrder(fun2_2, lineEdit_13);
        QWidget::setTabOrder(lineEdit_13, fun3_1);
        QWidget::setTabOrder(fun3_1, pushButton_1);
        QWidget::setTabOrder(pushButton_1, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        fun2_2->setText(QCoreApplication::translate("MainWindow", "New Youk NY", nullptr));
        loadData->setText(QCoreApplication::translate("MainWindow", "load data", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Year:", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "Origin City:", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "Destination City:", nullptr));
        fun3_1->setText(QCoreApplication::translate("MainWindow", "Los Angeles CA", nullptr));
        fun1_1->setText(QCoreApplication::translate("MainWindow", "Atlanta GA", nullptr));
        fun2_1->setText(QCoreApplication::translate("MainWindow", "Chicago IL", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "City Name:", nullptr));
        fun1_2->setText(QCoreApplication::translate("MainWindow", "Los Angeles CA", nullptr));
        fun1_3->setText(QCoreApplication::translate("MainWindow", "2001", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "Origin City:", nullptr));
        Display->setInputMask(QString());
        Display->setText(QCoreApplication::translate("MainWindow", "Please load data first!", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "Destination City:", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "function 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "function 2", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "reset graphic", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "function 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
