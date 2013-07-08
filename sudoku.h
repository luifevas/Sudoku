/**
* @file sudoku.h
* @brief Este archivo contiene la definicion de las funciones para el la creación, validación y presentación del sudoku. ademas permite cargar y guardar la partida.
* @author Luis Caviedes
* @author Luis Vasquez
*
* @date 07/07/2013
*/


#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLineEdit>
#include <QGridLayout>
#include <QFile>
#include <string>
#include "lcdnumber.h"
#include <QString>
#include "jugador.h"

namespace Ui {
class sudoku;
}

class sudoku : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit sudoku(QWidget *parent = 0, int dificultad=0,QString nomJugador="");
    ~sudoku();
    QList<int> listPosX;
    QList<int> listPosY;
    int matriz[9][9],matrizSudoku[9][9];

    /**
    * llenarsudoku se encarga de la creacion y presentacion en la ventana de juego del sudoku
    * @param dif
    * @param nom variable QString que representa el nombre del jugador actual.
    * @date 07/07/2013
    */
    void llenarsudoku(int dif, QString nom);
    /**
    * verificarHorizontal permite hacer la validacion de toda la fila si es que cumple las reglas del sudoku.
    * @param matriz variable int 9x9 que representa al sudoku
    * @param x variable int que representa la posicion x de la casilla que se quiere verificar.
    * @param y variable int que representa la posicion y de la casilla que se quiere verificar.
    * @return un tipo int que retorna 0 cuando la casilla verificada es correcta y 1 cuando es incorrecta.
    * @date 07/07/2013
    */
    int verificarHorizontal(int matriz[9][9], int x, int y);
    /**
    * verificarVertical permite hacer la validacion de toda la columna si es que cumple las reglas del sudoku.
    * @param matriz variable int 9x9 que representa al sudoku
    * @param x variable int que representa la posicion x de la casilla que se quiere verificar.
    * @param y variable int que representa la posicion y de la casilla que se quiere verificar.
    * @return un tipo int que retorna 0 cuando la casilla verificada es correcta y 1 cuando es incorrecta.
    * @date 07/07/2013
    */
    int verificarVertical(int matriz[9][9], int x, int y);
    /**
    * verificarRecuadro permite hacer la validacion de todo el recuadro si es que cumple las reglas del sudoku.
    * @param matriz variable int 9x9 que representa al sudoku
    * @param x variable int que representa la posicion x de la casilla que se quiere verificar.
    * @param y variable int que representa la posicion y de la casilla que se quiere verificar.
    * @return un tipo int que retorna 0 cuando la casilla verificada es correcta y 1 cuando es incorrecta.
    * @date 07/07/2013
    */
    int verificarRecuadro(int matriz[9][9], int x, int y);
    /**
    * verificarSudoku recopilación de las otras funciones de validacion ademas verifica que los numero que se encuentran en las casillas este en 1 y 9.
    * @param matriz variable int 9x9 que representa al sudoku
    * @return un tipo int que retorna 0 cuando la casilla verificada es correcta y 1 cuando es incorrecta.
    * @date 07/07/2013
    */
    int verificarSudoku(int matriz[9][9]);
    /**
    * sacarCeros remueve los ceros que se han añadido a las interfaz grafica y los reemplazo por "".
    * @date 07/07/2013
    */
    void sacarCeros();
    /**
    * llenarCeros llena toda la matriz con 0.
    * @param matriz variable int 9x9.
    * @date 07/07/2013
    */
    void llenarCeros(int matriz[9][9]);
    /**
    * esPosible hace una verificacion si el numero deseado es una opcion valida a colocar en la casilla actual.
    * @param posibilidad variable tipo int que representa el numero que se va a colocar en la casilla.
    * @param matriz variable int 9x9 que representa al sudoku
    * @param x variable int que representa la posicion x de la casilla que se quiere verificar.
    * @param y variable int que representa la posicion y de la casilla que se quiere verificar.
    * @return un tipo int que retorna 0 cuando el numero proporcionado es valido y 1 cuando es invalido.
    * @date 07/07/2013
    */
    int esPosible(int posibilidad, int matriz[9][9], int posX, int posY);
    /**
    * reiniciar elimina todo los elemento ingresados distintos de 0 que se encuentra en la fila, columna y recuadro del sudoku.
    * @param matriz variable int 9x9 que representa al sudoku
    * @param x variable int que representa la posicion x de la casilla que se quiere verificar.
    * @param y variable int que representa la posicion y de la casilla que se quiere verificar.
    * @return un QList<int> con todas la posiciones de los elementos removidos donde se han ingresado un elemento distinto de 0.
    * @date 07/07/2013
    */
    QList<int> reiniciar(int matriz[9][9], int posX, int posY);
    /**
    * listaDePosibilidades creo una lista con todos lo numero posibles que se pueden colocar en la casilla seleccionada.
    * @param matriz variable int 9x9 que representa al sudoku
    * @param x variable int que representa la posicion x de la casilla que se quiere verificar.
    * @param y variable int que representa la posicion y de la casilla que se quiere verificar.
    * @return un tipo int que retorna 0 cuando el numero proporcionado es valido y 1 cuando es invalido.
    * @date 07/07/2013
    */
    QList<int> listaDePosibilidades(int matriz[9][9], int posX, int posY);
    /**
    * copiarMatriz hace una copia de la matriz.
    * @param matriz variable int 9x9 matriz la cual se va a sacar una copia.
    * @param matrizCopia variable int 9x9 en la cual se va a llenar con los elementos que se encuentran en la variable matriz.
    * @date 07/07/2013
    */
    void copiarMatriz(int matriz[9][9], int matrizCopia[9][9]);
    /**
    * colocarPistas se colocan pista para que se pueda resolver el sudoku de acuerdo al nivel seleccionado.
    * @param matriz variable int 9x9 matriz que contiene el sudoku resuelto.
    * @param matrizSudoku variable int 9x9 matriz la cual se le va a colocar las pista y posteriormente se la presenta en la interfaz grafica.
    * @param numPistas variable tipo int la cual nos proporciona cuantas pista se le da al jugador.
    * @date 07/07/2013
    */
    void colocarPistas(int matriz[9][9], int matrizSudoku[9][9], int numPistas);
    /**
    * guardarPartida crea un archivo txt con los datos de la partida actual.
    * @date 07/07/2013
    */
    void guardarPartida();
    /**
    * obtenerMatriz obtiene los datos del sudoku que se encuentran en la interfaz grafica.
    * @param matriz variable int 9x9 matriz se le añaden los elementos que son proporcionado por la interfaz.
    * @date 07/07/2013
    */
    void obtenerMatriz(int matriz[9][9]);
    /**
    * pistaJugador coloca un numero que todavia no a sido puesto en el tablero.
    * @date 07/07/2013
    */
    void pistaJugador();
    /**
    * jugadasIncorrectas se verifica en funcion al tablero resuelto.
    * @date 07/07/2013
    */
    void jugadasIncorrectas();
    /**
    * jugadasInvalidas no validas segun el estado actual del tablero.
    * @date 07/07/2013
    */
    void jugadasInvalidas();
    /**
    * encriptar codifica el numero envia por parametro.
    * @param num variable tipo int el cual va a ser codificado.
    * @return QString que representa una cadena de caracteres del numero codificado.
    * @date 07/07/2013
    */
    QString encriptar(int num);
    /**
    * decode decodifica la cadena de caracteres que se envia por parametro.
    * @param code variable tipo QString el cual va a ser decodificado.
    * @return int que representa la decodificado de la cadena de caracteres .
    * @date 07/07/2013
    */
    int decode(QString code);
    /**
    * cargarPartida carga los datos almacenado en el archivo "guardar.txt".
    * @date 07/07/2013
    */
    void cargarPartida();
    /**
    * cargarSolucion carga los datos almacenado en el archivo "guardarS.txt".
    * @date 07/07/2013
    */
    void cargarSolucion();
    /**
    * guardarSolucion crea un archivo txt con los datos del sudoku resuelto de la partida actual.
    * @date 07/07/2013
    */
    void guardarSolucion();
    /**
    * cargarOriginal carga los datos almacenado en el archivo "guardarO.txt".
    * @date 07/07/2013
    */
    void cargarOriginal();
    /**
    * guardarOriginal crea un archivo txt con los datos iniciales de la partida actual.
    * @date 07/07/2013
    */
    void guardarOriginal();
    /**
     * @brief cargarRanking obtiene los datos almacenado en el archivo "ranking.txt".
     * @return QList<Jugador> una lista con los jugadores que se encuentran en el archivo de texto.
     */
    QList<Jugador> cargarRanking();
    /**
     * @brief guardarRanking guarda el elemento una vez concluida la partida de forma exitosa.
     * @param puntaje se guarda en el archivo el nuevo elemento.
     */
    void guardarRanking(int puntaje);
private slots:
    void on_validar_clicked();

    void on_pushButton_clicked();

    void on_pista_clicked();

    void on_cargar_clicked();

    void on_invalido_toggled(bool checked);

    void on_incorrecto_toggled(bool checked);

private:
    Ui::sudoku *ui;
    QLineEdit *cuadros[81];
    QList<int> posibilidades;
    QFile guardar;
    LCDNumber *crono;
    QString nombre;
    bool cheat=false;

};

#endif // SUDOKU_H
