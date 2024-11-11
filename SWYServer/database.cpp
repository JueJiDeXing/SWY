#include "database.h"
#include <QStringBuilder>
#include <QSqlRecord>

Database *Database::instance=nullptr;

Database::Database() {
    qsdb = QSqlDatabase::addDatabase("QODBC");
    qsdb.setHostName("localhost::3306"); // 数据库服务器地址
    qsdb.setUserName("root"); // 用户名
    qsdb.setPassword("Mx18397887506"); // 密码
    qsdb.setDatabaseName("swy"); // 数据库名

    qDebug() << "数据库连接"<<(isConnect()?"成功":"失败");
}
bool Database::isConnect(){
    return qsdb.open();
}
bool  Database::beginTransaction(){
    return qsdb.transaction();
}
Database* Database::getInstance(){
    if(instance==nullptr) instance=new Database();
    return instance;
}
QSqlQuery Database::prepare(QString s){
    QSqlQuery qs(qsdb);
    qs.prepare(s);
    return qs;
}
void Database::bindValue(QSqlQuery &qs,QVector<QString> list,QVector<QVariant> bind ){
    if(list.size()!=bind.size()){
        qDebug()<<"绑定参数数量不正确";
        return;
    }
    for(int i=0;i<list.size();i++){
        qs.bindValue(list[i],bind[i]);
    }
}
bool Database::exec(QSqlQuery &q ){
    if(!q.exec()){
        qDebug() << "sql执行失败:" << q.lastError().text();
        return false;
    }else{
        return true;
    }

}
Database:: ~Database(){
    qsdb.close();
}
Room*Database::queryToRoom(QSqlQuery query){
    Room*room=new Room();
    room->roomId= query.value("id").toString();
    room->password=query.value("password").toString();
    room->hostId = query.value("hostId").toInt();
    room->maxnum = query.value("maxnum").toInt();
    room->state=query.value("state").toString();
    room->turnTo = query.value("turnTo").toInt();
    room->gameOrder = query.value("gameOrder").toInt();
    return room;
}
User* Database::queryToUser(QSqlQuery  query){
    User *user=new User();
    user->id = query.value("id").toInt();
    user->account=query.value("account").toString();
    user->password=query.value("password").toString();
    user->name=query.value("name").toString();
    user->dao = query.value("dao").toInt();
    user->login = query.value("login").toBool();
    user->pixmap.loadFromData(query.value("picture").toByteArray());
    return user;
}
Seat* Database::queryToSeat(QSqlQuery query){
    Seat *seat = new Seat();
    seat->user = queryToUser(query);
    seat->orderNum = query.value("orderNum").toInt();
    seat->state = query.value("state").toString();
    return seat;
}
//数据库交互--------------------------------------------------
User* Database::selectUserById(int id){
    QSqlQuery query = prepare("SELECT * FROM user WHERE id = :id");
    bindValue(query,{":id"}, {id});

    if (exec(query)&&query.next()) {
        return queryToUser(query);
    }
    return nullptr;
}

User* Database::selectUserByAccount(QString account){
    QSqlQuery query = prepare("SELECT * FROM user WHERE account = :account");
    bindValue(query,{":account"}, {account});
    if (exec(query)&&query.next()) {
        return queryToUser(query);
    }
    return nullptr;
}

bool Database::setUserLogin(int id,bool login){
    QSqlQuery query = prepare("Update user SET login = :login WHERE id = :id");
    bindValue(query, {":login", ":id"},   {login, id});
    return exec(query);
}
bool Database::insertUser(User user){
    QSqlQuery query = prepare("INSERT INTO user (name, account, password, dao, picture, login) "
                              "VALUES (:name, :account, :password, :dao, :picture, :login)");
    QVariant picture = Util::pixmapToVariant(user.pixmap);
    bindValue(query, {":name", ":account", ":password", ":dao", ":picture", ":login"},
              {user.name, user.account, user.password, user.dao, picture, user.login});
    return exec(query);
}

bool Database::uploadUserPicture(int id, QPixmap pixmap){
    QSqlQuery query = prepare("UPDATE user SET picture = :picture WHERE id = :id");
    QVariant picture= Util::pixmapToVariant(pixmap);
    bindValue(query, { ":picture", ":id"},  {picture,id});
    return exec(query);
}

Room* Database::queryRoom(QString id){
    QSqlQuery query = prepare("SELECT * FROM room WHERE id = :id");
    bindValue(query, {":id"},  {id});
    if(!exec(query)) return nullptr;
    if(query.next()){
        Room*room = queryToRoom(query);
        room->seatList = querySeat(id);
        return room;
    }
    return nullptr;
}

bool Database::insertRoom(QString id,QString password,int hostId ,int maxnum,QString state,int turnTo,int gameOrder){
    QSqlQuery query = prepare("INSERT INTO room (id, password, hostId, maxnum, state, turnTo, gameOrder) "
                              "VALUES (:id, :password, :hostId, :maxnum, :state, :turnTo, :gameOrder)");
    bindValue(query, {":id", ":password",":hostId",":maxnum", ":state",":turnTo", ":gameOrder"},
              {id, password, hostId, maxnum, state, turnTo, gameOrder });
    return exec(query);
}

bool Database::exitRoom(int userId, QString roomId){
    if(!beginTransaction())return false;
    QSqlQuery query = prepare("DELETE FROM seat WHERE userId = :userId AND roomId = :roomId");
    bindValue(query, {":userId", ":roomId"},  {userId, roomId});
    if(!exec(query))  {
        qsdb.rollback();
        return false;
    }
    query = prepare("SELECT COUNT(*) FROM seat WHERE roomId = :roomId");
    bindValue(query, { ":roomId"},  { roomId});
    if(!exec(query))  {
        qsdb.rollback();
        return false;
    }
    if (!query.next()) {
        qsdb.rollback();
        return false;
    }
    if (query.value(0).toInt() != 0) return qsdb.commit();
    query=prepare("DELETE FROM room WHERE roomId = :roomId");
    bindValue(query, {":roomId"}, {roomId});
    if (!exec(query)) {
        qsdb.rollback();
        return false;
    }
    return qsdb.commit();
}

Room* Database::createRoom(int hostId,int maxnum){
    QString id;
    do{
        id=Util::generateId();
    }while(queryRoom(id)!=nullptr);
    qDebug()<<"准备创建房间"<<id;
    QString password = Util::generatePassword();
    if(!insertRoom(id, password,hostId,maxnum,"准备",-1,0)) {
        qDebug()<<"创建房间"<<id<<"失败";
        return nullptr;
    }
    return queryRoom(id);
}

QVector<Seat> Database::querySeat(QString roomId){
    QVector<Seat> seatList;
    QSqlQuery query = prepare("SELECT user.*, state, orderNum FROM user "
                              "JOIN seat ON user.id = seat.userId WHERE seat.roomId = :roomId");
    bindValue(query,{":roomId"},{roomId});
    if (exec(query)) {
        while (query.next()) {
            Seat* seat = queryToSeat(query);
            seatList.append(*seat);
        }
    }
    return seatList;

}
bool Database::insertSeat(int userId, QString roomId){
    QSqlQuery query = prepare(" INSERT INTO seat (userId, roomId, orderNum) "
                              " SELECT :userId, :roomId, COALESCE(t.mex, 1) "
                              " FROM (SELECT MIN(orderNum + 1) AS mex "
                              " FROM seat t1 "
                              " WHERE t1.roomId = :roomId AND NOT EXISTS (SELECT 1 FROM seat t2 "
                              " WHERE t2.orderNum = t1.orderNum + 1 AND t2.roomId = :roomId )) As t");
    bindValue(query, {":userId",":roomId"}, {userId,roomId});
    return exec(query);
}

bool Database::setRoomState(QString roomId, QString state){
    QSqlQuery query = prepare(" UPDATE room SET state = :state WHERE roomId = :roomId");
    bindValue(query, {":roomId"},  {roomId});
    return exec(query);
}
