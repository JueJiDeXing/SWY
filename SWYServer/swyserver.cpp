#include "swyserver.h"
#include "database.h"
#include "Util.h"
SwyServer::SwyServer(QObject *parent) :
    QObject(parent){
    tcpServer=new QTcpServer(this);  //初始化服务器指针
    myPort=7777;
    db=Database::getInstance();
}

SwyServer::~SwyServer(){
}
QJsonObject SwyServer::errorReturn( QString message){
    QJsonObject o;
    o["success"]=false;
    o["message"]=message;
    return o;
}
QJsonObject SwyServer::errorReturn(int rId, QString message){
    QJsonObject o;
    o["rId"]=rId;
    o["success"]=false;
    o["message"]=message;
    return o;
}
// void SwyServer::flushRoom(QString roomId){
//     qDebug()<<"广播刷新";
//     Room*room = db->queryRoom(roomId);
//     QJsonObject o=room->roomToJson();
//     o["rId"]=100;
//     o["fun"]="刷新房间";
//     for(Seat seat:room->seatList){
//         int userId=seat.user->id;
//         QTcpSocket *clientSocket =clientMap[userMap[userId]];
//         send(clientSocket,o);
//     }
// }
void SwyServer::swybind(QString address, int port){
    if(tcpServer->listen(QHostAddress(address),port))  {
        qDebug()<<"端口绑定成功";
    }else{
        qDebug()<<"端口绑定失败";
    }
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(newConnectionSlot()));
}

void SwyServer::newConnectionSlot() {
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    if (clientSocket) {
        QString clientAddress = clientSocket->peerAddress().toString();
        quint16 clientPort = clientSocket->peerPort();
        QString clientKey = clientAddress + ":" + QString::number(clientPort);
        clientMap.insert(clientKey, clientSocket);
        connect(clientSocket, &QTcpSocket::readyRead, this, &SwyServer::readClientData);
        qDebug() << "有一个新的客户端连接" << clientKey;
    } else {
        qWarning() << "客户端连接失败";
    }
}

void SwyServer::send( QTcpSocket *tcpClient, QJsonObject  jsonObj){
    if(jsonObj.empty())return;
    QJsonDocument jsonDoc(jsonObj);
    QByteArray jsonData = jsonDoc.toJson();
    if (tcpClient->state() == QAbstractSocket::ConnectedState) {
        tcpClient->write(jsonData);
        tcpClient->flush();
        qDebug()<<"发送"<<jsonObj;
    } else {
        qDebug() << "服务器:未连接!";
    }
}

void SwyServer::readClientData() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) {
        qWarning() << "获取发送对象失败";
        return;
    }
    QByteArray data = clientSocket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    if ( jsonDoc.isNull())  {
        qDebug() << "JSON数据格式转换失败";
    }
    QJsonObject jsonObj = jsonDoc.object();

    QString clientAddress = clientSocket->peerAddress().toString();
    quint16 clientPort = clientSocket->peerPort();
    QString clientKey = clientAddress + ":" + QString::number(clientPort);
    jsonObj["clientKey"]=clientKey;

    if (db->qsdb.isOpen()) {
        send(clientSocket,checkFun(jsonObj));
    }else{
        qDebug() << "数据库未连接";
        send(clientSocket,errorReturn(jsonObj["rId"].toInt(),"数据库连接失败"));
    }

}
//接口定义-------------------------------------------------------------------------------------
QJsonObject SwyServer::checkFun( QJsonObject o){
    qDebug()<<"checkFun---------------";
    QString fun = o["fun"].toString();
    qDebug() << "收到请求:" <<fun << "来自于"<<o["clientKey"];
    QJsonObject returnData;
    if(fun=="获取用户信息"){
        returnData = doGetUserInfo(o);
    }else if(fun=="登录"){
        returnData =  doLogin(o);
    }else if(fun=="登出"){
        returnData =  doOutLogin(o);
    }else if(fun=="注册"){
        returnData =  doRegister(o );
    }else if(fun=="上传头像"){
        returnData =  doUploadUserPicture(o);
    }else if(fun=="创建房间"){
        returnData =  doCreateRoom(o);
    }else if(fun=="进入房间"){
        returnData =  doEnterRoom(o);
    }else if(fun=="查询房间"){
        returnData =  doQueryRoom(o);
    }else if(fun=="退出房间"){
        returnData =  doExitRoom(o);
    }else if(fun=="开始游戏"){
        returnData =  doStartGame(o);
    }else{
        returnData =  errorReturn("未定义请求");
    }
    returnData["rId"]=o["rId"];
    qDebug()<<"checkFun################";
    return returnData;
}
QJsonObject SwyServer::doGetUserInfo(QJsonObject o){
    QJsonObject returnData;
    int id = o["id"].toInt();
    User* user= db->selectUserById(id);
    if(user==nullptr)return errorReturn("用户不存在");

    returnData["success"] = true;
    return Util::merage(returnData, user->userToJson());

}

QJsonObject SwyServer::doLogin(QJsonObject o ){
    QJsonObject returnData;
    QString account = o["account"].toString();
    QString password = o["password"].toString();

    User* user= db->selectUserByAccount(account);
    if (user==nullptr||user->password!=password) return errorReturn("账号或密码错误");
    if(user->login) return errorReturn("该用户已登录");

    db->setUserLogin(user->id,true);
    qDebug()<< "用户"<<account<<"登录成功";
    userMap[user->id] = o["clientKey"].toString();
    returnData["success"] = true;
    return Util::merage(returnData,user->userToJson());
}
QJsonObject SwyServer::doOutLogin(QJsonObject o ){
    QJsonObject returnData;
    int id = o["id"].toInt();
    db->setUserLogin(id, false);
    qDebug()<< "用户"<<id<<"登出成功";
    // userMap.remove(id);
    returnData["success"] = true;
    return  returnData ;
}

QJsonObject SwyServer::doRegister(QJsonObject  o){
    QJsonObject returnData;
    User user;
    user.account = o["account"].toString();
    user.password = o["password"].toString();
    user.name = o["name"].toString();
    user.login = true;
    if(db->selectUserByAccount(user.account)!=nullptr) return errorReturn( "账号已存在");

    qDebug()<<"准备注册";
    if(!db->insertUser(user))return errorReturn( "注册失败");

    qDebug()<<"用户"<<user.account<<"成功注册";
    returnData["success"] = true;
    return Util::merage(returnData,user.userToJson());
}
QJsonObject SwyServer::doUploadUserPicture(QJsonObject o){
    QJsonObject returnData;
    int id = o["id"].toInt();
    QPixmap pixmap = Util::jsonToPixmap(o["pixmap"].toString());
    if(db->selectUserById(id)==nullptr) return errorReturn( "用户不存在");

    qDebug()<<"准备上传";
    if(!db->uploadUserPicture(id,pixmap))return errorReturn( "上传失败");

    qDebug()<<"用户"<<id<<"成功上传头像";
    returnData["success"] = true;
    return returnData;
}
QJsonObject SwyServer::doCreateRoom(QJsonObject o){
    QJsonObject returnData;
    int hostId = o["hostId"].toInt();
    int maxnum=o["maxnum"].toInt();
    Room*room=db->createRoom(hostId,maxnum);
    if(room==nullptr)return errorReturn( "创建失败");

    returnData = Util::merage(returnData,room->roomToJson());
    returnData["success"] = true;
    return returnData;
}

QJsonObject SwyServer::doEnterRoom(QJsonObject o){
    QJsonObject returnData;
    int userId = o["userId"].toInt();
    QString roomId=o["roomId"].toString();
    QString password=o["password"].toString();

    Room*room = db->queryRoom(roomId);
    if(room==nullptr)return errorReturn( "房间不存在");
    if(room->password!=password)return errorReturn("密码错误");
    if(room->maxnum == room->seatList.size())return errorReturn( "房间已满");

    if(!db->insertSeat(userId, roomId)) return errorReturn( "进入房间失败");
    room = db->queryRoom(roomId);
    qDebug()<<"用户"<<userId<< " 进入房间"<<room->roomId<<", 房间内人数"<<room->seatList.size();
    // flushRoom(roomId); // 有新人进入, 通知其他玩家
    returnData = Util::merage(returnData,room->roomToJson());
    returnData["success"] = true;
    return returnData;
}
QJsonObject SwyServer::doQueryRoom(QJsonObject o){
    QJsonObject returnData;
    QString roomId=o["roomId"].toString();
    Room*room = db->queryRoom(roomId);
    if(room==nullptr) return errorReturn( "房间不存在");
    QJsonObject r = room->roomToJson();
    returnData=Util::merage(returnData,r);
    returnData["success"] = true;
    return returnData;
}
QJsonObject SwyServer::doExitRoom(QJsonObject o){
    QJsonObject returnData;
    int userId = o["userId"].toInt();
    QString roomId=o["roomId"].toString();
    if(db->exitRoom(userId, roomId)) return errorReturn("退出失败");

    // flushRoom(roomId);
    returnData["success"] = true;
    return returnData;
}
QJsonObject SwyServer::doStartGame(QJsonObject o){
    QJsonObject returnData;
    QString roomId=o["roomId"].toString();
    // if(db->setRoom(roomId,"发牌",1)) return errorReturn("开始失败");
    // 准备 -> 开始(发牌,第一局)
    returnData["success"] = true;
    return returnData;
}
