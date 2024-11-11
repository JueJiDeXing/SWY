#include "mainwdiget.h"
#include "ui_mainwdiget.h"

MainWdiget::MainWdiget(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWidget){
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/qrc/moon3.png"));
    gmw=new GameMainWdiget();
    gfw=new GameFriendWdiget();
    gbw=new GameBackpackWdiget();
    ui->stack->addWidget(gmw);
    ui->stack->addWidget(gfw);
    ui->stack->addWidget(gbw);
}

MainWdiget::~MainWdiget(){
    delete ui;
}

void MainWdiget::on_toMainWidget_triggered(){
    ui->stack->setCurrentWidget(gmw);
}

void MainWdiget::on_toFriendWidget_triggered(){
    ui->stack->setCurrentWidget(gfw);
}

void MainWdiget::on_toMyInfo_triggered(){
    ui->stack->setCurrentWidget(gbw);
}
