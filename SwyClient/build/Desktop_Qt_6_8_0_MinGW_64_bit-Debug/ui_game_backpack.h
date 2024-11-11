/********************************************************************************
** Form generated from reading UI file 'game_backpack.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_BACKPACK_H
#define UI_GAME_BACKPACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_myinfo
{
public:

    void setupUi(QWidget *game_myinfo)
    {
        if (game_myinfo->objectName().isEmpty())
            game_myinfo->setObjectName("game_myinfo");
        game_myinfo->resize(400, 300);

        retranslateUi(game_myinfo);

        QMetaObject::connectSlotsByName(game_myinfo);
    } // setupUi

    void retranslateUi(QWidget *game_myinfo)
    {
        game_myinfo->setWindowTitle(QCoreApplication::translate("game_myinfo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_myinfo: public Ui_game_myinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_BACKPACK_H
