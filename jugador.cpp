#include "jugador.h"
#include <QString>

Jugador::Jugador(QString nom)
{
    this->nombre=nom;
    this->puntaje=0;


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
