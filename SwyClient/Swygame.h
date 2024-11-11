#ifndef SWYGAME_H
#define SWYGAME_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include "User.h"
#include "Room.h"
namespace Ui {
class Widget;
}

class SwyGame : public QObject
{
    Q_OBJECT
public:
    static User* user ;
    static Room* room ;
    static QTcpSocket *tcpClient;
    static SwyGame* instance;
    ~SwyGame();
    static bool swyconnect(QString address, QString port);
    static void send(QJsonObject jsonObj);
    static QJsonObject read();


    static bool autoLogin();
    static void recordAutoLogin(QString account,QString password,bool autoLogin);
    static void onAboutToQuit() ;

    static QJsonObject uploadPicture(int id,QPixmap pixmap);
    static QJsonObject getUserInfo(int id);
    static QJsonObject login(QString account,QString password);
    static QJsonObject userRegister(QString account,QString password,QString name);
    static QJsonObject outLogin(int id);

    static bool flushUserInfo();

    static QJsonObject queryRoomAndFlush(QString roomId);
    static Room* queryRoom(QString roomId);
    static QJsonObject createRoom(int host,int maxnum);
    static QJsonObject enterRoom(int userId,QString roomId,QString password);
    static QJsonObject exitRoom( int userId,QString roomId);

    static QJsonObject startGame(QString roomId);
private:
    SwyGame(QObject*parent=nullptr);
};

#endif // SWYGAME_H
