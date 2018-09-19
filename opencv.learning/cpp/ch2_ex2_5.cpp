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

Mat doPyrDown(
  Mat in,
  int       filter = CV_GAUSSIAN_5x5/* IPL_GAUSSIAN_5x5 */)
{

    Size in_size = in.size();
    // Best to make sure input image is divisible by two.
    //
    assert( in_size.width%2 == 0 && in_size.height%2 == 0 );

    Mat out = Mat( 
        Size( in_size.width/2, in_size.height/2 ),
        in.type()
    );
    pyrDown( in, out );
    return( out );
};

int main( int argc, char** argv )
{
  Mat img = imread( argv[1] );
  Mat img2; // = cvCreateImage( cvSize( img->width/2,img->height/2 ), img->depth, img->nChannels);
  namedWindow( "Example1", CV_WINDOW_AUTOSIZE );
  namedWindow( "Example2", CV_WINDOW_AUTOSIZE );
  imshow( "Example1", img );
  img2 = doPyrDown( img );
  imshow( "Example2", img2 );

  waitKey( 0 );

  destroyWindow("Example1");
  destroyWindow("Example2");
}
