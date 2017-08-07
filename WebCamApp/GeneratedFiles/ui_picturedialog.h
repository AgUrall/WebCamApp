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

    void setupUi(QWidget *PictureDialog)
    {
        if (PictureDialog->objectName().isEmpty())
            PictureDialog->setObjectName(QStringLiteral("PictureDialog"));
        PictureDialog->resize(400, 300);
        label = new QLabel(PictureDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 361, 231));
        yesButton = new QPushButton(PictureDialog);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setGeometry(QRect(232, 270, 161, 28));
        noButton = new QPushButton(PictureDialog);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setGeometry(QRect(0, 270, 191, 28));

        retranslateUi(PictureDialog);

        QMetaObject::connectSlotsByName(PictureDialog);
    } // setupUi

    void retranslateUi(QWidget *PictureDialog)
    {
        PictureDialog->setWindowTitle(QApplication::translate("PictureDialog", "PictureDialog", 0));
        label->setText(QApplication::translate("PictureDialog", "TextLabel", 0));
        yesButton->setText(QApplication::translate("PictureDialog", "Yes", 0));
        noButton->setText(QApplication::translate("PictureDialog", "No", 0));
    } // retranslateUi

};

namespace Ui {
    class PictureDialog: public Ui_PictureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREDIALOG_H
