#ifndef WEBCAMAPP_H
#define WEBCAMAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_webcamapp.h"
#include "picturedialog.hpp"
#include <videoPlayer.h>
#include <opencv2\videoio\videoio_c.h>
#include <opencv2\highgui\highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <videoInput.h>

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
	//sloat for the save imaje push button
	void takePictureEvent();
	//Display video frame in player UI
	void updatePlayerUI(QImage img);
	//sloat for combobox, choose camera for video input
	void onItemChange();
	//unused now
	void playPauseEvent();

};

#endif // WEBCAMAPP_H
