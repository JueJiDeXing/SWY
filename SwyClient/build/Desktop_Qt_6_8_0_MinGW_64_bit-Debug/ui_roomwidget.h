/********************************************************************************
** Form generated from reading UI file 'roomwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMWIDGET_H
#define UI_ROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomWidget
{
public:
    QPushButton *backButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *roomId;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *password;
    QPushButton *startGame;
    QPushButton *setting;
    QPushButton *prepare;
    QLabel *moon;
    QLabel *gameOrder;
    QLabel *gameOrder_2;
    QLabel *curNum;

    void setupUi(QWidget *RoomWidget)
    {
        if (RoomWidget->objectName().isEmpty())
            RoomWidget->setObjectName("RoomWidget");
        RoomWidget->resize(700, 800);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RoomWidget->sizePolicy().hasHeightForWidth());
        RoomWidget->setSizePolicy(sizePolicy);
        backButton = new QPushButton(RoomWidget);
        backButton->setObjectName("backButton");
        backButton->setEnabled(true);
        backButton->setGeometry(QRect(20, 20, 51, 51));
        backButton->setAutoFillBackground(false);
        backButton->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(RoomWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(110, 10, 171, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        roomId = new QLabel(verticalLayoutWidget);
        roomId->setObjectName("roomId");

        horizontalLayout->addWidget(roomId);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        password = new QLabel(verticalLayoutWidget);
        password->setObjectName("password");

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);

        startGame = new QPushButton(RoomWidget);
        startGame->setObjectName("startGame");
        startGame->setGeometry(QRect(210, 720, 92, 28));
        setting = new QPushButton(RoomWidget);
        setting->setObjectName("setting");
        setting->setEnabled(true);
        setting->setGeometry(QRect(630, 20, 51, 51));
        setting->setAutoFillBackground(false);
        setting->setStyleSheet(QString::fromUtf8(""));
        prepare = new QPushButton(RoomWidget);
        prepare->setObjectName("prepare");
        prepare->setGeometry(QRect(380, 720, 92, 28));
        moon = new QLabel(RoomWidget);
        moon->setObjectName("moon");
        moon->setGeometry(QRect(550, 20, 51, 51));
        gameOrder = new QLabel(RoomWidget);
        gameOrder->setObjectName("gameOrder");
        gameOrder->setGeometry(QRect(460, 30, 61, 31));
        gameOrder_2 = new QLabel(RoomWidget);
        gameOrder_2->setObjectName("gameOrder_2");
        gameOrder_2->setGeometry(QRect(10, 750, 81, 31));
        curNum = new QLabel(RoomWidget);
        curNum->setObjectName("curNum");
        curNum->setGeometry(QRect(90, 750, 81, 31));

        retranslateUi(RoomWidget);

        QMetaObject::connectSlotsByName(RoomWidget);
    } // setupUi

    void retranslateUi(QWidget *RoomWidget)
    {
        RoomWidget->setWindowTitle(QCoreApplication::translate("RoomWidget", "\346\234\224\346\234\233\346\234\210 - \345\245\263\345\250\262\346\270\270\346\210\217", nullptr));
        backButton->setText(QCoreApplication::translate("RoomWidget", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("RoomWidget", "\346\210\277\351\227\264\345\217\267:", nullptr));
        roomId->setText(QString());
        label_2->setText(QCoreApplication::translate("RoomWidget", "\345\257\206\347\240\201:", nullptr));
        password->setText(QString());
        startGame->setText(QCoreApplication::translate("RoomWidget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        setting->setText(QCoreApplication::translate("RoomWidget", "\350\256\276\347\275\256", nullptr));
        prepare->setText(QCoreApplication::translate("RoomWidget", "\345\207\206\345\244\207", nullptr));
        moon->setText(QString());
        gameOrder->setText(QCoreApplication::translate("RoomWidget", "\346\234\252\345\274\200\345\247\213", nullptr));
        gameOrder_2->setText(QCoreApplication::translate("RoomWidget", "\345\275\223\345\211\215\344\272\272\346\225\260:", nullptr));
        curNum->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RoomWidget: public Ui_RoomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWIDGET_H
