#ifndef GAME_MAINWDIGET_H
#define GAME_MAINWDIGET_H

#include <QWidget>
namespace Ui {
class game_mainwdiget;
}

class GameMainWdiget : public QWidget
{
    Q_OBJECT

public:
 explicit     GameMainWdiget(  QWidget* parent =nullptr  );

    ~GameMainWdiget();

private slots:
    void toUserMainWidget();
    void createRoom();
    void enterRoom();
protected:
    void showEvent(QShowEvent *event) override ;
private:
    Ui::game_mainwdiget *ui;
};

#endif // GAME_MAINWDIGET_H
