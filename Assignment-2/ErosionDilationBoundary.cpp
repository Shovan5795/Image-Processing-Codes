#include<iostream>
#include<cmath>
#include<algorithm>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat srce,dese,srcd,desd,srcb,desb;

void erosion(){
	srce = imread("e.tif");
	dese = srce.clone();
	
	int k;
	cout<<"The value of the mask size:";
	cin>>k;
	imshow("original",srce);
	waitKey(0);
	int kernel[100][100];
    for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			kernel[i][j]=255;
		}
	}
	int top;
	top=k/2;
	
	
	cvtColor(srce, dese, CV_BGR2GRAY);
	threshold( dese, dese, 128,255,THRESH_BINARY );
    imshow("binary",dese);
	waitKey(0);

	copyMakeBorder(dese,dese,top,top,top,top,BORDER_CONSTANT,0);

	for(int i=0;i<dese.rows;i++)
	 {
		 int Row = k+i;
		 for(int j=0;j<dese.cols;j++)
		 {
			 int Col = k+j;

			 int check = 0;
			 for(int m=i,x=0;m<Row&&Row-1<dese.rows;m++,x++)
			 {
				 for(int n=j,y=0;n<Col&&Col-1<dese.cols;n++,y++)
				 {
					 int value = dese.at<uchar>(m,n);

					 if(value!=kernel[x][y])
					 {
						 dese.at<uchar>(i,j)=0;
						 check=1;
						 break;
					 }
				 }
				if(check)
					 break;
			 }

		 }
	 }

	imshow("erosion",dese);
	waitKey(0);

}



void dilation(){

	srcd = imread("d.tif");
	desd = srcd.clone();
	int k;
	cout<<"The value of the mask size:";
	cin>>k;
	imshow("original",srcd);
	waitKey(0);
	int kernel[100][100];
    for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			kernel[i][j]=255;
		}
	}
	int top;
	top=k/2;
	
	
	cvtColor(srcd, desd, CV_BGR2GRAY);
	threshold( desd, desd, 128,255,THRESH_BINARY );
    imshow("binary",desd);
	waitKey(0);

	copyMakeBorder(desd,desd,top,top,top,top,BORDER_CONSTANT,0);

	for(int i=0;i<desd.rows;i++)
	 {
		 int Row = k+i;
		 for(int j=0;j<desd.cols;j++)
		 {
			 int Col = k+j;

			 int check = 0;
			 for(int m=i,x=0;m<Row&&Row-1<desd.rows;m++,x++)
			 {
				 for(int n=j,y=0;n<Col&&Col-1<desd.cols;n++,y++)
				 {
					 int value = desd.at<uchar>(m,n);

					 if(value!=kernel[x][y])
					 {
						 desd.at<uchar>(i,j)=0;
						 check=1;
						 break;
					 }
				 }
				if(check)
					 break;
			 }

		 }
	 }

	imshow("erosion1",desd);
	waitKey(0);



	for(int i=0;i<desd.rows;i++)
	 {
		 int Row = k+i;
		 for(int j=0;j<desd.cols;j++)
		 {
			 int Col = k+j;

			 int check = 0;
			 for(int m=i,x=0;m<Row&&Row-1<desd.rows;m++,x++)
			 {
				 for(int n=j,y=0;n<Col&&Col-1<desd.cols;n++,y++)
				 {
					 int value = desd.at<uchar>(m,n);

					 if(value==kernel[x][y])
					 {
						 desd.at<uchar>(i,j)=kernel[x][y];
						 check=1;
						 break;
					 }
				 }
				if(check)
					 break;
			 }

		 }
	 }

	

	imshow("dilation1",desd);
	waitKey(0);


	for(int i=0;i<desd.rows;i++)
	 {
		 int Row = k+i;
		 for(int j=0;j<desd.cols;j++)
		 {
			 int Col = k+j;

			 int check = 0;
			 for(int m=i,x=0;m<Row&&Row-1<desd.rows;m++,x++)
			 {
				 for(int n=j,y=0;n<Col&&Col-1<desd.cols;n++,y++)
				 {
					 int value = desd.at<uchar>(m,n);

					 if(value==kernel[x][y])
					 {
						 desd.at<uchar>(i,j)=kernel[x][y];
						 check=1;
						 break;
					 }
				 }
				if(check)
					 break;
			 }

		 }
	 }

	

	imshow("dilation2",desd);
	waitKey(0);

	for(int i=0;i<desd.rows;i++)
	 {
		 int Row = k+i;
		 for(int j=0;j<desd.cols;j++)
		 {
			 int Col = k+j;

			 int check = 0;
			 for(int m=i,x=0;m<Row&&Row-1<desd.rows;m++,x++)
			 {
				 for(int n=j,y=0;n<Col&&Col-1<desd.cols;n++,y++)
				 {
					 int value = desd.at<uchar>(m,n);

					 if(value!=kernel[x][y])
					 {
						 desd.at<uchar>(i,j)=0;
						 check=1;
						 break;
					 }
				 }
				if(check)
					 break;
			 }

		 }
	 }

	imshow("final",desd);
	waitKey(0);

}

void boundary(){
	srcb = imread("b.tif");
	//desb = srcb.clone();
//	Mat bound = srcb.clone();
	int k;
	cout<<"The value of the mask size:";
	cin>>k;
	imshow("original",srcb);
	waitKey(0);
	int kernel[100][100];
    for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			kernel[i][j]=255;
		}
	}
	int top;
	top=k/2;
	cvtColor(srcb, srcb, CV_BGR2GRAY);
	threshold( srcb, srcb, 128,255,THRESH_BINARY );
	desb=srcb.clone();
	
//	cvtColor(srcb, desb, CV_BGR2GRAY);
//	threshold( desb, desb, 128,255,THRESH_BINARY );
    imshow("binary",desb);
    waitKey(0);
	Mat bound=desb.clone();
	copyMakeBorder(desb,desb,top,top,top,top,BORDER_CONSTANT,0);

	for(int i=0;i<desb.rows;i++)
	 {
		 int Row = k+i;
		 for(int j=0;j<desb.cols;j++)
		 {
			 int Col = k+j;

			 int check = 0;
			 for(int m=i,x=0;m<Row&&Row-1<desd.rows;m++,x++)
			 {
				 for(int n=j,y=0;n<Col&&Col-1<desd.cols;n++,y++)
				 {
					 int value = desb.at<uchar>(m,n);

					 if(value!=kernel[x][y])
					 {
						 desb.at<uchar>(i,j)=0;
						 check=1;
						 break;
					 }
				 }
				if(check)
					 break;
			 }

		 }
	 }

	imshow("erosion",desb);
	waitKey(0);

	for(int i=0;i<bound.rows;i++)
	{
		for(int j=0;j<bound.cols;j++)
		{
				//if(bound.at<uchar>(i,j)==desb.at<uchar>(i,j))
			//{
				bound.at<uchar>(i,j)=srcb.at<uchar>(i,j) - desb.at<uchar>(i,j);
		//	}
			
		}
	}
	
	//bound= srcb-desb;
	imshow("boundary:",bound);
	waitKey(0);

}





int main(){
   cout<<"For Erosion: Enter 1"<<endl<<"For dilation: Enter 2"<<endl<<"For boundary image: Enter 3"<<endl;
   int n;
   cin>>n;
   if(n==1) erosion();
   else if(n==2) dilation();
   else if(n==3) boundary();



}
