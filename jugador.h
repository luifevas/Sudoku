/**
* @file jugador.h
* @brief contiene la declaracion del tipo de datos jugador y sus respectivos getter y setter.
* @author Luis Caviedes
* @author Luis Vasquez
*
* @date 07/07/2013
*/


#ifndef JUGADOR_H
#define JUGADOR_H
#include <QString>
class Jugador
{
public:
    /**
    * Jugador constructor de la clase.
    * @param n variable de tipo QString que representa el nombre del jugador.
    * @param p variable de tipo int que representa el puntaje obtenido por el jugador.
    * @date 07/07/2013
    */
    Jugador(QString n, int p);
    /**
    * getNombre proporciona el nombre del jugador.
    * @return una cadena de caracteres con el nombre del jugador.
    */
    QString getNombre();
    /**
     * getPuntaje proporciona el puntaje obtenido por el jugador.
     * @return un tipo int con el puntaje almacenado en el jugador.
     */
    int getPuntaje();
    /**
     * setNombre cambia el nombre de jugador.
     * @param n variable tipo QString que representa el nuevo nombre del jugador.
     */
    void setNombre(QString n);
    /**
     * setPuntaje cambia el puntaje de jugador.
     * @param n variable tipo int que representa el nuevo puntaje del jugador.
     */
    void setPuntaje(int p);
 private:
    int puntaje;
    QString nombre;
};

#endif // JUGADOR_H
