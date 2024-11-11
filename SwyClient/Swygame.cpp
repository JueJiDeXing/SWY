#include "Swygame.h"
#include <QEventLoop>
#include <QTimer>
#include <QSettings>
#include <QObject>
#include<QJsonObject>
#include<QThread>
#include<QFuture>
#include <QtConcurrent>
User*SwyGame::user=new User() ;
Room*SwyGame:: room=new Room() ;
QTcpSocket*SwyGame:: tcpClient =new QTcpSocket();
SwyGame* SwyGame::instance=new SwyGame();

SwyGame::SwyGame(QObject *parent) : QObject(parent) {

}

SwyGame::~SwyGame(){
}

bool SwyGame::swyconnect(QString address, QString port){
    QEventLoop eventLoop;
    bool isConnected = false;
    QObject::connect(tcpClient, &QTcpSocket::connected,  [&]() {
        isConnected = true;
        eventLoop.quit();
    });

    QObject::connect(tcpClient, &QTcpSocket::errorOccurred,  [&](QAbstractSocket::SocketError socketError) {
        qWarning() << "连接失败:" << socketError;
        eventLoop.quit();
    });

    tcpClient->connectToHost(QHostAddress(address), port.toUInt());

    QTimer timer;
    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        if (!isConnected) {
            tcpClient->abort();
            eventLoop.quit();
        }
    });
    timer.start(5000);
    eventLoop.exec();
    if(isConnected){
        qDebug()<<"连接服务器成功";
    }
    return isConnected;
}

void SwyGame::send(QJsonObject  jsonObj){
    QJsonDocument jsonDoc(jsonObj);
    QByteArray o = jsonDoc.toJson();
    if (tcpClient->state() == QAbstractSocket::ConnectedState) {
        tcpClient->write(o);
        tcpClient->flush();
        qDebug()<<"发送"<<jsonObj;
    } else {
        qDebug() << "客户端:服务器未连接";
    }
}
QJsonObject SwyGame::read() {
    if(tcpClient->waitForReadyRead(30000)){
        QByteArray arr=tcpClient->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(arr);
        QJsonObject o = jsonDoc.object();
        return o;
    }
    qDebug()<<"超时";
    return {};

}

bool SwyGame::autoLogin(){
    qDebug()<<"检查settings自动登录";
    QSettings settings("settings.ini", QSettings::IniFormat);

    bool autoLogin = settings.value("autoLogin").toBool();
    if(!autoLogin) return false;

    QString account = settings.value("account").toString();
    QString password = settings.value("password").toString();
    QJsonObject jsonObject =  login(account,password);
    return jsonObject["success"]==true;

}
void SwyGame::recordAutoLogin(QString account,QString password,bool autoLogin){
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.setValue("account", account);
    settings.setValue("password", password);
    settings.setValue("autoLogin", autoLogin);
}
void SwyGame::onAboutToQuit() {
    outLogin(user->id);
}
//后端交互---------------------------------------------------------------------

QJsonObject SwyGame::getUserInfo(int id){
    qDebug()<<"获取用户信息-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=1;
    jsonObj["fun"]="获取用户信息";
    jsonObj["id"]=id;
    send(jsonObj);
    QJsonObject data = read();
    qDebug()<<"获取用户信息#################";
    return data;
}

QJsonObject SwyGame::login(QString account, QString password){
    qDebug()<<"登录-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=2;
    jsonObj["fun"]="登录";
    jsonObj["account"]=account;
    jsonObj["password"]=password;
    send(jsonObj);

    QJsonObject data  = read();
    if(data["success"]==true){
        qDebug()<<"成功登录";
        user->toUser(data);
    }
    qDebug()<<"登录#################";

    return data;
}


QJsonObject SwyGame:: userRegister(QString account,QString password,QString name){
    qDebug()<<"注册-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=3;
    jsonObj["fun"]="注册";
    jsonObj["account"]=account;
    jsonObj["password"]=password;
    jsonObj["name"]=name;
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        qDebug()<<"成功注册";
        user->toUser(data);
    }
    qDebug()<<"注册#################";
    return data;
}

QJsonObject SwyGame::uploadPicture(int id, QPixmap pixmap){
    qDebug()<<"上传头像-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=4;
    jsonObj["fun"]="上传头像";
    jsonObj["id"]=id;
    jsonObj["pixmap"]= Util::pixmapToJson(pixmap);
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        qDebug()<<"成功上传头像";
        user->pixmap=&pixmap;
    }
    qDebug()<<"上传头像#################";

    return data;
}
QJsonObject SwyGame::outLogin(int id){
    qDebug()<<"登出-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=5;
    jsonObj["fun"]="登出";
    jsonObj["id"]=id;
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        qDebug()<<"成功登出";
        user->login = false;
    }
    qDebug()<<"登出#################";
    return data;
}

QJsonObject SwyGame::queryRoomAndFlush(QString roomId){
    qDebug()<<"查询房间-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=6;
    jsonObj["fun"] = "查询房间";
    jsonObj["roomId"] = roomId;
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        qDebug()<<"queryRoom - 查询房间成功";
        room->toRoom(data);
    }
    qDebug()<<"查询房间#################";
    return data;
}

Room* SwyGame::queryRoom(QString roomId){
    qDebug()<<"查询房间-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"] = 6;
    jsonObj["fun"] = "查询房间";
    jsonObj["roomId"] = roomId;
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        Room*room=new Room();
        room->toRoom(data);
        return room;
    }
    qDebug()<<"查询房间#################";
    return nullptr;
}
QJsonObject SwyGame::createRoom(int hostId,int maxnum){
    qDebug()<<"创建房间-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=7;
    jsonObj["fun"]="创建房间";
    jsonObj["hostId"]=hostId;
    jsonObj["maxnum"]=maxnum;
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        room->toRoom(data);
        qDebug()<<"成功创建房间"<<room->roomId;
    }
    qDebug()<<"创建房间#################";
    return data;
}

QJsonObject SwyGame::enterRoom(int userId,QString roomId,QString password){
    qDebug()<<"进入房间-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=8;
    jsonObj["fun"]="进入房间";
    jsonObj["userId"]=userId;
    jsonObj["roomId"]=roomId;
    jsonObj["password"]=password;
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        room->toRoom(data);
        qDebug()<<"成功进入房间";
        room->print();

    }
    qDebug()<<"进入房间#################";
    return data;
}
QJsonObject SwyGame::exitRoom(int userId,QString roomId){
    qDebug()<<"进入房间-------------------";
    QJsonObject jsonObj;
    jsonObj["rId"]=9;
    jsonObj["fun"]="退出房间";
    jsonObj["userId"]=userId;
    jsonObj["roomId"]=roomId;
    send(jsonObj);
    QJsonObject data  = read();
    if(data["success"]==true){
        qDebug()<<"成功退出房间";
    }
    qDebug()<<"退出房间#################";
    return data;
}
 QJsonObject SwyGame::startGame(QString roomId){
      qDebug()<<"开始游戏-------------------";
      QJsonObject jsonObj;
      jsonObj["rId"]=10;
      jsonObj["fun"]="开始游戏";
      jsonObj["roomId"]=roomId;
      send(jsonObj);
      QJsonObject data = read();
      if(data["success"]==true){
          qDebug()<<"成功开始游戏";
      }
      qDebug()<<"开始游戏#################";
      return data;
}
//用户信息--------------------------------------------------------------------------
bool SwyGame::flushUserInfo(){
    if(user->id<0){
        qDebug()<<"无法刷新";
        return false;
    }
    qDebug()<<"开始刷新";
    QJsonObject data = getUserInfo(user->id);
    if(data["success"]!=true){
        qDebug()<<"刷新失败:"<<data["message"];
        return false;
    }
    user->toUser(data);
    qDebug()<<"刷新成功";
    return true;
}
