#include <iostream>
#include <string>
#include <stdlib.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#if CV_MAJOR_VERSION >= 3
#include <opencv2/imgproc.hpp>  // for cv::circle
#endif

using namespace std;

int main(int argc, char *argv[]) {
    std::string image_path = "puppy.bmp";

    cv::Mat image; 

    image = cv::imread(image_path);
    if (image.empty()) {
        cout << "read image file \"" << image_path << "\" failed.\n";
        exit(1);
    }

	cv::circle(image,              // destination image 
		       cv::Point(155,110), // center coordinate
			   65,                 // radius  
			   0,                  // color (here black)
			   3);                 // thickness

	cv::putText(image,                   // destination image
		        "This is a dog.",        // text
				cv::Point(40,200),       // text position
				cv::FONT_HERSHEY_PLAIN,  // font type
				2.0,                     // font scale
				255,                     // text color (here white)
				2);                      // text thickness

    cv::namedWindow("Drawing on an Image");

    cv::imshow("Drawing on an Image", image);

    cv::waitKey(0);

    return 0;
}


