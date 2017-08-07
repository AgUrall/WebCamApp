#pragma once
#include <qdialog.h>
#include "ui_dialogwnd.h"
#include <webcamapp.h>

class DialogWnd : public QDialog, public Ui::WebCamAppClass {
	Q_OBJECT

public:
	DialogWnd(QWidget * parent = 0);
	~DialogWnd();
private:
	void setPicture(QImage);

};


