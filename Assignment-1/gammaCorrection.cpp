#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;



Mat src, dst;



int main( int argc, char** argv )
{
   
	src=imread("lena.jpg");
    
	imshow("lena",src);
	waitKey(0);

	Mat grayLena;
	cvtColor(src,grayLena,CV_BGR2GRAY);

	imshow("lenaGray",grayLena);
	waitKey(0);
	//dst=grayLena;

	int row_size, col_size;

	row_size = grayLena.rows;
	col_size = grayLena.cols;


    int c=1;
	float g;
	cout<<"Enter gamma value:";
	cin>>g;
	for(int i=0;i<row_size;i++){
		for(int j=0; j<col_size;j++){
			uchar intensity =  grayLena.at<uchar>(i, j);
			grayLena.at<uchar>(i, j) = c * pow(intensity,g);
		}
	}

	imshow("lenaGamma",grayLena);
	waitKey(0);


    return 0;
}


