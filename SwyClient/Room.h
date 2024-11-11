#ifndef ROOM_H
#define ROOM_H
#include <QString>
#include <QVector>
#include "Seat.h"
#include <QJsonObject>
#include <QJsonArray>
#include <algorithm>
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
    QString pCard;

    QJsonObject roomToJson() {
        QJsonObject jsonObj;
        jsonObj["roomId"] =  roomId;
        jsonObj["password"] =  password;
        jsonObj["hostId"] =  hostId;
        jsonObj["maxnum"] = maxnum;
        jsonObj["state"] = state;
        jsonObj["turnTo"] = turnTo;
        jsonObj["gameOrder"] = gameOrder;
        jsonObj["pCard"] = pCard;

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
        pCard = jsonObj["pCard"].toString();

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
    bool equals(Room*other){
        if( this->roomId==other->roomId&&
            this-> password==other->password&&
            this-> hostId==other->hostId&&
            this-> maxnum==other->maxnum&&
            this-> state==other->state&&
            this-> turnTo==other->turnTo&&
            this-> gameOrder==other->gameOrder&&
            this-> pCard==other->pCard&&
            this-> seatList.size() != other->seatList.size()){

            std::sort(this->seatList.begin(),this->seatList.end(), [](const Seat &a, const Seat &b) {
                return a.orderNum < b.orderNum;
            });
            std::sort(other->seatList.begin(),other->seatList.end(), [](const Seat &a, const Seat &b) {
                return a.orderNum < b.orderNum;
            });
            for(int i=0;i<this->seatList.size();i++){
                if(!this->seatList[i].equals(&other->seatList[i])){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }

    }
};

#endif // ROOM_H
