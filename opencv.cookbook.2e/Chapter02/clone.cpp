#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void colorReduce(cv::Mat image, int div=64) {

      int nl= image.rows; // number of lines
      int nc= image.cols * image.channels(); // total number of elements per line

      for (int j=0; j<nl; j++) {

          // get the address of row j
          uchar* data= image.ptr<uchar>(j);

          for (int i=0; i<nc; i++) {

            // process each pixel ---------------------

                data[i]= data[i]/div*div + div/2;

            // end of pixel processing ----------------

          } // end of line
      }
}

int main()
{
    cv::Mat image= cv::imread("boldt.jpg");

    cv::Mat imageClone = image.clone();

    colorReduce(imageClone, 64);

    cv::namedWindow("Original Image");
    cv::imshow("Original Image",image);

    cv::namedWindow("Image colorReduce");
    cv::imshow("Image colorReduce",imageClone);

    cv::waitKey();

    return 0;
}
