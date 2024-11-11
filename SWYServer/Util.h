#ifndef UTIL_H
#define UTIL_H
#include <QJsonObject>
#include <QBuffer>
#include <QPixmap>
class Util
{
public:
    Util();
    static QJsonObject merage(QJsonObject q1,QJsonObject q2){
        QJsonObject q3=q1;
        for (auto it = q2.begin(); it != q2.end(); ++it) {
            q3.insert(it.key(), it.value());
        }
        return q3;
    }
    static  QString pixmapToJson(QPixmap pixmap){
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
    static QVariant pixmapToVariant(QPixmap pixmap){
        if(pixmap.isNull())return {};

        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        pixmap.save(&buffer, "PNG"); // 使用 PNG 格式保存图像
        return QVariant(byteArray);
    }
   static QString generateId() {
        return QString::number(rand() % 1000000);
    }
   static QString generatePassword() {
       return QString::number(rand() % 100);
   }
};

#endif // UTIL_H
