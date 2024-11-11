
#include <QApplication>

#include "Swygame.h"
#include "widgetmanager.h"

#include "login.h"
#include "register.h"
#include "mainwdiget.h"
#include "user_mainwidget.h"
#include "roomwidget.h"
void addWidget(){
    LoginWidget *loginWidget=new LoginWidget();
    RegisterWidget *registerWidget=new RegisterWidget();
    MainWdiget* mainWdiget=new MainWdiget();
    UserMainWidget* usermainwidget=new UserMainWidget();
    RoomWidget *roomwidget=new RoomWidget();

    WidgetManager::addWidget("登录",loginWidget);
    WidgetManager::addWidget("注册",registerWidget);
    WidgetManager::addWidget("游戏主页",mainWdiget);
    WidgetManager::addWidget("用户主页",usermainwidget);
    WidgetManager::addWidget("房间",roomwidget);
}
void begin(){
    int model=2;
    if(model==1){// 正常用户
        if(SwyGame::autoLogin()){
            WidgetManager::show("游戏主页");
        }else{
            WidgetManager::show("登录");
        }
    }else if(model==2){// 多线程, 模拟正常用户
        WidgetManager::show("登录");
    }else if(model==3){// 调试Room模块
        SwyGame::login("齐夏","余念安");
        SwyGame::createRoom(1,5);
        SwyGame::enterRoom(1,SwyGame::room->roomId,SwyGame::room->password);
        WidgetManager::show("房间");
    }
}
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QObject::connect(&a, &QApplication::aboutToQuit, &SwyGame::onAboutToQuit);

    bool isConnected = SwyGame::swyconnect(QString("127.0.0.1"), QString("7777"));
    if(!isConnected) qDebug()<<"未连接上服务器";

    // SwyGame::outLogin(1);
    // SwyGame::outLogin(2);

    addWidget();

    begin();
    return a.exec();
}













