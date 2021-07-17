#include "MyTimer.h"
#include <iostream>
#include <string>

#include <opencv2/core.hpp>    // 基本图像数据处理
#include <opencv2/highgui.hpp> // 图像的读写以及图形界面的显示
#include <opencv2/video.hpp>   // 摄像头模块

// 定义需要或者允许的参数"{name_param | default_value | description}""
// @表示默认输入，name_param可以有多个，例如下面的[help ?]
const char *keys = {
    "{help h usage ? | | print this message}"
    "{@video | | Video file, if not defined try to use webcamera}"};

int main(int argc, const char **argv)
{
    cv::CommandLineParser parser(argc, argv, keys);
    // 获取help
    if (parser.has("help"))
    {
        parser.printMessage();
    }
    // 检查参数是否解析正确
    if (parser.check())
    {
        parser.printErrors();
    }
    // 获取命令行的信息
    std::string video_file = parser.get<std::string>("@video");
    std::cout << video_file << std::endl;
    // 打开摄像头
    cv::VideoCapture cap;
    if (video_file != "")
        cap.open(video_file);
    else
        cap.open(0);
    if (!cap.isOpened())
        std::cout << "Cant't open camrea." << std::endl;

    // 显示
    cv::namedWindow("Video", 1);
    while (true)
    {
        cv::Mat frame;
        cap >> frame;
        cv::imshow("Video", frame);
        if (cv::waitKey(30) >= 0)
            break;
    }
    cap.release();
    return 0;
}