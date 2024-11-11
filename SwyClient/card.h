#ifndef CARD_H
#define CARD_H
#include <QPushButton>
#include <QLabel>

class Card{
public:
    int order;
    bool use;
    Card(int order){
        this->order=order;
    }
    QPushButton*picture;
    QLabel*host,*self,*num,*status;
    QLabel*name;

    void setPos(){
        if(order<=5){
            picture->setGeometry(20,120*order,80,80);
            setGeometry(picture,host,0,0,40,20);
            setGeometry(picture,self,0,60,20,20);
            setGeometry(picture,num,35,75,15,15);
            setGeometry(picture,status,25,30,40,20);
            setGeometry(picture,name,100,30,40,20);
        } else{
            picture->setGeometry(600,120*(order-5),80,80);
            setGeometry(picture,host,45,0,40,20);
            setGeometry(picture,self,60,60,20,20);
            setGeometry(picture,num,35,75,15,15);
            setGeometry(picture,status,25,30,40,20);
            setGeometry(picture,name,-50,30,40,20);
        }
    }

    void setStyle(){
        host->hide();
        self->hide();
        status->hide();
        picture->setIconSize( picture->size());
    }
    void setUse(int maxnum){
        use=order<=maxnum;
    }

    void setGeometry(QWidget*reference,QWidget*needSet,int ox,int oy,int w,int h){
        needSet->setGeometry(reference->x()+ox,reference->y()+oy,w,h);
    }
};

#endif // CARD_H
