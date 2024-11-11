#ifndef ROOM_H
#define ROOM_H
#include <QString>
#include <QVector>
#include "Seat.h"
#include <QJsonObject>
#include <QJsonArray>
class Room{
public:
    Room(){}
    Room(QString id,QString password,int hostId,int maxnum, QString state){
        this->roomId=id;
        this->password=password;
        this->hostId=hostId;
        this->maxnum=maxnum;
        this->state=state;
    }

    QString roomId;
    QString password;
    int hostId;
    int maxnum;
    QVector<Seat> seatList;
    QString state="准备";
    int turnTo = -1;
    int gameOrder = 0;
    QJsonObject roomToJson() {
        QJsonObject jsonObj;
        jsonObj["roomId"] =  roomId;
        jsonObj["password"] =  password;
        jsonObj["hostId"] =  hostId;
        jsonObj["maxnum"] = maxnum;
        jsonObj["state"] = state;
        jsonObj["turnTo"] = turnTo;
        jsonObj["gameOrder"] = gameOrder;

        QJsonArray jsonArray;
        for (Seat seat : seatList) {
            jsonArray.append(seat.seatToJson());
        }
        jsonObj["seatList"] = jsonArray;
        return jsonObj;
    }


    void toRoom(QJsonObject jsonObj) {
        roomId = jsonObj["roomId"].toString();
        password = jsonObj["password"].toString();
        hostId = jsonObj["hostId"].toInt();
        maxnum = jsonObj["maxnum"].toInt();
        state = jsonObj["state"].toString();
        turnTo=  jsonObj["turnTo"].toInt()   ;
        gameOrder= jsonObj["gameOrder"] .toInt()  ;

        seatList.clear();
        if (jsonObj.contains("seatList") && jsonObj["seatList"].isArray()) {
            QJsonArray jsonArray = jsonObj["seatList"].toArray();
            for (const QJsonValue& value : jsonArray) {
                if (value.isObject()) {
                    QJsonObject seatObj = value.toObject();
                    Seat seat;
                    seat.toSeat(seatObj);
                    seatList.append(seat);
                }
            }
        }
    }
    void print(){
        qDebug() << "房间id:" << roomId;
        qDebug() << "房间密码:" << password;
        qDebug() << "房主:" << hostId;
        qDebug() << "最大人数:" << maxnum;
        qDebug() << "房间状态: "<< state;
        qDebug() << "座位情况:";
        for (const Seat& seat : seatList) {
            qDebug() << "\t用户:" << seat.user->id << ", 座位号:" << seat.orderNum;
        }
    }
    bool isFullSeat(){
        return seatList.size()==maxnum;
    }
    int cntSeatState(QString s){
        int cnt=0;
        for(Seat seat:seatList){
            if(seat.state==s){
                cnt++;
            }
        }
        return cnt;
    }
};

#endif // ROOM_H
