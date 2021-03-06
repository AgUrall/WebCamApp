
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
	while (!stop) {
		if (VI.isFrameNew(deviceId)) {
			IplImage * img  = cvCreateImage(cvSize(VI.getWidth(deviceId), VI.getHeight(deviceId)), IPL_DEPTH_8U, 3);
			VI.getPixels(deviceId, (unsigned char *)img->imageData, false, true);
			img = overwork(img);
			emit processedImage(IplImage2QImage(img));
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
		if(camID >= 0 && camID < VI.listDevices(true)) deviceId = camID;
		return false;
	}
	else
	{
		VI.setupDevice(camID, 1280, 960, VI_COMPOSITE);
		VI.setIdealFramerate(camID, 15);
		deviceId = camID;
		return true;
	}

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


void CamPlayer::setMirrorMode(bool mode)
{
	mirrorMode = mode;
}

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
		return QImage();
	}
}

IplImage * CamPlayer::overwork(IplImage * img)
{
	if (mirrorMode) cvFlip(img,img, 1);
	return img;
}
