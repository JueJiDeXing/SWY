#include "roomwidget.h"
#include "ui_roomwidget.h"
#include "widgetmanager.h"
#include "Swygame.h"
#include <QPushButton>
#include <QObject>

Card* RoomWidget::create(int order, RoomWidget*rw){
    Card*card=new Card(order);
    card->order=order;
    card->picture=new QPushButton(rw);
    card->host=new QLabel("房主",rw);
    card->self=new QLabel("你",rw);
    card->num=new QLabel(QString::number(card->order),rw);
    card->status=new QLabel("",rw);
    card->name=new QLabel("",rw);
    card->setPos();
    card->setStyle();
    return card;
}

RoomWidget::RoomWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RoomWidget){
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/qrc/moon4.png"));
    connect(ui->backButton,&QPushButton::clicked,this,&RoomWidget::backToGameMain);
    connect(ui->startGame,&QPushButton::clicked,this,&RoomWidget::startGame);
    connect(ui->prepare,&QPushButton::clicked,this,&RoomWidget::prepare);
    connect(ui->setting,&QPushButton::clicked,this,&RoomWidget::settingRoom);
    for(int i=1;i<=10;i++){
        Card*card=create(i,this);
        userCards.push_back(card);
    }
}

void RoomWidget::checkFlush(){
    connect(&flushRoomTimer, &QTimer::timeout, this, &RoomWidget::flush);
    flushRoomTimer.start(5000);
}

void RoomWidget::flush(){
    Room*room =  SwyGame::queryRoom(SwyGame::room->roomId);

    // if(!SwyGame::room->equals(room)){
        SwyGame::room = room;
        flushUI(room);
    // }
}
void RoomWidget::setRoomMenu(Room*room){
    ui->roomId->setText(room->roomId);
    ui->password->setText(room->password);

    ui->startGame->setEnabled(room->hostId==SwyGame::user->id);
    ui->prepare->setEnabled(room->hostId!=SwyGame::user->id);
    ui->setting->setEnabled(room->hostId==SwyGame::user->id);

    if(room->state=="准备") {
        ui->gameOrder->setText("未开始");
        ui->moon->hide();
    }else{
        QString gameOrder=QString::number(room->gameOrder);
        ui->gameOrder->setText("第"+gameOrder+"局");
        QString path=":/qrc/fullmoon.png";
        if(room->gameOrder<=4) path=":/qrc/moon"+gameOrder+".png";
        ui->moon->setPixmap(QPixmap(path));
        ui->moon->show();
    }
    ui->curNum->setText(QString::number(room->seatList.size())+"/"+QString::number(room->maxnum));

}
void RoomWidget::setDefaultCard(Room*room){
    for(Card*card:userCards){
        card->setStyle();
        if(card->order>room->maxnum){
            card->picture->setIcon(QIcon(":/qrc/lock.png"));
        }
    }
}
void RoomWidget::setUserCard(Room*room){
    QVector<Seat>seatList = room->seatList;
    for(Seat seat:seatList){
        User*user=seat.user;
        int orderNum=seat.orderNum;
        Card*card=userCards[orderNum-1];
        card->name->setText(user->name);
        card->name->show();
        card->picture->setIcon(QIcon(*user->pixmap));
        if(user->id==SwyGame::user->id)card->self->show();
        if(room->state=="准备"&&user->id==room->hostId) card->host->show();
        if(room->state!="准备"){
            card->name->hide();
        }
    }
    if(room->state=="下注"){// 选中
        userCards[room->turnTo]->picture->setStyleSheet("border: 2px solid #8f8f91");
    }
}
void RoomWidget::flushUI(Room*room){
    qDebug()<<"### 刷新房间ui";
    setRoomMenu(room); // 房间菜单栏信息
    setDefaultCard(room);// 用户卡牌默认样式
    setUserCard(room); // 用户卡牌样式   根据不同的房间状态设置UI
}

void RoomWidget::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    this->show();
    flush();
    checkFlush();
}

void RoomWidget::backToGameMain(){
    SwyGame::exitRoom(SwyGame::user->id,SwyGame::room->roomId);
    flushRoomTimer.stop();
    if(WidgetManager::show("游戏主页")) this->hide();
}
void  RoomWidget::settingRoom(){

}
void RoomWidget::prepare(){
    qDebug()<<"准备";
    if( ui->prepare->text()=="准备"){
        ui->prepare->setText("取消准备");
    }else{
       ui->prepare->setText("准备");
    }

}
void  RoomWidget::startGame(){
    Room*room=SwyGame::room;
    qDebug()<<"start";
    if(!room->isFullSeat()){
        qDebug()<<"房间不满";
        return;
    }
    if(room->cntSeatState("已准备")!=room->maxnum){
        qDebug()<<"还有玩家未准备";
        return;
    }
    SwyGame::startGame(room->roomId);

}
RoomWidget::~RoomWidget(){
    delete ui;
}
