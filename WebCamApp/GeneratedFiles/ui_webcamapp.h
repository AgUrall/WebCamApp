/********************************************************************************
** Form generated from reading UI file 'webcamapp.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBCAMAPP_H
#define UI_WEBCAMAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebCamAppClass
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label_2;
    QCheckBox *checkBox;
    QFrame *line;

    void setupUi(QMainWindow *WebCamAppClass)
    {
        if (WebCamAppClass->objectName().isEmpty())
            WebCamAppClass->setObjectName(QStringLiteral("WebCamAppClass"));
        WebCamAppClass->resize(634, 427);
        WebCamAppClass->setMinimumSize(QSize(634, 427));
        WebCamAppClass->setMaximumSize(QSize(634, 427));
        centralWidget = new QWidget(WebCamAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 331, 21));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-10, 380, 651, 51));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 250, 190);"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 10, 211, 32));
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(67, 67, 67);\n"
"font: 75 10pt \"Nirmala UI\";\n"
""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 40, 531, 331));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(350, 10, 121, 21));
        QFont font;
        font.setPointSize(10);
        checkBox->setFont(font);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 370, 631, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        WebCamAppClass->setCentralWidget(centralWidget);
        groupBox->raise();
        comboBox->raise();
        label_2->raise();
        checkBox->raise();
        line->raise();

        retranslateUi(WebCamAppClass);

        QMetaObject::connectSlotsByName(WebCamAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *WebCamAppClass)
    {
        WebCamAppClass->setWindowTitle(QApplication::translate("WebCamAppClass", "WebCamApp", 0));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("WebCamAppClass", "Take photo", 0));
        label_2->setText(QApplication::translate("WebCamAppClass", "TextLabel", 0));
        checkBox->setText(QApplication::translate("WebCamAppClass", "Mirror Mode", 0));
    } // retranslateUi

};

namespace Ui {
    class WebCamAppClass: public Ui_WebCamAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBCAMAPP_H
