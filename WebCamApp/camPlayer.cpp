
#include <camPlayer.h>

static QImage IplImage2QImage(const IplImage *iplImage);
CamPlayer::CamPlayer(QObject * parent )
{
	stop = true;
	VI.listDevices();
}
CamPlayer::~CamPlayer()
{
	mutex.lock();
	stop = true;
	capture.release();
	condition.wakeOne();
	mutex.unlock();
	wait();
}
void CamPlayer::run()
{
	/*
	int delay = (1000 / frameRate);
	//IplImage * image = cvCreateImage(cvSize(VI.getSize(deviceId), VI.getHeight(deviceId)), IPL_DEPTH_8U, 3);
	while (!stop) {
		
		if (!capture.read(frame))
		{
			stop = true;
		}
		if (frame.channels() == 3) {

			cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
			img = QImage((const unsigned char*)(RGBframe.data),
				RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		}
		else
		{
			img = QImage((const unsigned char*)(frame.data),
				frame.cols, frame.rows, QImage::Format_Indexed8);
		}
		emit processedImage(img);
		/*
		IplImage * img = cvCreateImage(cvSize(VI.getSize(deviceId), VI.getHeight(deviceId)), IPL_DEPTH_8U, 3);
		VI.getPixels(deviceId, (unsigned char *)img->imageData, false, true);
		
		this->msleep(delay);
	}
	*/
	while (!stop) {
		if (VI.isFrameNew(deviceId)) {
			// первый параметр - индекс видеоустройсва
			// второй - указатель на буфер дл€ сохранени€ данных
			// третий - флаг, определ€ющий мен€ть ли местами B и R -составл€ющий
			// четвЄртый - флаг, определ€ющий поворачивать картинку или нет
			//VI.getPixels(deviceId, (unsigned char *)image->imageData, false, true); // получение пикселей в BGR

																				   //
																				   // здесь уже можно работать с картинкой
																				   // с помощью функций OpenCV
																				   //

																				   // показываем картинку
			IplImage * img  = cvCreateImage(cvSize(VI.getWidth(deviceId), VI.getHeight(deviceId)), IPL_DEPTH_8U, 3);;// cvCreateImage(cvSize(VI.getSize(deviceId), VI.getHeight(deviceId)), IPL_DEPTH_8U, 3);
			VI.getPixels(deviceId, (unsigned char *)img->imageData, false, true);
			emit processedImage(IplImage2QImage(img));
		}

		char c = cvWaitKey(33);
		if (c == 27) { // ESC
			break;
		}
	}
}
void CamPlayer::msleep(int ms)
{
	sleep(ms / 1000);
}
bool CamPlayer::changeCam(int camID)
{
	if (VI.isDeviceSetup(camID))
	{
		return false;
	}
	else
	{
		VI.setupDevice(camID, 1280, 960, VI_COMPOSITE);
		VI.setIdealFramerate(camID, 15);
		deviceId = camID;
		frameRate = 30;//standart fps in videoInput lib
		return true;
	}
	/*
	IplImage * image = cvCreateImage(cvSize(VI.getWidth(camID), VI.getHeight(camID)), IPL_DEPTH_8U, 3);

		if (VI.isFrameNew(camID)) {
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

	if (!capture.open(camID, NULL))
	{
		return false;
	}
	if(capture.isOpened()){
		frameRate = 5;
		return true;
	}
	else return false;

	int delay = (1000 / frameRate);
	IplImage * image = cvCreateImage(cvSize(VI.getSize(deviceId), VI.getHeight(deviceId)), IPL_DEPTH_8U, 3);
	while (!stop) {

	if (!/*VI.getPixels(deviceId, (unsigned char *)image->imageData, false, true))
		{
		stop = true;
		}

	if (frame.channels() == 3) {

		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		img = QImage((uchar*)image->imageData, image->width, image->height, /*(const unsigned char*)(RGBframe.data),
																			RGBframe.cols, RGBframe.rows,*/ /*QImage::Format_RGB888);

	}
	else
	{

		img = QImage((uchar*)image->imageData, image->width, image->height, /*(const unsigned char*)(frame.data),
																			frame.cols, frame.rows,*/ /*QImage::Format_Indexed8);

	}
	//cvtColor(image, image, CV_BGR2RGB);
	//Then you can :

	//QImage qImage((uchar*)image->imageData, image->width, image->height, QImage::Format_RGB32)
	emit processedImage(img);

	this->msleep(delay);
}cvReleaseImage(&image);
	*/
}
void CamPlayer::startVideo()
{
	if (!isRunning()) {
		if (isStopped()) {
			stop = false;
		}
		start(LowPriority);
	}
}
void CamPlayer::stopVideo()
{
	stop = true;
}
bool CamPlayer::isStopped() const
{
	return this->stop;
}

bool CamPlayer::captured(cv::Mat image,int deviceId)
{
	IplImage * img = cvCreateImage(cvSize(VI.getSize(deviceId), VI.getHeight(deviceId)), IPL_DEPTH_8U, 3);
	bool f = VI.getPixels(deviceId, (unsigned char *)img->imageData, false, true);
	image = cv::cvarrToMat(img);
	cvReleaseImage(&img);
	return f;
}

/*
QImage CamPlayer::getImg()
{
	if (!capture.read(frame))
	{
		stop = true;
	}
	if (frame.channels() == 3) {
		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		return QImage((const unsigned char*)(RGBframe.data),
			RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
	}
	else
	{
		return QImage((const unsigned char*)(frame.data),
			frame.cols, frame.rows, QImage::Format_Indexed8);
	}
}*/
/*
QImage CamPlayer::overDraw(QImage & img,int radius)
{
	IplConvKernel* Kern = cvCreateStructuringElementEx(radius * 2 + 1, radius * 2 + 1, radius, radius, CV_SHAPE_ELLIPSE);
	
	// выполн€ем преобразовани€
	cvErode(img., cvCloneImage(img.), Kern, iterations);
	
}*/

static QImage IplImage2QImage(const IplImage *iplImage)
{
	int height = iplImage->height;
	int width = iplImage->width;
	if (iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 3)
	{
		const uchar *qImageBuffer = (const uchar*)iplImage->imageData;
		QImage img(qImageBuffer, width, height, QImage::Format_RGB888);
		return img.rgbSwapped();
	}
	else {
		//qWarning() << "Image cannot be converted.";
		return QImage();
	}
}