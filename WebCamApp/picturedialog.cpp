#include "picturedialog.hpp"

PictureDialog::PictureDialog(QImage  img, QWidget * parent) : QDialog(parent) {
	ui.label->setAlignment(Qt::AlignCenter);
	ui.label->setPixmap(QPixmap::fromImage(img).scaled(ui.label->size(),
	Qt::KeepAspectRatio, Qt::FastTransformation));
	QDialog::setModal(true);
	ui.setupUi(this);
	connect(ui.yesButton, SIGNAL(clicked()), this, SLOT(yesButtonEvent()));
	connect(ui.noButton, SIGNAL(clicked()), this, SLOT(noButtonEvent()));
}

PictureDialog::PictureDialog( QWidget * parent) : QDialog(parent) {

	ui.setupUi(this);
	connect(ui.yesButton, SIGNAL(clicked()), this, SLOT(yesButtonEvent()));
	connect(ui.noButton, SIGNAL(clicked()), this, SLOT(noButtonEvent()));
}


PictureDialog::~PictureDialog() {
	
}
void PictureDialog::setImg(QImage img)
{
	picture = img;
	ui.label->setAlignment(Qt::AlignCenter);
	ui.label->setPixmap(QPixmap::fromImage(img).scaled(ui.label->size(),
		Qt::KeepAspectRatio, Qt::FastTransformation));
}

void PictureDialog::yesButtonEvent()
{
	QString fileName = QFileDialog::getSaveFileName(
		this,
		tr("Save Picture"),
		QDir::currentPath(),
		tr("Picture (*.bmp);;All Files (*)"));
	if (fileName.isEmpty())
		return;
	else {
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly)) {
			QMessageBox::information(this, tr("Unable to open file"),
				file.errorString());
			return;
		}
		if(!picture.isNull()) picture.save(&file, "bmp");
	}
	this->close();

}
void PictureDialog::noButtonEvent()
{
	this->close();
}