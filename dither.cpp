#include"dither.h"

dither::dither() {

}


dither::~dither() {

}

//Floyd & SteinbergÇÃï˚ñ@
void dither::dither_fs(Mat img) {
	if (img.data == NULL) {
		cout << "Read Error" << endl;
	}

	int ir, ic;			//Image Size
	ir = img.rows;
	ic = img.cols;

	const int irc = ir*ic;
	double *tmp;

	Mat gray_img;
	cvtColor(img, gray_img, CV_BGR2GRAY);

	double d, t;
	tmp = new double[irc];

	for (int i = 0; i < ir; i++) {
		for (int j = 0; j < ic; j++)
		{
			tmp[i*ic + j] = (double)gray_img.at<uchar>(i, j);
		}
	}

	for (int i = 0; i < ir; i++)
	{
		for (int j = 0; j < ic; j++)
		{
			t = tmp[i*ic + j];

			if (t > 127) {
				d = t - 255;
				if (j + 1 < ic) { tmp[i*ic + (j + 1)] += d * 7.0 / 16.0; }
				if (i + 1 < ir) {
					if (j - 1 >= 0) { tmp[(i + 1)*ic + (j - 1)] += d * 3.0 / 16.0; }
					tmp[(i + 1)*ic + j] += d * 5.0 / 16.0;
					if (j + 1 < ic) { tmp[(i + 1)*ic + (j + 1)] += d * 1.0 / 16.0; }
				}
				gray_img.at<uchar>(i, j) = 255.0;
			}
			else {
				d = t;
				if (j + 1 < ic) { tmp[i*ic + (j + 1)] += d * 7.0 / 16.0; }
				if (i + 1 < ir) {
					if (j - 1 >= 0) { tmp[(i + 1)*ic + (j - 1)] += d * 3.0 / 16.0; }
					tmp[(i + 1)*ic + j] += d * 5.0 / 16.0;
					if (j + 1 < ic) { tmp[(i + 1)*ic + (j + 1)] += d* 1.0 / 16.0; }
				}
				gray_img.at<uchar>(i, j) = 0.0;
			}
			if (d == 0) continue;          // åÎç∑Ç»Çµ
		}
	}
	delete[] tmp;
	imshow("åÎç∑ägéUñ@(Floyd & Steinberg)", gray_img);
	imwrite("dither_fs.jpg", gray_img);
}

//JaJuNi (Jarvis, Judice & Ninke)ÇÃï˚ñ@
void dither::dither_jjn(Mat img) {
	if (img.data == NULL) {
		cout << "Read Error" << endl;
	}

	int ir, ic;			//Image Size
	ir = img.rows;
	ic = img.cols;

	const int irc = ir*ic;
	double *tmp;

	Mat gray_img;
	cvtColor(img, gray_img, CV_BGR2GRAY);

	double d, t;
	tmp = new double[irc];

	for (int i = 0; i < ir; i++) {
		for (int j = 0; j < ic; j++)
		{
			tmp[i*ic + j] = (double)gray_img.at<uchar>(i, j);
		}
	}

	for (int i = 0; i < ir; i++)
	{
		for (int j = 0; j < ic; j++)
		{
			t = tmp[i*ic + j];

			if (t > 127) {
				d = t - 255;
				if (j + 1 < ic) {
					tmp[i*ic + (j + 1)] += d * 7.0 / 48.0;
					if (j + 2 < ic) {
						tmp[i*ic + (j + 2)] += d * 5.0 / 48.0;;
					}
				}
				if (i + 1 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 1)*ic + (j - 1)] += d * 5.0 / 48.0;
						if (j - 2 > -2) { tmp[(i + 1)*ic + (j - 2)] += d * 3.0 / 48.0; }
					}
					tmp[(i + 1)*ic + j] += d * 7.0 / 48.0;
					if (j + 1 < ic) {
						tmp[(i + 1)*ic + (j + 1)] += d * 5.0 / 48.0;
						if (j + 2 < ic) {
							tmp[(i + 1)*ic + (j + 2)] += d * 3.0 / 48.0;
						}
					}
				}
				if (i + 2 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 2)*ic + (j - 1)] += d * 3.0 / 48.0;
						if (j - 2 > -2) { tmp[(i + 2)*ic + (j - 2)] += d * 1.0 / 48.0; }
					}
					tmp[(i + 2)*ic + j] += d * 5.0 / 48.0;
					if (j + 1 < ic) {
						tmp[(i + 2)*ic + (j + 1)] += d * 3.0 / 48.0;
						if (j + 2 < ic) {
							tmp[(i + 2)*ic + (j + 2)] += d * 1.0 / 48.0;
						}
					}
				}
				gray_img.at<uchar>(i, j) = 255.0;
			}
			else {
				d = t;
				if (j + 1 < ic) {
					tmp[i*ic + (j + 1)] += d * 7.0 / 48.0;
					if (j + 2 < ic) {
						tmp[i*ic + (j + 2)] += d * 5.0 / 48.0;;
					}
				}
				if (i + 1 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 1)*ic + (j - 1)] += d * 5.0 / 48.0;
						if (j - 2 > -2) { tmp[(i + 1)*ic + (j - 2)] += d * 3.0 / 48.0; }
					}
					tmp[(i + 1)*ic + j] += d * 7.0 / 48.0;
					if (j + 1 < ic) {
						tmp[(i + 1)*ic + (j + 1)] += d * 5.0 / 48.0;
						if (j + 2 < ic) {
							tmp[(i + 1)*ic + (j + 2)] += d * 3.0 / 48.0;
						}
					}
				}if (i + 2 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 2)*ic + (j - 1)] += d * 3.0 / 48.0;
						if (j - 2 > -2) { tmp[(i + 2)*ic + (j - 2)] += d * 1.0 / 48.0; }
					}
					tmp[(i + 2)*ic + j] += d * 5.0 / 48.0;
					if (j + 1 < ic) {
						tmp[(i + 2)*ic + (j + 1)] += d * 3.0 / 48.0;
						if (j + 2 < ic) {
							tmp[(i + 2)*ic + (j + 2)] += d * 1.0 / 48.0;
						}
					}
				}
				gray_img.at<uchar>(i, j) = 0.0;
			}
			if (d == 0) continue;          // åÎç∑Ç»Çµ
		}
	}
	delete[] tmp;
	imshow("åÎç∑ägéUñ@(JaJuNi (Jarvis, Judice & Ninke))", gray_img);
	imwrite("dither_jjn.jpg", gray_img);
}

//StuckiÇÃï˚ñ@
void dither::dither_stucki(Mat img) {
	if (img.data == NULL) {
		cout << "Read Error" << endl;
	}

	int ir, ic;		//Image Size
	ir = img.rows;
	ic = img.cols;

	const int irc = ir*ic;
	double *tmp;

	Mat gray_img;
	cvtColor(img, gray_img, CV_BGR2GRAY);

	double d, t;
	tmp = new double[irc];

	for (int i = 0; i < ir; i++) {
		for (int j = 0; j < ic; j++)
		{
			tmp[i*ic + j] = (double)gray_img.at<uchar>(i, j);
		}
	}

	for (int i = 0; i < ir; i++)
	{
		for (int j = 0; j < ic; j++)
		{
			t = tmp[i*ic + j];

			if (t > 127) {
				d = t - 255;
				if (j + 1 < ic) {
					tmp[i*ic + (j + 1)] += d * 8.0 / 42.0;
					if (j + 2 < ic) {
						tmp[i*ic + (j + 2)] += d * 4.0 / 42.0;;
					}
				}
				if (i + 1 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 1)*ic + (j - 1)] += d * 4.0 / 42.0;
						if (j - 2 > -2) { tmp[(i + 1)*ic + (j - 2)] += d * 2.0 / 42.0; }
					}
					tmp[(i + 1)*ic + j] += d * 8.0 / 42.0;
					if (j + 1 < ic) {
						tmp[(i + 1)*ic + (j + 1)] += d * 4.0 / 42.0;
						if (j + 2 < ic) {
							tmp[(i + 1)*ic + (j + 2)] += d * 2.0 / 42.0;
						}
					}
				}
				if (i + 2 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 2)*ic + (j - 1)] += d * 2.0 / 42.0;
						if (j - 2 > -2) { tmp[(i + 2)*ic + (j - 2)] += d * 1.0 / 42.0; }
					}
					tmp[(i + 2)*ic + j] += d * 4.0 / 42.0;
					if (j + 1 < ic) {
						tmp[(i + 2)*ic + (j + 1)] += d * 2.0 / 42.0;
						if (j + 2 < ic) {
							tmp[(i + 2)*ic + (j + 2)] += d * 1.0 / 42.0;
						}
					}
				}
				gray_img.at<uchar>(i, j) = 255.0;
			}
			else {
				d = t;
				if (j + 1 < ic) {
					tmp[i*ic + (j + 1)] += d * 8.0 / 42.0;
					if (j + 2 < ic) {
						tmp[i*ic + (j + 2)] += d * 4.0 / 42.0;;
					}
				}
				if (i + 1 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 1)*ic + (j - 1)] += d * 4.0 / 42.0;
						if (j - 2 > -2) { tmp[(i + 1)*ic + (j - 2)] += d * 2.0 / 42.0; }
					}
					tmp[(i + 1)*ic + j] += d * 8.0 / 42.0;
					if (j + 1 < ic) {
						tmp[(i + 1)*ic + (j + 1)] += d * 4.0 / 42.0;
						if (j + 2 < ic) {
							tmp[(i + 1)*ic + (j + 2)] += d * 2.0 / 42.0;
						}
					}
				}
				if (i + 2 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 2)*ic + (j - 1)] += d * 2.0 / 42.0;
						if (j - 2 > -2) { tmp[(i + 2)*ic + (j - 2)] += d * 1.0 / 42.0; }
					}
					tmp[(i + 2)*ic + j] += d * 4.0 / 42.0;
					if (j + 1 < ic) {
						tmp[(i + 2)*ic + (j + 1)] += d * 2.0 / 42.0;
						if (j + 2 < ic) {
							tmp[(i + 2)*ic + (j + 2)] += d * 1.0 / 42.0;
						}
					}
				}
				gray_img.at<uchar>(i, j) = 0.0;
			}
			if (d == 0) continue;          // åÎç∑Ç»Çµ
		}
	}
	delete[] tmp;
	imshow("åÎç∑ägéUñ@(Stucki)", gray_img);
	imwrite("dither_stucki.jpg", gray_img);
}

//BurkesÇÃï˚ñ@
void dither::dither_burkes(Mat img) {
	if (img.data == NULL) {
		cout << "Read Error" << endl;
	}

	int ir, ic;			//Image Size
	ir = img.rows;
	ic = img.cols;

	const int irc = ir*ic;
	double *tmp;

	Mat gray_img;
	cvtColor(img, gray_img, CV_BGR2GRAY);

	double d, t;
	tmp = new double[irc];

	for (int i = 0; i < ir; i++) {
		for (int j = 0; j < ic; j++)
		{
			tmp[i*ic + j] = (double)gray_img.at<uchar>(i, j);
		}
	}

	for (int i = 0; i < ir; i++)
	{
		for (int j = 0; j < ic; j++)
		{
			t = tmp[i*ic + j];

			if (t > 127) {
				d = t - 255;
				if (j + 1 < ic) {
					tmp[i*ic + (j + 1)] += d * 4.0 / 16.0;
					if (j + 2 < ic) {
						tmp[i*ic + (j + 2)] += d * 2.0 / 16.0;;
					}
				}
				if (i + 1 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 1)*ic + (j - 1)] += d * 2.0 / 16.0;
						if (j - 2 > -2) { tmp[(i + 1)*ic + (j - 2)] += d * 1.0 / 16.0; }
					}
					tmp[(i + 1)*ic + j] += d * 4.0 / 16.0;
					if (j + 1 < ic) {
						tmp[(i + 1)*ic + (j + 1)] += d * 2.0 / 16.0;
						if (j + 2 < ic) {
							tmp[(i + 1)*ic + (j + 2)] += d * 1.0 / 16.0;
						}
					}
				}
				gray_img.at<uchar>(i, j) = 255.0;
			}
			else {
				d = t;
				if (j + 1 < ic) {
					tmp[i*ic + (j + 1)] += d * 4.0 / 16.0;
					if (j + 2 < ic) {
						tmp[i*ic + (j + 2)] += d * 2.0 / 16.0;;
					}
				}
				if (i + 1 < ir) {
					if (j - 1 > -1) {
						tmp[(i + 1)*ic + (j - 1)] += d * 2.0 / 16.0;
						if (j - 2 > -2) { tmp[(i + 1)*ic + (j - 2)] += d * 1.0 / 16.0; }
					}
					tmp[(i + 1)*ic + j] += d * 4.0 / 16.0;
					if (j + 1 < ic) {
						tmp[(i + 1)*ic + (j + 1)] += d * 2.0 / 16.0;
						if (j + 2 < ic) {
							tmp[(i + 1)*ic + (j + 2)] += d * 1.0 / 16.0;
						}
					}
				}
				gray_img.at<uchar>(i, j) = 0.0;
			}
			if (d == 0) continue;          // åÎç∑Ç»Çµ
		}
	}
	delete[] tmp;
	imshow("åÎç∑ägéUñ@(Burkes)", gray_img);
	imwrite("dither_burkes.jpg", gray_img);
}