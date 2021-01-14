#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;



Mat src;

float s1, r1, s2, r2;

float contrast_strech(int intensity)
{
	if(intensity > 0 && intensity <= r1)
		return (s1/r1)*intensity;
	else if(intensity > r1 && intensity <= r2)
		return ((s2-s1) * (intensity-r1)/(r2-r1))+s1;
	else
		return ((255-s2) * (intensity-r2)/(255-r2))+s2;

}



int main()
{
	cout << "Enter r1:";
	cin >> r1;

	cout << "Enter s1:";
	cin >> s1;

	cout << "Enter r2:";
	cin >> r2;

	cout << "Enter s2:";
	cin >> s2;

	src=imread("lena.jpg");
	if (!src.data) {
		cout << "Bad image ..." << endl;
		return 0;
	}

	imshow("lena",src);
	//waitKey(0);

	Mat grayLena;
	cvtColor(src,grayLena,CV_BGR2GRAY);

	imshow("lenaGray",grayLena);
	waitKey(0);
	


	int row_size, col_size;

	row_size = grayLena.rows;
	col_size = grayLena.cols;

	for(float i=0;i<row_size;i++){
		for(float j=0; j<col_size;j++){
			uchar intensity =  grayLena.at<uchar>(i, j);
			grayLena.at<uchar>(i, j) = contrast_strech(intensity);
		}
	}

	imshow("lenaContrast",grayLena);
	waitKey(0);

	
    return 0;
}


