#include "webcamapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WebCamApp w;
	w.show();
	return a.exec();
}
