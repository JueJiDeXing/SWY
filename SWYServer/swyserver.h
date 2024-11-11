#ifndef SWYSERVER_H
#define SWYSERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkInterface>
#include <QList>
#include <QtNetwork/QHostAddress>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include "database.h"
#include "Room.h"
namespace Ui {
class Widget;
}

class SwyServer : public QObject
{
    Q_OBJECT

public:
    explicit SwyServer(QObject *parent = 0);
    ~SwyServer();
    QJsonObject errorReturn( QString message);
    QJsonObject errorReturn(int rId,QString message);
    // void flushRoom(QString id);
    void swybind(QString address,int port);
    void send( QTcpSocket *tcpClient,QJsonObject jsonObj);
    QJsonObject read();
    QJsonObject checkFun(  QJsonObject o);

    QJsonObject doGetUserInfo(QJsonObject o);
    QJsonObject doLogin(QJsonObject  o);
    QJsonObject doOutLogin(QJsonObject o);
    QJsonObject doRegister(QJsonObject  o);
    QJsonObject doUploadUserPicture(QJsonObject  o);

    QJsonObject doCreateRoom(QJsonObject o);
    QJsonObject doEnterRoom(QJsonObject o);
    QJsonObject doQueryRoom(QJsonObject o);
    QJsonObject doExitRoom(QJsonObject o);

    QJsonObject doStartGame(QJsonObject o);
private slots:
    void newConnectionSlot();
    void readClientData();
private:
    Database* db;
    QTcpServer *tcpServer; //服务器类
    QString myAddress; //服务器的ip地址和端口
    int myPort;
    QMap<QString,QTcpSocket*>clientMap;// ip+端口 -> tcp
    QMap<int,QString>userMap;// userId -> ip+端口
};

#endif // SWYSERVER_H
