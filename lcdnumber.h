#ifndef LCDNUMBER_H
#define LCDNUMBER_H
#include <QLCDNumber>
#include <QtGui>
class LCDNumber: public QLCDNumber
{
  Q_OBJECT

  public:
  QTimer* timer;
  QTime*  timeValue;


  public:
    LCDNumber(int minutes,int seconds){
        timer	= 	new QTimer();
        timeValue	=	new QTime(0,minutes,seconds,0);
        this->display(timeValue->toString(QString("ss")));
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setDisplay()));

    }
    ~ LCDNumber(){

    };

   public slots:
    void setDisplay()
    {
      this->timeValue->setHMS(0,this->timeValue->addMSecs(+1).minute(),
                    this->timeValue->addMSecs(+1).second(),
                    this->timeValue->addMSecs(+1).msec());
      this->display(this->timeValue->toString(QString("ss")));
    }

    void start(){
      this->timer->start(1);}

    void stop(){
      this->timer->stop();}

};
#endif
