#pragma once
#include <qwidget.h>
#include <qfiledialog.h>
#include <qdialog.h>
#include "ui_picturedialog.h"
#include <QMessageBox>

class PictureDialog : public QDialog {
	Q_OBJECT

public:
	PictureDialog(QImage img, QWidget * parent = 0);
	PictureDialog(QWidget * parent = 0);
	~PictureDialog();
	QImage picture;
	// function for connection image to window
	void setImg(QImage img);
			
private:
	Ui::PictureDialog ui;
private slots:
	//slot for Button "Yes"
	void yesButtonEvent();
	//slot for Button "No"
	void noButtonEvent();
};
