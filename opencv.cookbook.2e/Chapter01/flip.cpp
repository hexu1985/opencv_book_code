#include <iostream>
#include <string>
#include <stdlib.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: flip image_path result_path\n";
        exit(1);
    }

    std::string image_path = argv[1];
    std::string result_path = argv[2];

    cv::Mat image; 

    image = cv::imread(image_path);
    if (image.empty()) {
        cout << "read image file \"" << image_path << "\" failed.\n";
        exit(1);
    }
    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);

    cv::Mat result;
    cv::flip(image, result, 1);

    cv::namedWindow("Output Image");
    cv::imshow("Output Image", result);

    cv::imwrite(argv[2], result);

    cv::waitKey(0);

    return 0;
}


