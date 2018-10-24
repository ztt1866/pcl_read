#include "pcl_visualizer.h"
#include "ui_pcl_visualizer.h"

pcl_visualizer::pcl_visualizer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pcl_visualizer)
{
    ui->setupUi(this);
    //viewer.reset(new pcl::visualization::PCLVisualizer("viewer",false));
    //ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    //viewer->setupInteractor(ui->qvtkWidget->GetInteractor(),ui->qvtkWidget->GetRenderWindow());
   // ui->qvtkWidget->update();
    initialVtkWidget();

    connect(ui->pushButton_pcl,SIGNAL(clicked()),this,SLOT(onOpenpcl()));
    connect(ui->pushButton_pic,SIGNAL(clicked()),this,SLOT(onOpenpic()));
    //viewer->addPointCloud(cloud,"cloud");
    //pSliderValueChanged(2);
    //viewer->resetCamera();
   // ui->qvtkWidget->update();
}

void pcl_visualizer::initialVtkWidget(){
    cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer",false));
    viewer->addPointCloud(cloud,"cloud");

    ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui->qvtkWidget->GetInteractor(),ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->update();
}

//void pcl::visualizer()
//{

//}

pcl_visualizer::~pcl_visualizer()
{
    delete ui;
}

void pcl_visualizer::onOpenpcl()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open PointCloud"),".",tr("Open PCD files(*.pcd)"));

    if(!fileName.isEmpty())
    {
        std::string file_name = fileName.toStdString();
        pcl::PCLPointCloud2 cloud2;
        Eigen::Vector4f origin;
        Eigen::Quaternionf orientation;
        int pcd_version;
        int data_type;
        unsigned int data_idx;
        int offset = 0;
        pcl::PCDReader rd;
        rd.readHeader(file_name,cloud2,origin,orientation,pcd_version,data_type,data_idx);

        if(data_type ==0)
        {
            pcl::io::loadPCDFile(fileName.toStdString(),*cloud);
        }
        else if(data_type==2)
        {
            pcl::PCDReader reader;
            reader.read<pcl::PointXYZ>(fileName.toStdString(),*cloud);
        }

        viewer->updatePointCloud(cloud,"cloud");
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }

}

void pcl_visualizer::onOpenpic()
{
    QString picName = QFileDialog::getOpenFileName(this,tr("Open photo"),".",tr("Open photo files(*.pic *.png *.jpg *.jpeg *.bmp)"));
    image = cv::imread(picName.toLatin1().data());
    cv::cvtColor(image,image,CV_BGR2RGB);
    QImage img = QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->labelimage->setPixmap(QPixmap::fromImage(img));
    //ui->labelimage->resize(ui->labelimage->pixmap()->size());
   // ui->graphicsView->hide();

}
