
#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class CamPlayer : public QThread
{
	Q_OBJECT
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	cv::Mat frame;
	int frameRate;
	cv::VideoCapture capture;
	//CvCapture* cap;
	cv::Mat RGBframe;
	QImage img;
signals:
	//Signal to output frame to be displayed
	void processedImage(const QImage &image);
protected:
	void run();
	void msleep(int ms);
public:
	CamPlayer(QObject * parent = 0);
	~CamPlayer();
	bool changeCam(int camID);
	void startVideo();
	void stopVideo();
	bool isStopped() const;
	QImage getImg();
};
#endif