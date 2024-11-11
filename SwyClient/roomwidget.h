#ifndef ROOMWIDGET_H
#define ROOMWIDGET_H

#include <QWidget>
#include "card.h"
#include<QJsonObject>
#include <QTimer>
#include "Room.h"
namespace Ui {
class RoomWidget;
}

class RoomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RoomWidget(QWidget *parent = nullptr);
    void  setRoomMenu(Room*room);
    void setDefaultCard(Room*room);
    void setUserCard(Room*room);
    void  flushUI(Room*room);
    ~RoomWidget();
protected:
    void showEvent(QShowEvent *event) override;
private slots:
    void checkFlush();
    void flush();
    void backToGameMain();
    void settingRoom();
    void startGame();
     void  prepare();
private:
    QTimer flushRoomTimer ;
    Card* create(int order, RoomWidget*rw);
    QVector<Card*>userCards;
    Ui::RoomWidget *ui;
};

#endif // ROOMWIDGET_H
