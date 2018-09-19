#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "usage: isContinuous image\n";
        exit(1);
    }

    std::string image_path = argv[1];

    cv::Mat image; 

    image = cv::imread(image_path);
    if (image.empty()) {
        cout << "read image file \"" << image_path << "\" failed.\n";
        exit(1);
    }

    cout << "This image is " << image.rows << " x "
        << image.cols << endl;

    cout << "image isContinuous ? " << boolalpha << image.isContinuous() << "\n";
    assert((image.step == image.cols*image.elemSize()) == image.isContinuous());

    return 0;
}


