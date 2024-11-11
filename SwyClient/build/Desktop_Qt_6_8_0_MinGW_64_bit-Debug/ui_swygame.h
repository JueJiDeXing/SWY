/********************************************************************************
** Form generated from reading UI file 'swygame.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWYGAME_H
#define UI_SWYGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *lable;
    QLabel *lable_4;
    QLineEdit *serverIP;
    QPlainTextEdit *recvMsg;
    QLineEdit *serverPort;
    QPushButton *btnSend;
    QPlainTextEdit *sendMsg;
    QLabel *lable_2;
    QLabel *label_2;
    QPushButton *btnBind;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(704, 555);
        lable = new QLabel(Widget);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(10, 10, 131, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Aharoni")});
        font.setPointSize(20);
        font.setBold(true);
        lable->setFont(font);
        lable_4 = new QLabel(Widget);
        lable_4->setObjectName("lable_4");
        lable_4->setGeometry(QRect(0, 290, 181, 31));
        lable_4->setFont(font);
        serverIP = new QLineEdit(Widget);
        serverIP->setObjectName("serverIP");
        serverIP->setGeometry(QRect(140, 10, 131, 31));
        recvMsg = new QPlainTextEdit(Widget);
        recvMsg->setObjectName("recvMsg");
        recvMsg->setGeometry(QRect(10, 90, 661, 181));
        serverPort = new QLineEdit(Widget);
        serverPort->setObjectName("serverPort");
        serverPort->setGeometry(QRect(470, 10, 131, 31));
        btnSend = new QPushButton(Widget);
        btnSend->setObjectName("btnSend");
        btnSend->setGeometry(QRect(600, 280, 75, 31));
        btnSend->setFont(font);
        sendMsg = new QPlainTextEdit(Widget);
        sendMsg->setObjectName("sendMsg");
        sendMsg->setGeometry(QRect(10, 320, 661, 181));
        lable_2 = new QLabel(Widget);
        lable_2->setObjectName("lable_2");
        lable_2->setGeometry(QRect(10, 50, 181, 31));
        lable_2->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 10, 161, 31));
        label_2->setFont(font);
        btnBind = new QPushButton(Widget);
        btnBind->setObjectName("btnBind");
        btnBind->setGeometry(QRect(610, 10, 75, 31));
        btnBind->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\234\224\346\234\233\346\234\210", nullptr));
        lable->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        lable_4->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\347\232\204\346\266\210\346\201\257:", nullptr));
        serverIP->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        serverPort->setText(QCoreApplication::translate("Widget", "7777", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        lable_2->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\210\260\347\232\204\346\266\210\346\201\257:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250PORT:", nullptr));
        btnBind->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWYGAME_H
