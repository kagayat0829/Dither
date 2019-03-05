#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class dither {
public:
	dither();
	~dither();
	void dither_fs(Mat img);
	void dither_jjn(Mat img);
	void dither_stucki(Mat img);
	void dither_burkes(Mat img);
};