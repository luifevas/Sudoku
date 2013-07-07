#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <QDialog>

namespace Ui {
class instrucciones;
}

class instrucciones : public QDialog
{
    Q_OBJECT
    
public:
    explicit instrucciones(QWidget *parent = 0);
    ~instrucciones();
    
private:
    Ui::instrucciones *ui;
};

#endif // INSTRUCCIONES_H
