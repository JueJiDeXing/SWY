#include "register.h"
#include "ui_register.h"
#include "widgetmanager.h"
RegisterWidget::RegisterWidget( QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/qrc/moon1.png"));
    connect(ui->backButton, &QPushButton::clicked, this,  &RegisterWidget::onBack);
    connect(ui->registerButton,&QPushButton::clicked,this,&RegisterWidget::onRegister);
}
void RegisterWidget:: onRegister(){
    QString account = ui->account->text();
    QString password = ui->password->text();
    QString name =ui->name->text();

    QJsonObject jsonObject =SwyGame::userRegister(account,password,name);
    SwyGame::recordAutoLogin(account, password, ui->autoLoginBox->isChecked());
    if(jsonObject["success"]==true){
        if(WidgetManager::show("游戏主页")){
            this->hide();
        }
    }else{

    }

}
void RegisterWidget::onBack(){
    if(WidgetManager::show("登录")){
        this->hide();
    }else{

    }
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}
