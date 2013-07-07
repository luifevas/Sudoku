#include "sudoku.h"
#include "ventanaprincipal.h"
#include <QApplication>
#include "eleccion.h"
#include "instrucciones.h"
#include "acercade.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaPrincipal v;
    v.show();






    return a.exec();
}
