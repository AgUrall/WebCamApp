/********************************************************************************
** Form generated from reading UI file 'picturedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREDIALOG_H
#define UI_PICTUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictureDialog
{
public:
    QLabel *label;
    QPushButton *yesButton;
    QPushButton *noButton;
    QLabel *label_2;

    void setupUi(QWidget *PictureDialog)
    {
        if (PictureDialog->objectName().isEmpty())
            PictureDialog->setObjectName(QStringLiteral("PictureDialog"));
        PictureDialog->resize(403, 315);
        label = new QLabel(PictureDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 361, 231));
        label->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        yesButton = new QPushButton(PictureDialog);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setGeometry(QRect(230, 280, 161, 31));
        yesButton->setMinimumSize(QSize(161, 31));
        yesButton->setMaximumSize(QSize(161, 31));
        noButton = new QPushButton(PictureDialog);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setGeometry(QRect(10, 280, 161, 31));
        noButton->setMinimumSize(QSize(161, 31));
        noButton->setMaximumSize(QSize(161, 31));
        label_2 = new QLabel(PictureDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 10, 361, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        retranslateUi(PictureDialog);

        QMetaObject::connectSlotsByName(PictureDialog);
    } // setupUi

    void retranslateUi(QWidget *PictureDialog)
    {
        PictureDialog->setWindowTitle(QApplication::translate("PictureDialog", "Image saving", 0));
        label->setText(QApplication::translate("PictureDialog", "TextLabel", 0));
        yesButton->setText(QApplication::translate("PictureDialog", "Yes", 0));
        noButton->setText(QApplication::translate("PictureDialog", "No", 0));
        label_2->setText(QApplication::translate("PictureDialog", "Whant to save image?", 0));
    } // retranslateUi

};

namespace Ui {
    class PictureDialog: public Ui_PictureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREDIALOG_H
