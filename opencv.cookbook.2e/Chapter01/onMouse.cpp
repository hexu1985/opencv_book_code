#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

void onMouse( int event, int x, int y, int flags, void* param)	{
	
	cv::Mat *im= reinterpret_cast<cv::Mat*>(param);

    switch (event) {	// dispatch the event

		case CV_EVENT_LBUTTONDOWN: // mouse button down event

			// display pixel value at (x,y)
			cout << "at (" << x << "," << y << ") value is: " 
				      << static_cast<int>(im->at<uchar>(cv::Point(x,y))) << endl;
			break;
	}
}

int main(int argc, char *argv[]) {
    std::string image_path = "puppy.bmp";
    if (argc == 2) {
        image_path = argv[1];
    }

    cv::Mat image; 

    cout << "This image is " << image.rows << " x "
        << image.cols << endl;

    image = cv::imread(image_path);
    if (image.empty()) {
        cout << "read image file \"" << image_path << "\" failed.\n";
        exit(1);
    }

    cv::namedWindow("Original Image");

    cv::imshow("Original Image", image);

	cv::setMouseCallback("Original Image", onMouse, reinterpret_cast<void*>(&image));

    cv::waitKey(0);

    return 0;
}
