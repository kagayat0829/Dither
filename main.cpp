#include"dither.h"

int main() {
	//��l���������摜��ݒ肵�Ă�������
	//�덷�g�U�@�ɂ���l�����ꂽ�摜�f�[�^��4�\���E�o�͂����
	Mat src = imread("lena.jpg");	
	if (src.data == NULL) {
		cout << "Read Error" << endl;
	}

	dither fs;
	fs.dither_fs(src);			//Floyd & Steinberg�̕��@
	fs.dither_jjn(src);			//JaJuNi (Jarvis, Judice & Ninke)�̕��@
	fs.dither_stucki(src);		//Stucki�̕��@
	fs.dither_burkes(src);		//Burkes�̕��@
	waitKey(0);
}