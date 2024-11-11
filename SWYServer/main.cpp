#include <QApplication>
#include "swyserver.h"
#include "database.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwyServer server;
    server.swybind(QString("127.0.0.1"), 7777);
    // qDebug() << Database::getInstance()->containsRoom("1");
    return a.exec();
}
