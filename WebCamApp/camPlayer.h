
#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <C:\Users\Михаил\Documents\OpenCV\opencv\build\include\opencv2/core/core.hpp>
#include <C:\Users\Михаил\Documents\OpenCV\opencv\build\include\opencv2/imgproc/imgproc.hpp>
#include <C:\Users\Михаил\Documents\OpenCV\opencv\build\include\opencv2/highgui/highgui.hpp>
#include "libs\videoInput\videoInput.h"

class CamPlayer : public QThread
{
	Q_OBJECT
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	cv::VideoCapture capture;
	videoInput VI;
	QImage img;
	bool mirrorMode = false;
	int deviceId = -1;
signals:
	//Signal to output frame to be displayed
	void processedImage(const QImage &image);
protected:
	void run();
	void msleep(int ms);
public:
	CamPlayer(QObject * parent = 0 );
	~CamPlayer();
	IplImage * overwork(IplImage * img);
	bool changeCam(int camID);
	void startVideo();
	void stopVideo();
	bool isStopped() const;
	void setMirrorMode(bool mode);
};
#endif