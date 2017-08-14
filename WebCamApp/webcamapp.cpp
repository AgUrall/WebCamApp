#include "webcamapp.h"
//bool EnumerateCameras(std::vector<int> &camIdx);
void enumerateCams(std::vector<int> &camIndex, std::vector<QString> &strs);
WebCamApp::WebCamApp(QWidget *parent)
	: QMainWindow(parent)
{
	using namespace cv;

	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(takePictureEvent()));
	myPlayer = new CamPlayer();
	QObject::connect(myPlayer, SIGNAL(processedImage(QImage)), this, SLOT(updatePlayerUI(QImage)));
	//enumerateCams(cams);
	std::vector<QString> strs;
	enumerateCams(cams,strs);
	for (int i = 0; i < cams.size();i++) {
		std::string str = "camera ";
		str += std::to_string(cams[i]);
		ui.comboBox->addItem(strs[i].toStdString().c_str(), NULL);
	}
	connect(ui.comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onItemChange()));
	myPlayer->changeCam(0);
	myPlayer->startVideo();
}

WebCamApp::~WebCamApp()
{
	delete myPlayer;
}

void WebCamApp::takePictureEvent()
{
	wnd = new PictureDialog(this);
	wnd->setImg(screen);
	wnd->setWindowModality(Qt::ApplicationModal);
	myPlayer->stopVideo();
	wnd->exec();
	myPlayer->startVideo();
}

void WebCamApp::updatePlayerUI(QImage img)
{
	if (!img.isNull())
	{
		screen = img;
		ui.label_2->setAlignment(Qt::AlignCenter);
		ui.label_2->setPixmap(QPixmap::fromImage(img).scaled(ui.label_2->size(),
			Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void enumerateCams(std::vector<int> &camIndex, std::vector<QString> &strs )
{
	videoInput VI;
	int numDevices = VI.listDevices(true);
	//VI.getDeviceName();
	cv::VideoCapture capture;
	int i = 0;
	while (i < numDevices)
	{
		camIndex.push_back(i);
		strs.push_back(QString(VI.getDeviceName(i)));
		capture.release();
		i++;
	}
}

void WebCamApp::onItemChange()
{
	int currentIndex = ui.comboBox->currentIndex();
	myPlayer->changeCam(cams[currentIndex]);
}

bool EnumerateCameras(std::vector<int> &camIdx)
{
	using namespace cv;
	using namespace std;
	camIdx.clear();
	VideoCapture cap;
	struct CapDriver {
		int enumValue; string enumName; string comment;
	};
	// list of all CAP drivers (see highgui_c.h)
	std::vector<CapDriver> drivers;
	drivers.push_back({ CV_CAP_MIL, "CV_CAP_MIL", "MIL proprietary drivers" });
	drivers.push_back({ CV_CAP_VFW, "CV_CAP_VFW", "platform native" });
	drivers.push_back({ CV_CAP_FIREWARE, "CV_CAP_FIREWARE", "IEEE 1394 drivers" });
	drivers.push_back({ CV_CAP_STEREO, "CV_CAP_STEREO", "TYZX proprietary drivers" });
	drivers.push_back({ CV_CAP_QT, "CV_CAP_QT", "QuickTime" });
	drivers.push_back({ CV_CAP_UNICAP, "CV_CAP_UNICAP", "Unicap drivers" });
	drivers.push_back({ CV_CAP_DSHOW, "CV_CAP_DSHOW", "DirectShow (via videoInput)" });
	drivers.push_back({ CV_CAP_MSMF, "CV_CAP_MSMF", "Microsoft Media Foundation (via videoInput)" });
	drivers.push_back({ CV_CAP_PVAPI, "CV_CAP_PVAPI", "PvAPI, Prosilica GigE SDK" });
	drivers.push_back({ CV_CAP_OPENNI, "CV_CAP_OPENNI", "OpenNI (for Kinect)" });
	drivers.push_back({ CV_CAP_OPENNI_ASUS, "CV_CAP_OPENNI_ASUS", "OpenNI (for Asus Xtion)" });
	drivers.push_back({ CV_CAP_ANDROID, "CV_CAP_ANDROID", "Android" });
	drivers.push_back({ CV_CAP_ANDROID_BACK, "CV_CAP_ANDROID_BACK", "Android back camera" });
	drivers.push_back({ CV_CAP_ANDROID_FRONT, "CV_CAP_ANDROID_FRONT","Android front camera" });
	drivers.push_back({ CV_CAP_XIAPI, "CV_CAP_XIAPI", "XIMEA Camera API" });
	drivers.push_back({ CV_CAP_AVFOUNDATION, "CV_CAP_AVFOUNDATION", "AVFoundation framework for iOS" });
	drivers.push_back({ CV_CAP_GIGANETIX, "CV_CAP_GIGANETIX", "Smartek Giganetix GigEVisionSDK" });
	drivers.push_back({ CV_CAP_INTELPERC, "CV_CAP_INTELPERC", "Intel Perceptual Computing SDK" });

	std::string winName, driverName, driverComment;
	int driverEnum;
	Mat frame;
	bool found;
	for (int drv = 0; drv < drivers.size(); drv++)
	{
		driverName = drivers[drv].enumName;
		driverEnum = drivers[drv].enumValue;
		driverComment = drivers[drv].comment;
		found = false;

		int maxID = 100; //100 IDs between drivers
		if (driverEnum == CV_CAP_VFW)
			maxID = 10; //VWF opens same camera after 10 ?!?
		else if (driverEnum == CV_CAP_ANDROID)
			maxID = 98; //98 and 99 are front and back cam
		else if ((driverEnum == CV_CAP_ANDROID_FRONT) || (driverEnum == CV_CAP_ANDROID_BACK))
			maxID = 1;

		for (int idx = 0; idx < maxID; idx++)
		{
			cap.open(driverEnum + idx);  // open the camera
			if (cap.isOpened())                  // check if we succeeded
			{
				found = true;
				camIdx.push_back(driverEnum + idx);  // vector of all available cameras
				cap >> frame;
				// display the frame
				// imshow(driverName + "+" + to_string(idx), frame); waitKey(1);
			}
			cap.release();
		}
	}
	return (camIdx.size() > 0); // returns success
}