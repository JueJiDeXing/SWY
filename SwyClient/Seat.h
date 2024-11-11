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
    QString clearCard;
    QString hiddenCard;
    QJsonObject seatToJson() {
        QJsonObject jsonObj;
        if(user != nullptr){
            QJsonObject userObj = user->userToJson();
            jsonObj = Util::merage(jsonObj,userObj);
        }
        jsonObj["orderNum"] = orderNum;
        jsonObj["state"] = state;
        jsonObj["clearCard"] = clearCard;
        jsonObj["hiddenCard"] = hiddenCard;

        return jsonObj;
    }

    void toSeat(QJsonObject jsonObj) {
        user = new User();
        user->toUser(jsonObj);
        orderNum = jsonObj["orderNum"].toInt();
        state = jsonObj["state"].toString();
        clearCard = jsonObj["clearCard"].toString();
        hiddenCard = jsonObj["hiddenCard"].toString();
    }
    bool equals(Seat*other){
        return this->user->id==other->user->id&&
               this->orderNum==other->orderNum&&
               this->state==other->state&&
               this->clearCard==other->clearCard&&
               this->hiddenCard==other->hiddenCard;
    }
};

#endif // SEAT_H
