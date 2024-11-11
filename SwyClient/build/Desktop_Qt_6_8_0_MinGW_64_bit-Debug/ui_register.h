/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *account;
    QPushButton *registerButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *password;
    QPushButton *backButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *name;
    QCheckBox *autoLoginBox;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(541, 384);
        horizontalLayoutWidget = new QWidget(Register);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(110, 30, 311, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans")});
        font.setPointSize(16);
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

        registerButton = new QPushButton(Register);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(110, 320, 92, 28));
        registerButton->setAutoRepeatInterval(100);
        horizontalLayoutWidget_2 = new QWidget(Register);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(110, 110, 311, 81));
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

        backButton = new QPushButton(Register);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(300, 320, 92, 28));
        horizontalLayoutWidget_3 = new QWidget(Register);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(110, 190, 311, 81));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        name = new QLineEdit(horizontalLayoutWidget_3);
        name->setObjectName("name");
        name->setFont(font1);

        horizontalLayout_3->addWidget(name);

        autoLoginBox = new QCheckBox(Register);
        autoLoginBox->setObjectName("autoLoginBox");
        autoLoginBox->setGeometry(QRect(110, 280, 151, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HarmonyOS Sans")});
        font2.setPointSize(12);
        autoLoginBox->setFont(font2);
        autoLoginBox->setTabletTracking(false);
        autoLoginBox->setChecked(true);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "\346\234\224\346\234\233\346\234\210 - \346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("Register", "\350\264\246\345\217\267:", nullptr));
        account->setText(QString());
        registerButton->setText(QCoreApplication::translate("Register", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201:", nullptr));
        password->setText(QString());
        backButton->setText(QCoreApplication::translate("Register", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "\346\230\265\347\247\260:", nullptr));
        name->setText(QString());
        autoLoginBox->setText(QCoreApplication::translate("Register", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
