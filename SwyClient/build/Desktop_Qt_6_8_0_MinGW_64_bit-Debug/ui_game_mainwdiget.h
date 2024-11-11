/********************************************************************************
** Form generated from reading UI file 'game_mainwdiget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_MAINWDIGET_H
#define UI_GAME_MAINWDIGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_mainwdiget
{
public:
    QPushButton *name;
    QPushButton *createRoom;
    QPushButton *picture;
    QPushButton *enterRoom;

    void setupUi(QWidget *game_mainwdiget)
    {
        if (game_mainwdiget->objectName().isEmpty())
            game_mainwdiget->setObjectName("game_mainwdiget");
        game_mainwdiget->resize(510, 620);
        game_mainwdiget->setAutoFillBackground(false);
        name = new QPushButton(game_mainwdiget);
        name->setObjectName("name");
        name->setGeometry(QRect(150, 80, 60, 60));
        name->setStyleSheet(QString::fromUtf8("border: none"));
        createRoom = new QPushButton(game_mainwdiget);
        createRoom->setObjectName("createRoom");
        createRoom->setGeometry(QRect(300, 500, 71, 51));
        picture = new QPushButton(game_mainwdiget);
        picture->setObjectName("picture");
        picture->setEnabled(true);
        picture->setGeometry(QRect(50, 80, 60, 60));
        picture->setAutoFillBackground(false);
        picture->setStyleSheet(QString::fromUtf8(""));
        enterRoom = new QPushButton(game_mainwdiget);
        enterRoom->setObjectName("enterRoom");
        enterRoom->setGeometry(QRect(380, 500, 71, 51));

        retranslateUi(game_mainwdiget);

        QMetaObject::connectSlotsByName(game_mainwdiget);
    } // setupUi

    void retranslateUi(QWidget *game_mainwdiget)
    {
        game_mainwdiget->setWindowTitle(QCoreApplication::translate("game_mainwdiget", "Form", nullptr));
        name->setText(QCoreApplication::translate("game_mainwdiget", "\345\220\215\345\255\227", nullptr));
        createRoom->setText(QCoreApplication::translate("game_mainwdiget", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
        picture->setText(QString());
        enterRoom->setText(QCoreApplication::translate("game_mainwdiget", "\345\212\240\345\205\245\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_mainwdiget: public Ui_game_mainwdiget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_MAINWDIGET_H
