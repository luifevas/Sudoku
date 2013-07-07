#include "lcdnumber.h"

LCDNumber::LCDNumber(QVBoxLayout*& verticalLayout,int minutes,int seconds)
{
    timer	= 	new QTimer();
   timeValue	=	new QTime(0,minutes,seconds,0);
   verticalLayout->addWidget(this);
   this->display(timeValue->toString(QString("mm:ss")));
   QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setDisplay()));

}
void LCDNumber:: setDisplay()
    {
      this->timeValue->setHMS(0,this->timeValue->addMSecs(+1).minute(),
                    this->timeValue->addMSecs(+1).second(),
                    this->timeValue->addMSecs(+1).msec());
      this->display(this->timeValue->toString(QString("mm:ss")));
    }

void LCDNumber:: start(){
    this->timer->start();


}

void LCDNumber:: stop(){

    this->timer->stop();

}
