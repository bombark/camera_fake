#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tiobj.hpp>
#include <unistd.h>


using namespace std;
using namespace cv;



int main(){
	TiObj params( getenv("params") );
	int freq = params.atInt("freq");
	unsigned sleep_time = 1000000 / freq;

	Mat img;
	while ( true ){
		img.create(480,640,CV_8UC3);
		img.setTo(0);
		imwrite("image.jpg",img);
		usleep(sleep_time);
	}

	return 0;
}
