#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/surface/mls.h>
#include <pcl/search/kdtree.h>

int main(int argc, char** argv) {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_downsampled(new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("../public/pcds/kitchen.pcd", *cloud) == -1){
        PCL_ERROR("couldn't read file");
        return 0;
    }

    std::cout << "Loaded " << cloud->width * cloud->height
              << " data points" << std::endl;
              
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    
    // 输出的PointCloud中有PointNormal类型，用来存储 MLS 算出的法线
    pcl::PointCloud<pcl::PointNormal> mls_points;

    // 定义 MovingLeastSquares 对象并设置参数
    pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointNormal> mls;
    mls.setComputeNormals(true);
    mls.setInputCloud(cloud);
    mls.setSearchMethod(tree);
    mls.setSearchRadius(30);

    // 曲面重建
    mls.process(mls_points);

    //std::cout << "downsampled cloud size: " << mls_points->width * mls_points->height << std::endl;


    // 使用PCLVisualizer进行可视化
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("MLS Cloud Viewer"));
    viewer->addPointCloud<pcl::PointNormal>(mls_points.makeShared(), "MLS Cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "MLS Cloud");
    viewer->addPointCloudNormals<pcl::PointNormal>(mls_points.makeShared(), 1, 0.05, "normals");  // 可选：显示法线
    viewer->saveScreenshot("screenshot.png");
    while (!viewer->wasStopped())
    {
        viewer->spinOnce(100);
    }
    return 0;
}
