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
    void llenarsudoku(int dif, QString nom);
    int verificarHorizontal(int matriz[9][9], int x, int y);
    int verificarVertical(int matriz[9][9], int x, int y);
    int verificarRecuadro(int matriz[9][9], int x, int y);
    int verificarSudoku(int matriz[9][9]);
    void sacarCeros();
    void llenarCeros(int matriz[9][9]);
    int esPosible(int posibilidad, int matriz[9][9], int posX, int posY);
    QList<int> reiniciar(int matriz[9][9], int posX, int posY);
    QList<int> listaDePosibilidades(int matriz[9][9], int posX, int posY);
    void copiarMatriz(int matriz[9][9], int matrizCopia[9][9]);
    void colocarPistas(int matriz[9][9], int matrizSudoku[9][9], int numPistas);
    void guardarPartida();
    void obtenerMatriz(int matriz[9][9]);
    void pistaJugador();
    void jugadasIncorrectas();
    void jugadasInvalidas();
    int finDeJuego();
    QString encriptar(int num);
    int decode(QString code);
    void cargarPartida();
    void cargarSolucion();
    void guardarSolucion();
    void cargarOriginal();
    void guardarOriginal();
    QList<Jugador> cargarRanking();
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

};

#endif // SUDOKU_H
