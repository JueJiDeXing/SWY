#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QJsonObject>
#include "User.h"
#include "Room.h"
#include "Seat.h"
class Database
{
public:
    static Database* getInstance();
    QSqlDatabase qsdb;
    QSqlQuery prepare(QString s);
    void bindValue(QSqlQuery &qs,QVector<QString> list,QVector<QVariant> bind );
    bool exec(QSqlQuery &q );
    bool isConnect();
    bool beginTransaction();

    User* selectUserById(int id);
    User* selectUserByAccount(QString account);
    bool insertUser(User user);
    bool uploadUserPicture(int id,QPixmap pixmap);
    bool setUserLogin(int id,bool login);

    bool insertRoom(QString roomId,QString password,int host,int maxnum, QString state, int turnTo,int gameOrder);
    bool exitRoom(int userId,QString roomId);
    Room* queryRoom(QString roomId);
    Room* createRoom(int host,int maxnum);

    QVector<Seat> querySeat(QString roomId);
    bool insertSeat(int userId, QString roomId);

    bool setRoomState(QString roomId, QString state);
private:
    Room* queryToRoom(QSqlQuery query);
    User* queryToUser(QSqlQuery query);
    Seat* queryToSeat(QSqlQuery query);
    static Database* instance;
    Database();
    ~Database();
};

#endif // DATABASE_H
