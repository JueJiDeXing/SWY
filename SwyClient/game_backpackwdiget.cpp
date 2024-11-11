#include "game_backpackwdiget.h"
#include "ui_game_backpackwdiget.h"

GameBackpackWdiget::GameBackpackWdiget( QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::GameBackpackWdiget)
{
    ui->setupUi(this);
}

GameBackpackWdiget::~GameBackpackWdiget()
{
    delete ui;
}
