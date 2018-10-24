/********************************************************************************
** Form generated from reading UI file 'pcl_visualizer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCL_VISUALIZER_H
#define UI_PCL_VISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_pcl_visualizer
{
public:
    QWidget *centralWidget;
    QVTKWidget *qvtkWidget;
    QPushButton *pushButton_pcl;
    QPushButton *pushButton_pic;
    QLabel *labelimage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pcl_visualizer)
    {
        if (pcl_visualizer->objectName().isEmpty())
            pcl_visualizer->setObjectName(QStringLiteral("pcl_visualizer"));
        pcl_visualizer->resize(916, 485);
        centralWidget = new QWidget(pcl_visualizer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(450, 30, 461, 381));
        pushButton_pcl = new QPushButton(centralWidget);
        pushButton_pcl->setObjectName(QStringLiteral("pushButton_pcl"));
        pushButton_pcl->setGeometry(QRect(210, 0, 99, 27));
        pushButton_pic = new QPushButton(centralWidget);
        pushButton_pic->setObjectName(QStringLiteral("pushButton_pic"));
        pushButton_pic->setGeometry(QRect(50, 0, 99, 27));
        labelimage = new QLabel(centralWidget);
        labelimage->setObjectName(QStringLiteral("labelimage"));
        labelimage->setGeometry(QRect(6, 36, 441, 371));
        pcl_visualizer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(pcl_visualizer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 916, 31));
        pcl_visualizer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pcl_visualizer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pcl_visualizer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(pcl_visualizer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pcl_visualizer->setStatusBar(statusBar);

        retranslateUi(pcl_visualizer);

        QMetaObject::connectSlotsByName(pcl_visualizer);
    } // setupUi

    void retranslateUi(QMainWindow *pcl_visualizer)
    {
        pcl_visualizer->setWindowTitle(QApplication::translate("pcl_visualizer", "pcl_visualizer", 0));
        pushButton_pcl->setText(QApplication::translate("pcl_visualizer", "open_pcd", 0));
        pushButton_pic->setText(QApplication::translate("pcl_visualizer", "open_pic", 0));
        labelimage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pcl_visualizer: public Ui_pcl_visualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCL_VISUALIZER_H
