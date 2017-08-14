#include "webcamapp.h"

#include <C:\Users\ћихаил\Documents\OpenCV\opencv\build\include\opencv2\videoio\videoio_c.h>
#include <C:\Users\ћихаил\Documents\OpenCV\opencv\build\include\opencv2\highgui\highgui.hpp>
#include "libs\videoInput\videoInput.h"

IplImage* image = 0;
int main(int argc, char *argv[])
{
	/*
	videoInput VI;
	
	// получение списка доступных видеоустройств, возвращаетс€ число устройств
	int numDevices = VI.listDevices();
	int device1 = 0; // первое найденое видеоустройсво из списка

					 // частота кадров
	VI.setIdealFramerate(device1, 15);

	// указываем разрешение
	VI.setupDevice(device1, 1280, 960, VI_COMPOSITE);

	//VI.showSettingsWindow(device1); // показать окошко настроек камеры

	// создаЄм картинку нужного размера
	image = cvCreateImage(cvSize(VI.getWidth(device1), VI.getHeight(device1)), IPL_DEPTH_8U, 3);

	cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);

	while (1) {
		if (VI.isFrameNew(device1)) {
			// первый параметр - индекс видеоустройсва
			// второй - указатель на буфер дл€ сохранени€ данных
			// третий - флаг, определ€ющий мен€ть ли местами B и R -составл€ющий
			// четвЄртый - флаг, определ€ющий поворачивать картинку или нет
			VI.getPixels(device1, (unsigned char *)image->imageData, false, true); // получение пикселей в BGR

																				   //
																				   // здесь уже можно работать с картинкой
																				   // с помощью функций OpenCV
																				   //

																				   // показываем картинку
			cvShowImage("capture", image);
		}

		char c = cvWaitKey(33);
		if (c == 27) { // ESC
			break;
		}
	}

	// освобождаем ресурсы
	cvReleaseImage(&image);
	cvDestroyWindow("capture");

	// останавливаем видеозахват
	VI.stopDevice(device1);
	*/
	QApplication a(argc, argv);
	WebCamApp w;
	w.show();
	return a.exec();
}
