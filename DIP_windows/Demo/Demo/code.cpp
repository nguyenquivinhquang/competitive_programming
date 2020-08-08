#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int main()
{
	Mat image = imread("demo.jpg");
	imshow("Demo", image);

	waitKey(0);
	return 0;
}