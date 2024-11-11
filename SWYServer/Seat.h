#ifndef SEAT_H
#define SEAT_H
#include<QJsonObject>
#include "User.h"
#include "Util.h"
class Seat{
public:
    Seat(){}

    User *user;
    int orderNum;
    QString state="未准备";

    QJsonObject seatToJson() {
        QJsonObject jsonObj;
        if(user != nullptr){
            QJsonObject userObj = user->userToJson();
            jsonObj = Util::merage(jsonObj,userObj);
        }
        jsonObj["orderNum"] = orderNum;
        jsonObj["state"] = state;
        return jsonObj;
    }

    void toSeat(QJsonObject jsonObj) {
        user = new User();
        user->toUser(jsonObj);
        orderNum = jsonObj["orderNum"].toInt();
        state = jsonObj["state"].toString();
    }
};

#endif // SEAT_H
