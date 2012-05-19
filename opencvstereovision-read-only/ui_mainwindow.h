/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat May 19 05:02:37 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonCalibrate;
    QSpinBox *spinBoxSampleCount;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBoxInterval;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBoxCornersX;
    QSpinBox *spinBoxCornersY;
    QLabel *label_5_t;
    QLineEdit *lineEditFilename;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QLabel *labelSampleTimeout;
    QProgressBar *progressBar;
    QLCDNumber *lcdNumber;
    QPushButton *CaptureButton;
    QPushButton *CloseButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QSlider *horizontalSlider_7;
    QSlider *horizontalSlider_8;
    QSlider *horizontalSlider_9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *tab_2;
    QPlainTextEdit *plainTextEditTrace;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(546, 583);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(200, 200));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonCalibrate = new QPushButton(centralWidget);
        pushButtonCalibrate->setObjectName(QString::fromUtf8("pushButtonCalibrate"));
        pushButtonCalibrate->setEnabled(false);
        pushButtonCalibrate->setGeometry(QRect(400, 60, 131, 51));
        spinBoxSampleCount = new QSpinBox(centralWidget);
        spinBoxSampleCount->setObjectName(QString::fromUtf8("spinBoxSampleCount"));
        spinBoxSampleCount->setGeometry(QRect(170, 40, 46, 20));
        spinBoxSampleCount->setMinimum(3);
        spinBoxSampleCount->setValue(10);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 111, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 151, 41));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        spinBoxInterval = new QSpinBox(centralWidget);
        spinBoxInterval->setObjectName(QString::fromUtf8("spinBoxInterval"));
        spinBoxInterval->setGeometry(QRect(170, 70, 46, 21));
        spinBoxInterval->setMinimum(0);
        spinBoxInterval->setValue(5);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 151, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 151, 20));
        spinBoxCornersX = new QSpinBox(centralWidget);
        spinBoxCornersX->setObjectName(QString::fromUtf8("spinBoxCornersX"));
        spinBoxCornersX->setGeometry(QRect(170, 100, 46, 20));
        spinBoxCornersX->setMinimum(3);
        spinBoxCornersX->setValue(10);
        spinBoxCornersY = new QSpinBox(centralWidget);
        spinBoxCornersY->setObjectName(QString::fromUtf8("spinBoxCornersY"));
        spinBoxCornersY->setGeometry(QRect(170, 130, 46, 20));
        spinBoxCornersY->setMinimum(3);
        spinBoxCornersY->setValue(7);
        label_5_t = new QLabel(centralWidget);
        label_5_t->setObjectName(QString::fromUtf8("label_5_t"));
        label_5_t->setGeometry(QRect(10, 160, 111, 20));
        lineEditFilename = new QLineEdit(centralWidget);
        lineEditFilename->setObjectName(QString::fromUtf8("lineEditFilename"));
        lineEditFilename->setGeometry(QRect(140, 160, 251, 20));
        pushButtonLoad = new QPushButton(centralWidget);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setEnabled(true);
        pushButtonLoad->setGeometry(QRect(400, 160, 61, 21));
        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setEnabled(false);
        pushButtonSave->setGeometry(QRect(470, 160, 61, 21));
        labelSampleTimeout = new QLabel(centralWidget);
        labelSampleTimeout->setObjectName(QString::fromUtf8("labelSampleTimeout"));
        labelSampleTimeout->setGeometry(QRect(220, 40, 181, 20));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(220, 130, 311, 23));
        progressBar->setMaximum(10);
        progressBar->setValue(0);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(220, 60, 171, 51));
        lcdNumber->setFrameShape(QFrame::Panel);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        CaptureButton = new QPushButton(centralWidget);
        CaptureButton->setObjectName(QString::fromUtf8("CaptureButton"));
        CaptureButton->setGeometry(QRect(10, 10, 98, 27));
        CloseButton = new QPushButton(centralWidget);
        CloseButton->setObjectName(QString::fromUtf8("CloseButton"));
        CloseButton->setGeometry(QRect(120, 10, 98, 27));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 180, 501, 391));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(160, 20, 211, 311));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(verticalLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(5);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setSingleStep(2);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        horizontalSlider_2 = new QSlider(verticalLayoutWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_2);

        horizontalSlider_3 = new QSlider(verticalLayoutWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_3);

        horizontalSlider_4 = new QSlider(verticalLayoutWidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_4);

        horizontalSlider_5 = new QSlider(verticalLayoutWidget);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_5);

        horizontalSlider_6 = new QSlider(verticalLayoutWidget);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_6);

        horizontalSlider_7 = new QSlider(verticalLayoutWidget);
        horizontalSlider_7->setObjectName(QString::fromUtf8("horizontalSlider_7"));
        horizontalSlider_7->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_7);

        horizontalSlider_8 = new QSlider(verticalLayoutWidget);
        horizontalSlider_8->setObjectName(QString::fromUtf8("horizontalSlider_8"));
        horizontalSlider_8->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_8);

        horizontalSlider_9 = new QSlider(verticalLayoutWidget);
        horizontalSlider_9->setObjectName(QString::fromUtf8("horizontalSlider_9"));
        horizontalSlider_9->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_9);

        verticalLayoutWidget_2 = new QWidget(tab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 143, 311));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_3->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_3->addWidget(label_13);

        verticalLayoutWidget_3 = new QWidget(tab);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(379, 20, 111, 311));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_4->addWidget(label_14);

        label_15 = new QLabel(verticalLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_4->addWidget(label_15);

        label_16 = new QLabel(verticalLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_4->addWidget(label_16);

        label_17 = new QLabel(verticalLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_4->addWidget(label_17);

        label_18 = new QLabel(verticalLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_4->addWidget(label_18);

        label_19 = new QLabel(verticalLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_4->addWidget(label_19);

        label_20 = new QLabel(verticalLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_4->addWidget(label_20);

        label_21 = new QLabel(verticalLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_4->addWidget(label_21);

        label_22 = new QLabel(verticalLayoutWidget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_4->addWidget(label_22);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        plainTextEditTrace = new QPlainTextEdit(tab_2);
        plainTextEditTrace->setObjectName(QString::fromUtf8("plainTextEditTrace"));
        plainTextEditTrace->setGeometry(QRect(10, 10, 471, 331));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEditTrace->sizePolicy().hasHeightForWidth());
        plainTextEditTrace->setSizePolicy(sizePolicy1);
        plainTextEditTrace->setReadOnly(true);
        plainTextEditTrace->setMaximumBlockCount(1000);
        tabWidget->addTab(tab_2, QString());
        plainTextEditTrace->raise();
        plainTextEditTrace->raise();
        plainTextEditTrace->raise();
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(CaptureButton, CloseButton);
        QWidget::setTabOrder(CloseButton, pushButtonCalibrate);
        QWidget::setTabOrder(pushButtonCalibrate, spinBoxSampleCount);
        QWidget::setTabOrder(spinBoxSampleCount, spinBoxInterval);
        QWidget::setTabOrder(spinBoxInterval, spinBoxCornersX);
        QWidget::setTabOrder(spinBoxCornersX, spinBoxCornersY);
        QWidget::setTabOrder(spinBoxCornersY, pushButtonLoad);
        QWidget::setTabOrder(pushButtonLoad, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, lineEditFilename);
        QWidget::setTabOrder(lineEditFilename, tabWidget);
        QWidget::setTabOrder(tabWidget, horizontalSlider);
        QWidget::setTabOrder(horizontalSlider, horizontalSlider_2);
        QWidget::setTabOrder(horizontalSlider_2, horizontalSlider_3);
        QWidget::setTabOrder(horizontalSlider_3, horizontalSlider_4);
        QWidget::setTabOrder(horizontalSlider_4, horizontalSlider_5);
        QWidget::setTabOrder(horizontalSlider_5, horizontalSlider_6);
        QWidget::setTabOrder(horizontalSlider_6, horizontalSlider_7);
        QWidget::setTabOrder(horizontalSlider_7, horizontalSlider_8);
        QWidget::setTabOrder(horizontalSlider_8, horizontalSlider_9);
        QWidget::setTabOrder(horizontalSlider_9, plainTextEditTrace);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label_14, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), label_15, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), label_16, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_4, SIGNAL(valueChanged(int)), label_17, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_5, SIGNAL(valueChanged(int)), label_18, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_6, SIGNAL(valueChanged(int)), label_19, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_7, SIGNAL(valueChanged(int)), label_20, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_8, SIGNAL(valueChanged(int)), label_21, SLOT(setNum(int)));
        QObject::connect(horizontalSlider_9, SIGNAL(valueChanged(int)), label_22, SLOT(setNum(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Stereo Calibration", 0, QApplication::UnicodeUTF8));
        pushButtonCalibrate->setText(QApplication::translate("MainWindow", "Start Calibration", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Number of Samples:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Auto Sample Interval (seconds, 0=manual):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Chessboard Corners X:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Chessboard Corners Y:", 0, QApplication::UnicodeUTF8));
        label_5_t->setText(QApplication::translate("MainWindow", "Calibration File:", 0, QApplication::UnicodeUTF8));
        lineEditFilename->setText(QApplication::translate("MainWindow", "calibration.dat", 0, QApplication::UnicodeUTF8));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        labelSampleTimeout->setText(QApplication::translate("MainWindow", "Seconds till next sample:", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QApplication::translate("MainWindow", "%v of %m Calibration Samples Taken", 0, QApplication::UnicodeUTF8));
        CaptureButton->setText(QApplication::translate("MainWindow", "Capture", 0, QApplication::UnicodeUTF8));
        CloseButton->setText(QApplication::translate("MainWindow", "close", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Pre-Filter Size", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Pre-Filter Cap", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "SAD Window Size", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Min. Disparity", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Num. of Disp", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Texture Threshold", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Uniqueness Ratio", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Speckle Window Size", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Speckle Range", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "BM tune", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "trace progress", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
