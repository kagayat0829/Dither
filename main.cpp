#include"dither.h"

int main() {
	//二値化したい画像を設定してください
	//誤差拡散法により二値化された画像データが4つ表示・出力される
	Mat src = imread("lena.jpg");	
	if (src.data == NULL) {
		cout << "Read Error" << endl;
	}

	dither fs;
	fs.dither_fs(src);			//Floyd & Steinbergの方法
	fs.dither_jjn(src);			//JaJuNi (Jarvis, Judice & Ninke)の方法
	fs.dither_stucki(src);		//Stuckiの方法
	fs.dither_burkes(src);		//Burkesの方法
	waitKey(0);
}