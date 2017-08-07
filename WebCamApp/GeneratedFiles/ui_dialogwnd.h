/********************************************************************************
** Form generated from reading UI file 'dialogwnd.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGWND_H
#define UI_DIALOGWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogWnd
{
public:
    QLabel *picture;
    QPushButton *noButton;
    QPushButton *yesButton;

    void setupUi(QWidget *DialogWnd)
    {
        if (DialogWnd->objectName().isEmpty())
            DialogWnd->setObjectName(QStringLiteral("DialogWnd"));
        DialogWnd->resize(400, 300);
        picture = new QLabel(DialogWnd);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(10, 10, 371, 241));
        noButton = new QPushButton(DialogWnd);
        noButton->setObjectName(QStringLiteral("noButton"));
        noButton->setGeometry(QRect(10, 260, 171, 28));
        yesButton = new QPushButton(DialogWnd);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        yesButton->setGeometry(QRect(220, 260, 171, 31));

        retranslateUi(DialogWnd);

        QMetaObject::connectSlotsByName(DialogWnd);
    } // setupUi

    void retranslateUi(QWidget *DialogWnd)
    {
        DialogWnd->setWindowTitle(QApplication::translate("DialogWnd", "whant to save picture?", 0));
        picture->setText(QApplication::translate("DialogWnd", "TextLabel", 0));
        noButton->setText(QApplication::translate("DialogWnd", "NO", 0));
        yesButton->setText(QApplication::translate("DialogWnd", "Yes", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogWnd: public Ui_DialogWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGWND_H
