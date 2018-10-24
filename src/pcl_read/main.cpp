#include "pcl_visualizer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pcl_visualizer w;
    w.show();

    return a.exec();
}
