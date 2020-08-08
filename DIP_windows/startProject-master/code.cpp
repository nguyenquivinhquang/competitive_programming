#include <opencv2/highgui.hpp>
int main()
{
    cv::Mat image;
    image = cv::imread("dog.png", cv::IMREAD_COLOR);
    cv::imshow("test", image);
    cv::waitKey(0);
    return 0;
}
