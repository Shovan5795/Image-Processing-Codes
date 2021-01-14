#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<cmath>
#include<math.h>

using namespace std;
using namespace cv;

Mat src, dst,dstf, fimg, fin;

float kernel[9]={-1,0,-1,
                 0,4,0,
                 -1,0,-1};
Mat kernel1 = Mat(3,3,CV_32F,kernel);

int kernel_scal[9]={-1,0,-1,
	                 0,5,0,
				    -1,0,-1};



int main(){
	src= imread("blurry_moon.tif",0);
	imshow("Original image",src);
	
	filter2D(src,dst, CV_32F,kernel1,Point(-1,-1));
	imshow("filtered image",dst);

	normalize(dst,dstf,0,255,NORM_MINMAX, CV_8U);
	imshow("Normalized image",dstf);
	
	addWeighted(src,0.5,dstf,0.5,0,fimg);
	imshow("adding image",fimg);

	normalize(fimg,fin,0,255,NORM_MINMAX, CV_8U);

	imshow("final norm",fin);
	waitKey(0);






}