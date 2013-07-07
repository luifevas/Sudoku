#ifndef ELECCION_H
#define ELECCION_H

#include <QDialog>

namespace Ui {
class eleccion;
}

class eleccion : public QDialog
{
    Q_OBJECT
    
public:
    explicit eleccion(QWidget *parent = 0);
    ~eleccion();
    
private slots:
    void on_empezar_clicked();

private:
    Ui::eleccion *ui;
};

#endif // ELECCION_H
