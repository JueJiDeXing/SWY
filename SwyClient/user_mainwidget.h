#ifndef USER_MAINWIDGET_H
#define USER_MAINWIDGET_H

#include <QWidget>
namespace Ui {
class user_mainwidget;
}

class UserMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserMainWidget( QWidget*parent=nullptr);
    ~UserMainWidget();
private slots:
   void backToGameMainWidget();
    void onUploadPicture();
protected:
   void showEvent(QShowEvent *event) override;
private:
    Ui::user_mainwidget *ui;
};

#endif // USER_MAINWIDGET_H
