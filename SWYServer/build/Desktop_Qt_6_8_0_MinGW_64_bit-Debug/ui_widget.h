/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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
    QLineEdit *serverIP;
    QLabel *label_2;
    QLineEdit *serverPort;
    QPushButton *btnBind;
    QPlainTextEdit *recvMsg;
    QLabel *lable_2;
    QLineEdit *clientPort;
    QLabel *label_3;
    QLabel *lable_3;
    QLineEdit *clientIP;
    QPushButton *btnSend;
    QPlainTextEdit *sendMsg;
    QLabel *lable_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(752, 581);
        lable = new QLabel(Widget);
        lable->setObjectName("lable");
        lable->setGeometry(QRect(20, 20, 131, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Aharoni")});
        font.setPointSize(20);
        font.setBold(true);
        lable->setFont(font);
        serverIP = new QLineEdit(Widget);
        serverIP->setObjectName("serverIP");
        serverIP->setGeometry(QRect(150, 20, 131, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 20, 161, 31));
        label_2->setFont(font);
        serverPort = new QLineEdit(Widget);
        serverPort->setObjectName("serverPort");
        serverPort->setGeometry(QRect(480, 20, 131, 31));
        btnBind = new QPushButton(Widget);
        btnBind->setObjectName("btnBind");
        btnBind->setGeometry(QRect(620, 20, 75, 31));
        btnBind->setFont(font);
        recvMsg = new QPlainTextEdit(Widget);
        recvMsg->setObjectName("recvMsg");
        recvMsg->setGeometry(QRect(20, 100, 661, 181));
        lable_2 = new QLabel(Widget);
        lable_2->setObjectName("lable_2");
        lable_2->setGeometry(QRect(20, 60, 181, 31));
        lable_2->setFont(font);
        clientPort = new QLineEdit(Widget);
        clientPort->setObjectName("clientPort");
        clientPort->setGeometry(QRect(480, 300, 131, 31));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 300, 161, 31));
        label_3->setFont(font);
        lable_3 = new QLabel(Widget);
        lable_3->setObjectName("lable_3");
        lable_3->setGeometry(QRect(10, 300, 131, 31));
        lable_3->setFont(font);
        clientIP = new QLineEdit(Widget);
        clientIP->setObjectName("clientIP");
        clientIP->setGeometry(QRect(150, 300, 131, 31));
        btnSend = new QPushButton(Widget);
        btnSend->setObjectName("btnSend");
        btnSend->setGeometry(QRect(610, 300, 75, 31));
        btnSend->setFont(font);
        sendMsg = new QPlainTextEdit(Widget);
        sendMsg->setObjectName("sendMsg");
        sendMsg->setGeometry(QRect(20, 380, 661, 181));
        lable_4 = new QLabel(Widget);
        lable_4->setObjectName("lable_4");
        lable_4->setGeometry(QRect(10, 340, 181, 31));
        lable_4->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\234\224\346\234\233\346\234\210\346\234\215\345\212\241\345\231\250", nullptr));
        lable->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        serverIP->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250PORT:", nullptr));
        serverPort->setText(QCoreApplication::translate("Widget", "7777", nullptr));
        btnBind->setText(QCoreApplication::translate("Widget", "\347\273\221\345\256\232", nullptr));
        lable_2->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\210\260\347\232\204\346\266\210\346\201\257:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257PORT:", nullptr));
        lable_3->setText(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257IP:", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        lable_4->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\347\232\204\346\266\210\346\201\257:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
