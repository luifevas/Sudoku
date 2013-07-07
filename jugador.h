#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador
{
public:
    Jugador();
    QString getNombre();
    int getPuntaje();
    void setNombre(QString n);
    void setPuntaje(int p);
 private:
    int puntaje;
    String nombre;
};

#endif // JUGADOR_H
