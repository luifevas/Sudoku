#include "jugador.h"
#include <QString>

Jugador::Jugador(QString nom, int p)
{
    this->nombre=nom;
    this->puntaje=p;


}
QString Jugador::getNombre(){
    return this->nombre;
}
int Jugador:: getPuntaje(){

    return this->puntaje;

}
void Jugador::setNombre(QString n){
      this->nombre=n;
}
void Jugador:: setPuntaje(int p){
    this->puntaje=p;

}
