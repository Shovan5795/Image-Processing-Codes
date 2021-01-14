#include<iostream>
#include<cmath>
#include<algorithm>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat src,dst,hist;

int main(){
	src=imread("hist1.tif");
	cvtColor(src, src, CV_BGR2GRAY);
	
	imshow("Original",src);
	waitKey(0);
	
	
	//dst=src.clone();
	hist.create(300,256,CV_8UC1);
	hist.setTo(0);

	float histogram[256];
	float h[256];
	for(int i=0;i<256;i++){
		histogram[i]=0.0;
		h[i]=0.0;
	}

	for(int y=0;y<src.rows;y++){
		for(int x=0;x<src.cols;x++){
			histogram[(int)src.at<uchar>(y,x)]++;
		}
	}

	for(int i=0;i<256;i++){
		//cout<<histogram[i]<<endl;
		
	     h[i]= histogram[i]/(src.rows * src.cols * 1.0);
		 
		// cout<<h[i]<<endl;
	}

	for(int i=0;i<256;i++){
		int j=h[i];
		for(j=299-j;j<300;j++){
			hist.at<uchar>(j,i)=255;
		}
	}

	imshow("histogram",hist);
	waitKey(0);
	
}