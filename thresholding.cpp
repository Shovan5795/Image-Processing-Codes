ch#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<cmath>
#include<math.h>

using namespace std;
using namespace cv;



int main(){
	Mat mat,src,g1,g2;
	int thres;
	cout<<"Enter the threshold value:";
	cin>>thres;
	mat=imread("lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	imshow("Original Image",mat);
	src=mat.clone();
	g1=mat.clone();
	g2=mat.clone();


	for(int i=0;i<src.rows;i++){
		for(int j=0;j<src.cols;j++){
			if(src.at<uchar>(i,j)<thres){
				src.at<uchar>(i,j)=0;
			}
			else{
				src.at<uchar>(i,j)=255;
			}
		}
	}

	float sum=0,sum1=0,sum2=0;
	float T,T2=0,m1,m2;
	int count=0,count2=0;
	for(int i=0;i<mat.rows;i++){
		for(int j=0;j<mat.cols;j++){
			sum=sum+mat.at<uchar>(i,j);
		}
	}

	T=sum/(mat.rows * mat.cols);
	cout<<T<<endl;

	while( abs(T-T2)<10){
		float sum1=0,sum2=0,count=0,count2=0;
		for(int i=0;i<mat.rows;i++){
			for(int j=0;j<mat.cols;j++){
				if(mat.at<uchar>(i,j)>=T){
					sum1=sum1+mat.at<uchar>(i,j);
					count++;
				}
				else{
					sum2=sum2+mat.at<uchar>(i,j);
					count2++;
			}

		}
	}
		T2=T;
		T=(sum1/count)+(sum2/count2);
		T=T/2;
}
	for(int i=0;i<mat.rows;i++){
		for(int j=0;j<mat.cols;j++){
			if(mat.at<uchar>(i,j)<T){
				mat.at<uchar>(i,j)=0;
			}
			else{
			    mat.at<uchar>(i,j)=255;
			}
		}
	}




	imshow("Binary Image",src);
	imshow("Global Threshhold Image",mat);

	waitKey(0);


	//T=sum/(mat.rows*mat.cols);
	//cout<<T;




}
