#ifndef WEBCAMAPP_H
#define WEBCAMAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_webcamapp.h"
#include "picturedialog.hpp"
#include <camPlayer.h>
#include <C:\Users\Михаил\Documents\OpenCV\opencv\build\include\opencv2\videoio\videoio_c.h>
#include <C:\Users\Михаил\Documents\OpenCV\opencv\build\include\opencv2\highgui\highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "libs\videoInput\videoInput.h"


class WebCamApp : public QMainWindow
{
	Q_OBJECT

public:
	WebCamApp(QWidget *parent = 0);
	~WebCamApp();
private:
	std::vector<int> cams;
	Ui::WebCamAppClass ui;
	CamPlayer* myPlayer;
	PictureDialog * wnd;
	QImage screen;

private slots:
	//slot for the save imaje push button
	void takePictureEvent();
	//Display video frame in player UI
	void updatePlayerUI(QImage img);
	//slot for combobox, choose camera for video input
	void onItemChange();
	//slot for change mode of video
	void  changeMirrorState();
};

#endif // WEBCAMAPP_H
