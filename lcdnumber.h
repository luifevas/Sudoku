/**
* @file lcdnumber.h
* @brief contiene la definicion del cronometro utilizado en la interfaz del sudoku.
* @author Luis Caviedes
* @author Luis Vasquez
*
* @date 07/07/2013
*/


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
        this->display(timeValue->toString(QString("mm:ss")));
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
      this->display(this->timeValue->toString(QString("mm:ss")));
    }

    void start(){
      this->timer->start(1);}

    void stop(){
      this->timer->stop();}

};
#endif
