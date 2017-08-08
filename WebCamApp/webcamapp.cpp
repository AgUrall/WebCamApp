#include "webcamapp.h"

void enumerateCams(std::vector<int> &camIndex);
//bool EnumerateCameras(std::vector<int> &camIdx);
WebCamApp::WebCamApp(QWidget *parent)
	: QMainWindow(parent)
{
	using namespace cv;

	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(takePictureEvent()));
	myPlayer = new CamPlayer();
	QObject::connect(myPlayer, SIGNAL(processedImage(QImage)), this, SLOT(updatePlayerUI(QImage)));
	enumerateCams(cams);
	for (int i = 0; i < cams.size();i++) {
		std::string str = "camera ";
		str += std::to_string(cams[i]);
		ui.comboBox->addItem(str.c_str(), NULL);
	}
	connect(ui.comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onItemChange()));
	myPlayer->changeCam(0);
	myPlayer->startVideo();

	/*
	int numberOfDevices = 0;
	bool isCams = true;
	/*
	std::vector<int> camsid;
	EnumerateCameras(camsid);
	for (int i = 0; i < camsid.size(); i++) {
		std::string str = "camera ";
		str += std::to_string(camsid[0]);
		ui.comboBox->addItem(str.c_str(), NULL);
	}
	
	int i = 0;

	CvCapture* cap;

	while (cap = cvCaptureFromCAM(i++))
	{
		cams.push_back(cap);
	}
	std::string str = "camera ";
	str += std::to_string(i);
	ui.comboBox->addItem(str.c_str(), NULL);*/
	/*
	videoInput VI;
	int nOfCams = VI.listDevices();
	for (int i = 0; i < nOfCams; i++)
	{
		ui.comboBox->addItem( VI.getDeviceName(i),0);

	}
		*/
		/*
	while (isCams)
	{
		try
		{
			// Check if camera is available.
			//VideoCapture videoCapture(numberOfDevices); // Will crash if not available, hence try/catch.
			
			//getcam
			/CvCapture* capture = cvCreateCameraCapture(numberOfDevices);
			VideoCapture cap(0);
			//cap.
			if (capture == NULL)
			{
				isCams = false;
			}
			else
			{
				std::string str = "camera ";
				str += std::to_string(1 + numberOfDevices);
				ui.comboBox->addItem(str.c_str(), NULL);
			}
			cvReleaseCapture(&capture);
			
		}
		catch (...)
		{
			isCams = false;
		}

		// If above call worked, we have found another camera.
		numberOfDevices++;
	}
	*/
	
}

WebCamApp::~WebCamApp()
{
	delete myPlayer;
	//delete ui;
}

void WebCamApp::takePictureEvent()
{
	wnd = new PictureDialog(this);
	wnd->setImg(screen);
	wnd->setWindowModality(Qt::ApplicationModal);
	myPlayer->stopVideo();
	wnd->exec();
	myPlayer->startVideo();
	//wnd->show();
	//DialogWnd * wnd = new DialogWnd(this);
	//wnd:
	//wnd = &newWnd;
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

void enumerateCams(std::vector<int> &camIndex)
{
	cv::VideoCapture capture;
	int i = 0;
	while (capture.open(i))
	{
		camIndex.push_back(i);
		capture.release();
		i++;
	}
}

void WebCamApp::playPauseEvent()
{
	static int i = 0;
	//QApplication::exit();
	if (myPlayer->isStopped())
	{
		myPlayer->changeCam(i);
		myPlayer->startVideo();
		ui.pushButton->setText(tr("Stop"));
		i = (i + 1) % 3;

	}
	else
	{
		myPlayer->stopVideo();
		ui.pushButton->setText(tr("Play"));
	}
}
void WebCamApp::onItemChange()
{
	int currentIndex = ui.comboBox->currentIndex();
	//ui.comboBox->addItem(std::to_string(currentIndex).c_str(), NULL);
	myPlayer->changeCam(currentIndex);
	//QApplication::exit();
}

/*
void WebCamApp::onDraw(int cameraNumber)
{
	CvCapture* cap = cvCaptureFromCAM(cameraNumber);


}*/
/*
bool EnumerateCameras(std::vector<int> &camIdx)
{
	using namespace cv;
	using namespace std;
	camIdx.clear();
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
	std::cout << "Searching for cameras IDs..." << std::endl << std::endl;
	for (int drv = 0; drv < drivers.size(); drv++)
	{
		driverName = drivers[drv].enumName;
		driverEnum = drivers[drv].enumValue;
		driverComment = drivers[drv].comment;
		std::cout << "Testing driver " << driverName << "...";
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
			VideoCapture cap(driverEnum + idx);  // open the camera
			if (cap.isOpened())                  // check if we succeeded
			{
				found = true;
				camIdx.push_back(driverEnum + idx);  // vector of all available cameras
				cap >> frame;
				if (frame.empty())
					std::cout << endl << driverName << "+" << idx << "\t opens: OK \t grabs: FAIL";
				else
					std::cout << endl << driverName << "+" << idx << "\t opens: OK \t grabs: OK";
				// display the frame
				// imshow(driverName + "+" + to_string(idx), frame); waitKey(1);
			}
			cap.release();
		}
		if (!found) cout << "Nothing !" << endl;
		cout << endl;
	}
	cout << camIdx.size() << " camera IDs has been found ";
	cout << "Press a key..." << endl; cin.get();

	return (camIdx.size() > 0); // returns success
}
*/