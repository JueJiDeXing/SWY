/********************************************************************************
** Form generated from reading UI file 'mainwdiget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWDIGET_H
#define UI_MAINWDIGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QAction *toMainWidget;
    QAction *toFriendWidget;
    QAction *toMyInfo;
    QWidget *centralwidget;
    QStackedWidget *stack;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(509, 625);
        toMainWidget = new QAction(MainWidget);
        toMainWidget->setObjectName("toMainWidget");
        toMainWidget->setMenuRole(QAction::MenuRole::NoRole);
        toFriendWidget = new QAction(MainWidget);
        toFriendWidget->setObjectName("toFriendWidget");
        toFriendWidget->setMenuRole(QAction::MenuRole::NoRole);
        toMyInfo = new QAction(MainWidget);
        toMyInfo->setObjectName("toMyInfo");
        toMyInfo->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWidget);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setToolTipDuration(-1);
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        stack = new QStackedWidget(centralwidget);
        stack->setObjectName("stack");
        stack->setGeometry(QRect(0, 0, 511, 591));
        MainWidget->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWidget);
        toolBar->setObjectName("toolBar");
        MainWidget->addToolBar(Qt::ToolBarArea::BottomToolBarArea, toolBar);

        toolBar->addAction(toMainWidget);
        toolBar->addAction(toFriendWidget);
        toolBar->addAction(toMyInfo);

        retranslateUi(MainWidget);

        stack->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QMainWindow *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "\346\234\224\346\234\233\346\234\210 - \344\270\273\351\241\265", nullptr));
        toMainWidget->setText(QCoreApplication::translate("MainWidget", "\344\270\273\351\241\265", nullptr));
        toFriendWidget->setText(QCoreApplication::translate("MainWidget", "\345\245\275\345\217\213", nullptr));
        toMyInfo->setText(QCoreApplication::translate("MainWidget", "\346\210\221\347\232\204", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWidget", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWDIGET_H
