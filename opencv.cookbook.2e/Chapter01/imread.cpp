#include <iostream>
#include <string>
#include <stdlib.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

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

    cv::waitKey(0);

    return 0;
}


