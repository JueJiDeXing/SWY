#include "game_mainwdiget.h"
#include "ui_game_mainwdiget.h"
#include "Swygame.h"
#include <QFileDialog>
#include "widgetmanager.h"
#include<QInputDialog>
#include<QFormLayout>
GameMainWdiget::GameMainWdiget( QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::game_mainwdiget)
{
    ui->setupUi(this);
    connect(ui->picture,&QPushButton::clicked,this,&GameMainWdiget::toUserMainWidget);
    connect(ui->createRoom,&QPushButton::clicked,this,&GameMainWdiget::createRoom);
    connect(ui->enterRoom,&QPushButton::clicked,this,&GameMainWdiget::enterRoom);
}
void GameMainWdiget::showEvent(QShowEvent *event) {
    // 调用父类的showEvent方法
    QWidget::showEvent(event);

    // 调用自定义的flush方法
    if(SwyGame::user->login){
        SwyGame::flushUserInfo();
    }
    ui->name->setText(SwyGame::user->name);
    ui->picture->setIcon(*SwyGame::user->pixmap);
    ui->picture->setIconSize(ui->picture->size());
    this->show();
}
void GameMainWdiget::toUserMainWidget(){
    qDebug()<<"打开用户主页";
    if(WidgetManager::show("用户主页")) {
        WidgetManager::hide("游戏主页");
    }
}
void GameMainWdiget::createRoom(){
    bool ok;
    int value = QInputDialog::getInt(nullptr, "输入人数", "2~10人", 2, 2, 10, 1, &ok);

    if (!ok) return;
    if(value<2||value>10){
        QMessageBox::warning(nullptr, "输入错误","只能2~10人");
        return;
    }
    QJsonObject data = SwyGame::createRoom(SwyGame::user->id,value);
    if(data["success"]==false){
        qDebug()<<"创建房间失败";
        return;
    }
    data = SwyGame::enterRoom(SwyGame::user->id, SwyGame::room->roomId, SwyGame::room->password);
    if(data["success"]==false){
        qDebug()<<"进入房间失败";
        return;
    }
    qDebug()<<"进入房间";
    if(WidgetManager::show("房间")) {
        WidgetManager::hide("游戏主页");
    }
}
void GameMainWdiget::enterRoom(){
    // 创建一个对话框
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("朔望月 - 加入房间");

    QLineEdit *roomNumberEdit = new QLineEdit(dialog);
    QLineEdit *passwordEdit = new QLineEdit(dialog);

    QPushButton *okButton = new QPushButton("确定", dialog);
    QPushButton *cancelButton = new QPushButton("取消", dialog);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("房间号:", roomNumberEdit);
    formLayout->addRow("密码:", passwordEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    // 连接信号和槽
    connect(okButton, &QPushButton::clicked, [=]() {
        QString roomId = roomNumberEdit->text();
        QString password = passwordEdit->text();
        QJsonObject data = SwyGame::enterRoom(SwyGame::user->id,roomId,password);
        if(data["success"]==false){
            qDebug()<<"进入房间失败";
            return;
        }
        qDebug()<<"进入房间";
        if(WidgetManager::show("房间")) {
            WidgetManager::hide("游戏主页");
        }
        dialog->accept();
    });

    connect(cancelButton, &QPushButton::clicked, dialog, &QDialog::reject);

     dialog->exec();
}

GameMainWdiget::~GameMainWdiget()
{
    delete ui;
}
