/********************************************************************************
** Form generated from reading UI file 'user_mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MAINWIDGET_H
#define UI_USER_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_mainwidget
{
public:
    QPushButton *name;
    QPushButton *picture;
    QPushButton *changePicture;
    QPushButton *backButton;

    void setupUi(QWidget *user_mainwidget)
    {
        if (user_mainwidget->objectName().isEmpty())
            user_mainwidget->setObjectName("user_mainwidget");
        user_mainwidget->resize(400, 300);
        name = new QPushButton(user_mainwidget);
        name->setObjectName("name");
        name->setGeometry(QRect(170, 60, 60, 60));
        name->setStyleSheet(QString::fromUtf8("border: none"));
        picture = new QPushButton(user_mainwidget);
        picture->setObjectName("picture");
        picture->setEnabled(true);
        picture->setGeometry(QRect(70, 60, 60, 60));
        picture->setAutoFillBackground(false);
        picture->setStyleSheet(QString::fromUtf8(""));
        changePicture = new QPushButton(user_mainwidget);
        changePicture->setObjectName("changePicture");
        changePicture->setEnabled(true);
        changePicture->setGeometry(QRect(110, 100, 31, 31));
        changePicture->setAutoFillBackground(false);
        changePicture->setStyleSheet(QString::fromUtf8(""));
        backButton = new QPushButton(user_mainwidget);
        backButton->setObjectName("backButton");
        backButton->setEnabled(true);
        backButton->setGeometry(QRect(20, 10, 31, 31));
        backButton->setAutoFillBackground(false);
        backButton->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(user_mainwidget);

        QMetaObject::connectSlotsByName(user_mainwidget);
    } // setupUi

    void retranslateUi(QWidget *user_mainwidget)
    {
        user_mainwidget->setWindowTitle(QCoreApplication::translate("user_mainwidget", "Form", nullptr));
        name->setText(QCoreApplication::translate("user_mainwidget", "\345\220\215\345\255\227", nullptr));
        picture->setText(QString());
        changePicture->setText(QCoreApplication::translate("user_mainwidget", "\344\277\256\346\224\271", nullptr));
        backButton->setText(QCoreApplication::translate("user_mainwidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_mainwidget: public Ui_user_mainwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MAINWIDGET_H
