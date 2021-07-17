#include "MyTimer.h"
#include <iostream>
#include <string>

#include <opencv2/core.hpp>    // 基本图像数据处理
#include <opencv2/highgui.hpp> // 图像的读写以及图形界面的显示

int main(int argc, const char **argv)
{
    {
        cv::Mat color = cv::imread("/home/wyz/codes/OpenCV/source/car.jpeg");
        cv::Mat gray = cv::imread("/home/wyz/codes/OpenCV/source/cat.jpeg", cv::IMREAD_GRAYSCALE);
        // cv::Mat gray = cv::imread("source/cat.jpeg", cv::IMREAD_COLOR);  // 读取彩色图片 BGR通道
        if (!color.data)
        {
            std::cout << "Can't open img." << std::endl;
            return -1;
        }
        cv::imwrite("/home/wyz/codes/OpenCV/source/gray.jpg", gray);
        cv::imshow("Gray", gray);
        cv::waitKey(0);
    }
    return 0;
}