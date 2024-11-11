#ifndef USER_H
#define USER_H

#include "Util.h"
#include <QJsonObject>
class User
{
public:
    User(){}
    int id=-1;
    QString account="";
    QString password="";
    QString name="";
    int dao=0;
    bool login=false;
    QPixmap pixmap;

    QJsonObject userToJson() {
        QJsonObject jsonObj;
        jsonObj["id"] =  id;
        jsonObj["account"] =  account;
        jsonObj["password"] =  password;
        jsonObj["name"] =  name;
        jsonObj["dao"] = dao;
        jsonObj["login"] =  login;
        jsonObj["picture"] = Util::pixmapToJson(pixmap);
        return jsonObj;
    }


    void toUser(QJsonObject jsonObj) {
        id = jsonObj["id"].toInt();
        account = jsonObj["account"].toString();
        password = jsonObj["password"].toString();
        name = jsonObj["name"].toString();
        dao = int(jsonObj["dao"].toDouble());
        login = jsonObj["login"].toBool();
        pixmap= Util::jsonToPixmap(jsonObj["picture"].toString());
    }
};

#endif // USER_H
