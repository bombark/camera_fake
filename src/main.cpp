#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tiobj.hpp>
#include <unistd.h>
#include <tisys.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;



int main(){
	TiObj params( getenv("params") );
	int freq   = params.atInt("freq",10);

	string url = "const/" + params.atStr("url");
	unsigned sleep_time = 1000000 / freq;
	

	Filesystem fs;
	TiObj file = fs.info(url);
	Mat img;

	cerr << file;

	if ( file.is("Image") ){
		img = imread(url);
		while ( true ){
			imwrite("image.jpg",img);
			usleep(sleep_time);
			printf("#end");
			fflush(stdout);
		}

	} else if ( file.is("Video") ){
		VideoCapture video;
		video.open(url);
		while ( true ){
			video >> img;
			imwrite("image.jpg",img);
			usleep(sleep_time);
			printf("#end");
			fflush(stdout);
		}
		video.release();
		
	} else if ( file.is("Folder") ){
		TiObj list = fs.ls(url);
		list.orderby("name");
		cerr << list;
		
	}


	return 0;
}
