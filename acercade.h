/**
* @file acercade.h
* @brief contiene una descripcion sobre los creadores del juego.
* @author Luis Caviedes
* @author Luis Vasquez
*
* @date 02/06/2013
*/


#ifndef ACERCADE_H
#define ACERCADE_H

#include <QDialog>

namespace Ui {
class acercade;
}

class acercade : public QDialog
{
    Q_OBJECT
    
public:
    explicit acercade(QWidget *parent = 0);
    ~acercade();
    
private:
    Ui::acercade *ui;
};

#endif // ACERCADE_H
