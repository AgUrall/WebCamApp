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
	QObject::connect(ui.checkBox,SIGNAL(toggled(bool)), this, SLOT(changeMirrorState()));
	ui.checkBox->setChecked(true);
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

void  WebCamApp::changeMirrorState()
{
	if(ui.checkBox->isChecked())myPlayer->setMirrorMode(true);
	else myPlayer->setMirrorMode(false);
}