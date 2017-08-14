#include "webcamapp.h"

#include <C:\Users\������\Documents\OpenCV\opencv\build\include\opencv2\videoio\videoio_c.h>
#include <C:\Users\������\Documents\OpenCV\opencv\build\include\opencv2\highgui\highgui.hpp>
#include "libs\videoInput\videoInput.h"

IplImage* image = 0;
int main(int argc, char *argv[])
{
	/*
	videoInput VI;
	
	// ��������� ������ ��������� ��������������, ������������ ����� ���������
	int numDevices = VI.listDevices();
	int device1 = 0; // ������ �������� �������������� �� ������

					 // ������� ������
	VI.setIdealFramerate(device1, 15);

	// ��������� ����������
	VI.setupDevice(device1, 1280, 960, VI_COMPOSITE);

	//VI.showSettingsWindow(device1); // �������� ������ �������� ������

	// ������ �������� ������� �������
	image = cvCreateImage(cvSize(VI.getWidth(device1), VI.getHeight(device1)), IPL_DEPTH_8U, 3);

	cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);

	while (1) {
		if (VI.isFrameNew(device1)) {
			// ������ �������� - ������ ��������������
			// ������ - ��������� �� ����� ��� ���������� ������
			// ������ - ����, ������������ ������ �� ������� B � R -������������
			// �������� - ����, ������������ ������������ �������� ��� ���
			VI.getPixels(device1, (unsigned char *)image->imageData, false, true); // ��������� �������� � BGR

																				   //
																				   // ����� ��� ����� �������� � ���������
																				   // � ������� ������� OpenCV
																				   //

																				   // ���������� ��������
			cvShowImage("capture", image);
		}

		char c = cvWaitKey(33);
		if (c == 27) { // ESC
			break;
		}
	}

	// ����������� �������
	cvReleaseImage(&image);
	cvDestroyWindow("capture");

	// ������������� �����������
	VI.stopDevice(device1);
	*/
	QApplication a(argc, argv);
	WebCamApp w;
	w.show();
	return a.exec();
}
