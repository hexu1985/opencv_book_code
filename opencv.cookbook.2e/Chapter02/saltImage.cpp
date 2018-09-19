/*------------------------------------------------------------------------------------------*\
   This file contains material supporting chapter 2 of the cookbook:  
   Computer Vision Programming using the OpenCV Library 
   Second Edition 
   by Robert Laganiere, Packt Publishing, 2013.

   This program is free software; permission is hereby granted to use, copy, modify, 
   and distribute this source code, or portions thereof, for any purpose, without fee, 
   subject to the restriction that the copyright notice may not be removed 
   or altered from any source or altered source distribution. 
   The software is released on an as-is basis and without any warranties of any kind. 
   In particular, the software is not guaranteed to be fault-tolerant or free from failure. 
   The author disclaims all warranties with regard to this software, any use, 
   and any consequent failure, is purely the responsibility of the user.
 
   Copyright (C) 2013 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h> // for std::rand

void salt(cv::Mat image, int n) {

	int i,j;
	for (int k=0; k<n; k++) {

		// rand() is the random number generator
		i= std::rand()%image.cols;
		j= std::rand()%image.rows;


		if (image.type() == CV_8UC1) { // gray-level image

			image.at<uchar>(j,i)= 255; 

		} else if (image.type() == CV_8UC3) { // color image

			image.at<cv::Vec3b>(j,i)[0]= 255; 
			image.at<cv::Vec3b>(j,i)[1]= 255; 
			image.at<cv::Vec3b>(j,i)[2]= 255; 
		}
	}
}

// This is an extra version of the function
// to illustrate the use of cv::Mat_
// works only for a 1-channel image
void salt2(cv::Mat image, int n) {

	// use image with a Mat_ template
	cv::Mat_<uchar> im2(image);
	
//  or with references:
//	cv::Mat_<uchar>& im2= reinterpret_cast<cv::Mat_<uchar>&>(image);

	int i,j;
	for (int k=0; k<n; k++) {

		// rand() is the MFC random number generator
		i= rand()%image.cols;
		j= rand()%image.rows;


		if (im2.type() == CV_8UC1) { // gray-level image

			im2(j,i)= 255; 

		} 
	}
}


int main()
{
	// open the image
	cv::Mat image= cv::imread("boldt.jpg",1);
    // image is resized for book printing
	cv::resize(image, image, cv::Size(), 0.6, 0.6);

	// call function to add noise
	salt(image,3000);

	// display result
	cv::namedWindow("Image");
	cv::imshow("Image",image);

	// write on disk
	cv::imwrite("salted.bmp",image);

	cv::waitKey();

	// test second version
	image= cv::imread("boldt.jpg",0);
    // image is resized for book printing
	cv::resize(image, image, cv::Size(), 0.6, 0.6);

	salt2(image, 500);

	cv::namedWindow("Image");
	cv::imshow("Image",image);

	cv::waitKey();

	return 0;
}


