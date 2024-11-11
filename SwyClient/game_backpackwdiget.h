#ifndef GAME_BACKPACKWDIGET_H
#define GAME_BACKPACKWDIGET_H

#include <QWidget>
namespace Ui {
class GameBackpackWdiget;
}

class GameBackpackWdiget : public QWidget
{
    Q_OBJECT

public:
   explicit   GameBackpackWdiget( QWidget* parent =nullptr   );

     ~GameBackpackWdiget();

private:
    Ui::GameBackpackWdiget *ui;
};

#endif // GAME_BACKPACKWDIGET_H
