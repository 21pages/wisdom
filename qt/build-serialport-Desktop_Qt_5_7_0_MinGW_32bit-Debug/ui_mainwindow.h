/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *portNameLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsBox;
    QComboBox *portNameBox;
    QLabel *paudRateLabel;
    QLabel *dataBitsLabel;
    QComboBox *baudRateBox;
    QSpacerItem *verticalSpacer;
    QPushButton *openButton;
    QVBoxLayout *verticalLayout;
    QLabel *getLabel;
    QTextEdit *getEdit;
    QLabel *sendLabel;
    QTextEdit *sendEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearButton;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(463, 467);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 22, 432, 364));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        portNameLabel = new QLabel(groupBox);
        portNameLabel->setObjectName(QStringLiteral("portNameLabel"));

        gridLayout->addWidget(portNameLabel, 0, 0, 1, 1);

        dataBitsBox = new QComboBox(groupBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        gridLayout->addWidget(dataBitsBox, 2, 1, 1, 1);

        parityLabel = new QLabel(groupBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        gridLayout->addWidget(parityLabel, 3, 0, 1, 1);

        parityBox = new QComboBox(groupBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        gridLayout->addWidget(parityBox, 3, 1, 1, 1);

        stopBitsLabel = new QLabel(groupBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));

        gridLayout->addWidget(stopBitsLabel, 4, 0, 1, 1);

        stopBitsBox = new QComboBox(groupBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        gridLayout->addWidget(stopBitsBox, 4, 1, 1, 1);

        portNameBox = new QComboBox(groupBox);
        portNameBox->setObjectName(QStringLiteral("portNameBox"));

        gridLayout->addWidget(portNameBox, 0, 1, 1, 1);

        paudRateLabel = new QLabel(groupBox);
        paudRateLabel->setObjectName(QStringLiteral("paudRateLabel"));

        gridLayout->addWidget(paudRateLabel, 1, 0, 1, 1);

        dataBitsLabel = new QLabel(groupBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));

        gridLayout->addWidget(dataBitsLabel, 2, 0, 1, 1);

        baudRateBox = new QComboBox(groupBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        gridLayout->addWidget(baudRateBox, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        openButton = new QPushButton(widget);
        openButton->setObjectName(QStringLiteral("openButton"));

        verticalLayout_2->addWidget(openButton);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        getLabel = new QLabel(widget);
        getLabel->setObjectName(QStringLiteral("getLabel"));

        verticalLayout->addWidget(getLabel);

        getEdit = new QTextEdit(widget);
        getEdit->setObjectName(QStringLiteral("getEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(getEdit->sizePolicy().hasHeightForWidth());
        getEdit->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(getEdit);

        sendLabel = new QLabel(widget);
        sendLabel->setObjectName(QStringLiteral("sendLabel"));

        verticalLayout->addWidget(sendLabel);

        sendEdit = new QTextEdit(widget);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sizePolicy1.setHeightForWidth(sendEdit->sizePolicy().hasHeightForWidth());
        sendEdit->setSizePolicy(sizePolicy1);
        sendEdit->setMaximumSize(QSize(16777215, 80));

        verticalLayout->addWidget(sendEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        clearButton = new QPushButton(widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        openButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 463, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\267\245\345\205\2671.0", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\351\241\271", 0));
        portNameLabel->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", 0));
        parityLabel->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0));
        stopBitsLabel->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0));
        paudRateLabel->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0));
        dataBitsLabel->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0));
        openButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        getLabel->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", 0));
        sendLabel->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", 0));
        clearButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", 0));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
