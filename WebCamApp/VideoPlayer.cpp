
#include <videoPlayer.h>

CamPlayer::CamPlayer(QObject * parent )
{
	stop = true;
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
	int delay = (1000 / frameRate);
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
		this->msleep(delay);
	}
}
void CamPlayer::msleep(int ms)
{
	sleep(ms / 1000);
}
bool CamPlayer::changeCam(int camID)
{
	if (!capture.open(camID, NULL))
	{
		return false;
	}
	if(capture.isOpened()){
		frameRate = 5;
		return true;
	}
	else return false;
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
}