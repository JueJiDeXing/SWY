#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Swygame.h"
#include <QMessageBox>
#include <Util.h>

namespace Ui {
    class login;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
   explicit  LoginWidget( QWidget* parent =nullptr  );
    ~LoginWidget();
    bool autoLogin();
private slots:
    void onLogin();
    void onRegister();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
