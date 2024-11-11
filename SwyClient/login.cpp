#include "login.h"
#include "ui_login.h"
#include <QSettings>
#include "widgetmanager.h"
LoginWidget::LoginWidget(QWidget*parent) : QWidget(parent) , ui(new Ui::login){
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/qrc/moon1.png"));
    connect(ui->loginButton, &QPushButton::clicked, this,  &LoginWidget:: onLogin);
    connect(ui->registerButton,&QPushButton::clicked,this,&LoginWidget::onRegister);
}

void LoginWidget:: onLogin(){
    QString account = ui->account->text();
    QString password = ui->password->text();
    bool autoLogin = ui->autoLoginBox->isChecked();
    QJsonObject jsonObject = SwyGame::login(account,password);

    if(jsonObject["success"]==true){
        if(WidgetManager::show("游戏主页")){
            this->hide();
            SwyGame::recordAutoLogin(account,password,autoLogin);
        }else{

        }
    }else{

    }

}
void LoginWidget::onRegister(){
    if(WidgetManager::show("注册")){
        this->hide();
    }else{
        // Util::alert("注册页面打开失败");
    }
}
LoginWidget::~LoginWidget()
{
    delete ui;
}




