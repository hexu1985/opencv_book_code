/* License:
   Oct. 3, 2008
   Right to use this code in any way you want without warrenty, support or any guarentee of it working.

   BOOK: It would be nice if you cited it:
   Learning OpenCV: Computer Vision with the OpenCV Library
     by Gary Bradski and Adrian Kaehler
     Published by O'Reilly Media, October 3, 2008
 
   AVAILABLE AT: 
     http://www.amazon.com/Learning-OpenCV-Computer-Vision-Library/dp/0596516134
     Or: http://oreilly.com/catalog/9780596516130/
     ISBN-10: 0596516134 or: ISBN-13: 978-0596516130    

   OTHER OPENCV SITES:
   * The source code is on sourceforge at:
     http://sourceforge.net/projects/opencvlibrary/
   * The OpenCV wiki page (As of Oct 1, 2008 this is down for changing over servers, but should come back):
     http://opencvlibrary.sourceforge.net/
   * An active user group is at:
     http://tech.groups.yahoo.com/group/OpenCV/
   * The minutes of weekly OpenCV development meetings are at:
     http://pr.willowgarage.com/wiki/OpenCV
*/
#include <opencv2/opencv.hpp>

using namespace cv;

Mat doCanny(
    Mat in,
    double    lowThresh,
    double    highThresh,
    double    aperture)
{
    if (in.channels() != 1)
        return Mat(); // Canny only handles gray scale images
    Mat out;
    Canny( in, out, lowThresh, highThresh, aperture );
    return( out );
};

int main( int argc, char** argv )
{
  Mat img_rgb = imread( argv[1] );
  Mat img_gry; 
  cvtColor(img_rgb, img_gry ,CV_BGR2GRAY);
  namedWindow( "Example Gray", CV_WINDOW_AUTOSIZE );
  namedWindow( "Example Canny", CV_WINDOW_AUTOSIZE );
  imshow( "Example Gray", img_gry );
  Mat img_cny = doCanny( img_gry, 10, 100, 3 );
  imshow( "Example Canny", img_cny );
  waitKey( 0 );
  destroyWindow( "Example Gray" );
  destroyWindow( "Example Canny" );
}
