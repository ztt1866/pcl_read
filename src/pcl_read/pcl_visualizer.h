#ifndef PCL_VISUALIZER_H
#define PCL_VISUALIZER_H

#include <QMainWindow>
#include<QFileDialog>
#include<QString>
#include<QLabel>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<iostream>
#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include<pcl/visualization/pcl_visualizer.h>
#include<pcl/io/pcd_io.h>
#include<opencv2/opencv.hpp>


#include<vtkRenderWindow.h>


//using namespace cv;


namespace Ui {
class pcl_visualizer;
}

class pcl_visualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit pcl_visualizer(QWidget *parent = 0);
    ~pcl_visualizer();

private slots:
    void onOpenpcl();
    void onOpenpic();

private:
    Ui::pcl_visualizer *ui;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer; //初始化vtk部件
    void initialVtkWidget();
    cv::Mat image;

};

#endif // PCL_VISUALIZER_H
