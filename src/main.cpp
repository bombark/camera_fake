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
	string robot_url = getenv("robot_url");
	string url = robot_url + "/" + params.atStr("url");
	unsigned sleep_time = 1000000 / freq;
	

	TiObj file;
	Filesystem fs;
	fs.info(url);
	cerr << "aaa" << fs;
	Mat img;

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

	}


	return 0;
}
