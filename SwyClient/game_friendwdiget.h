#ifndef GAME_FRIENDWDIGET_H
#define GAME_FRIENDWDIGET_H

#include <QWidget>
namespace Ui {
class game_friendwdiget;
}

class GameFriendWdiget : public QWidget
{
    Q_OBJECT

public:
  explicit    GameFriendWdiget(  QWidget* parent =nullptr );

     ~GameFriendWdiget();

private:
    Ui::game_friendwdiget *ui;
};

#endif // GAME_FRIENDWDIGET_H
