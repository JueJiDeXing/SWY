#include "user_mainwidget.h"
#include "ui_user_mainwidget.h"
#include <QFileDialog>
#include "Swygame.h"
#include "widgetmanager.h"
UserMainWidget::UserMainWidget(  QWidget*parent)
    : QWidget(parent)
    , ui(new Ui::user_mainwidget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/qrc/moon2.png"));
    connect(ui->changePicture,&QPushButton::clicked,this,&UserMainWidget::onUploadPicture);
    connect(ui->backButton,&QPushButton::clicked,this,&UserMainWidget::backToGameMainWidget);

}
void UserMainWidget::backToGameMainWidget(){
    if(WidgetManager::show("游戏主页"))  this->hide();
}

void UserMainWidget::showEvent(QShowEvent *event) {
    // 调用父类的showEvent方法
    QWidget::showEvent(event);

    // 调用自定义的flush方法
    if(SwyGame::user->login){
        SwyGame::flushUserInfo();
    }
    ui->name->setText(SwyGame::user->name);
    ui->picture->setIcon(*SwyGame::user->pixmap);
    ui->picture->setIconSize(ui->picture->size());
    this->show();
}

void UserMainWidget::onUploadPicture(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("PNG Images (*.png)"));

    if (fileName.isEmpty()) return;
    qDebug()<<"用户选择了文件";
    QPixmap pixmap(fileName);
    if (!pixmap.isNull()) {
        qDebug()<<"加载成功";
        QJsonObject data=SwyGame::uploadPicture(SwyGame::user->id, pixmap);
        if(data["success"]==true){
            qDebug()<<"上传成功";
            ui->picture->setIcon(pixmap);
            ui->picture->setIconSize(ui->picture->size());
        }
        else{
            qDebug()<<"上传失败";
        }
    }
}


UserMainWidget::~UserMainWidget()
{
    delete ui;
}
