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
#include <QtWidgets/QComboBox>
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
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *WebCamAppClass)
    {
        if (WebCamAppClass->objectName().isEmpty())
            WebCamAppClass->setObjectName(QStringLiteral("WebCamAppClass"));
        WebCamAppClass->resize(634, 345);
        WebCamAppClass->setMinimumSize(QSize(634, 345));
        WebCamAppClass->setMaximumSize(QSize(634, 345));
        centralWidget = new QWidget(WebCamAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 331, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 310, 431, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 310, 651, 41));
        groupBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 250, 190);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 40, 511, 261));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 310, 131, 31));
        WebCamAppClass->setCentralWidget(centralWidget);
        groupBox->raise();
        comboBox->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();

        retranslateUi(WebCamAppClass);

        QMetaObject::connectSlotsByName(WebCamAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *WebCamAppClass)
    {
        WebCamAppClass->setWindowTitle(QApplication::translate("WebCamAppClass", "WebCamApp", 0));
        label->setText(QApplication::translate("WebCamAppClass", "\320\227\320\264\320\265\321\201\321\217 \320\274\320\276\320\263\320\273\320\260 \320\261\321\213 \320\261\321\213\321\202\321\214 \320\262\320\260\321\210\320\260 \321\200\320\265\320\272\320\273\320\260\320\274\320\260", 0));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("WebCamAppClass", "TextLabel", 0));
        pushButton->setText(QApplication::translate("WebCamAppClass", "Take photo", 0));
    } // retranslateUi

};

namespace Ui {
    class WebCamAppClass: public Ui_WebCamAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBCAMAPP_H
