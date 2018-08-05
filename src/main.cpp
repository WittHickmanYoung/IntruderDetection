#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>

int main()
{
    cv::VideoCapture cvCapture;
    cv::Mat frame;
    cv::Mat frame_show;
    cvCapture.open("rtsp://test:why123456@192.168.199.254/channel=1_stream=0.sdp?real_stream?tcp", cv::CAP_FFMPEG);
    double rate = cvCapture.get(CV_CAP_PROP_FPS);
    int delay = 1000 / 25;
    bool stop(false);
    std::string window_name("Camera");

    //cv::namedWindow(window_name, cv::WINDOW_NORMAL | cv::WINDOW_GUI_EXPANDED);
    cv::namedWindow(window_name);
    cv::resizeWindow(window_name, 1920, 1028);

    while (!stop)
    {
        if (true != cvCapture.grab())
            continue;

        cvCapture >> frame;

        if (frame.empty())
        {
            std::cout << "no video frame" << std::endl;
            //break;
            continue;
        }

        cv::resize(frame, frame_show, cv::Size(), 0.5, 0.5);

        int frame_num = cvCapture.get(CV_CAP_PROP_POS_FRAMES);

        std::cout << "Frame Num:" << frame_num << std::endl;

        cv::imshow(window_name, frame_show);
        cv::resizeWindow(window_name, 1920, 1028);

        if (cv::waitKey(delay) > 0)
            stop = true;
    }

    return 0;
}
