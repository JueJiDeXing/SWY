#ifndef MAINWDIGET_H
#define MAINWDIGET_H

#include <QMainWindow>
#include "widgetmanager.h"
#include "game_mainwdiget.h"
#include "game_friendwdiget.h"
#include "game_backpackwdiget.h"
#include <QStackedWidget>
namespace Ui {
class MainWidget;
}

class MainWdiget : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWdiget(QWidget* parent =nullptr );
    MainWdiget( WidgetManager* manager );
    ~MainWdiget();

private slots:
    void on_toMainWidget_triggered();

    void on_toFriendWidget_triggered();

    void on_toMyInfo_triggered();

private:
    Ui::MainWidget *ui;
    QStackedWidget stack;
    GameMainWdiget *gmw;
    GameFriendWdiget *gfw;
    GameBackpackWdiget *gbw;
};

#endif // MAINWDIGET_H
