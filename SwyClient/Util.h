#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include <QMessageBox>
#include <QBuffer>
#include<QJsonObject>
class Util{
public:
    static QJsonObject merage(QJsonObject q1,QJsonObject q2){
        QJsonObject q3=q1;
        for (auto it = q2.begin(); it != q2.end(); ++it) {
            q3.insert(it.key(), it.value());
        }
        return q3;
    }
    static void alert(QString s){
        QMessageBox::information(nullptr, "", s);
    }
    static QString pixmapToJson(QPixmap pixmap){
        if (pixmap.isNull()) return "";
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        pixmap.save(&buffer, "PNG");
        buffer.close();
        return QString(byteArray.toBase64());
    }
    static QPixmap jsonToPixmap(QString s){
        if(s.isNull())return {};

        QByteArray byteArray = QByteArray::fromBase64(s.toUtf8());
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::ReadOnly);
        QImage image;
        image.load(&buffer, "PNG");
        buffer.close();
        return QPixmap::fromImage(image);
    }

};

#endif // UTIL_H
