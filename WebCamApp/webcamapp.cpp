#include "webcamapp.h"

void enumerateCams(std::vector<int> &camIndex);
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
	myPlayer->changeCam(currentIndex);
}