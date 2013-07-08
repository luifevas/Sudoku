/**
* @file ventanaprincipal.h
* @brief ventana principal del juego Sudoku.
* @author Luis Caviedes
* @author Luis Vasquez
*
* @date 07/07/2013
*/


#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QDialog>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QDialog
{
    Q_OBJECT
    
public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();
    
public slots:
   void on_jugar_clicked();
signals:
    void avisojugar(bool f);

private slots:
    void on_acerca_clicked();

    void on_pushButton_clicked();

    void on_salir_clicked();

private:
    Ui::VentanaPrincipal *ui;
};

#endif // VENTANAPRINCIPAL_H
