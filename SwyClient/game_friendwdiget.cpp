#include "game_friendwdiget.h"
#include "ui_game_friendwdiget.h"

GameFriendWdiget::GameFriendWdiget( QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::game_friendwdiget)
{
    ui->setupUi(this);
}

GameFriendWdiget::~GameFriendWdiget()
{
    delete ui;
}
