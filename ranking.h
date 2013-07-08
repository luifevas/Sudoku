/**
* @file ranking.h
* @brief presentacion de los jugadores que han terminado el sudoku de manera satisfactoria.
* @author Luis Caviedes
* @author Luis Vasquez
*
* @date 02/06/2013
*/


#ifndef RANKING_H
#define RANKING_H

#include <QDialog>
#include <QtGui>
#include "jugador.h"

namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT
    
public:
    explicit Ranking(QWidget *parent = 0);
    /**
    * cargarRanking() permite cargar los elementos que se encuentran almacenado en el archivo de texto ranking.txt
    una vez cargados los elementos se los almacena en un QList<Jugador> el cual se lo va a retornar.
    * @return un QList<Jugador> con los datos de todos los jugadores que han terminado el juego con sus respectivos tiempos.
    * @date 07/07/2013
    */
    QList<Jugador> cargarRanking();
    /**
    * ordenarRanking() permite ordenar de los elementos de la lista de manera ascedente tomando como referencia
    de comparación el tiempo que se tomo en finalizar el juego.
    * @param una variable de tipo QList<Jugador> donde se encuentran los jugadores obtenidos del archivo ranking.txt.
    * @return un QList<Jugador> con los datos ordenado de manera ascendente.
    * @date 07/07/2013
    */
    QList<Jugador> ordenarRanking(QList<Jugador> ranking);
    ~Ranking();

private:
    Ui::Ranking *ui;
     QStandardItemModel *model;
};

#endif // RANKING_H
