#ifndef JUGADOR_H
#define JUGADOR_H
#include <QString>
class Jugador
{
public:
    Jugador(QString n, int p);
    QString getNombre();
    int getPuntaje();
    void setNombre(QString n);
    void setPuntaje(int p);
 private:
    int puntaje;
    QString nombre;
};

#endif // JUGADOR_H
