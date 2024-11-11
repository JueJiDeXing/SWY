#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "Util.h"
#include "Swygame.h"
namespace Ui {
class Register;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
   explicit   RegisterWidget(  QWidget* parent =nullptr );
    ~RegisterWidget();
private slots:
    void onBack();
    void onRegister();
private:
    Ui::Register *ui;
};

#endif // REGISTER_H
