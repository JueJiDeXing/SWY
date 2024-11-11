/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *account;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *password;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QCheckBox *autoLoginBox;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(532, 382);
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans")});
        font.setPointSize(16);
        login->setFont(font);
        horizontalLayoutWidget = new QWidget(login);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(110, 70, 311, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        account = new QLineEdit(horizontalLayoutWidget);
        account->setObjectName("account");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\344\273\277\345\256\213")});
        font1.setPointSize(16);
        account->setFont(font1);

        horizontalLayout->addWidget(account);

        horizontalLayoutWidget_2 = new QWidget(login);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(110, 150, 311, 81));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        password = new QLineEdit(horizontalLayoutWidget_2);
        password->setObjectName("password");
        password->setFont(font1);

        horizontalLayout_2->addWidget(password);

        loginButton = new QPushButton(login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(130, 280, 92, 28));
        loginButton->setAutoRepeatInterval(100);
        registerButton = new QPushButton(login);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(320, 280, 92, 28));
        autoLoginBox = new QCheckBox(login);
        autoLoginBox->setObjectName("autoLoginBox");
        autoLoginBox->setGeometry(QRect(110, 240, 151, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HarmonyOS Sans")});
        font2.setPointSize(12);
        autoLoginBox->setFont(font2);
        autoLoginBox->setTabletTracking(false);
        autoLoginBox->setChecked(true);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "\346\234\224\346\234\233\346\234\210 - \347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("login", "\350\264\246\345\217\267:", nullptr));
        account->setText(QString());
        label_2->setText(QCoreApplication::translate("login", "\345\257\206\347\240\201:", nullptr));
        password->setText(QString());
        loginButton->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        registerButton->setText(QCoreApplication::translate("login", "\345\216\273\346\263\250\345\206\214", nullptr));
        autoLoginBox->setText(QCoreApplication::translate("login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
