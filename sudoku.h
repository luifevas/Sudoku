#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLineEdit>
#include <QGridLayout>
#include <QFile>
#include <string>


namespace Ui {
class sudoku;
}

class sudoku : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit sudoku(QWidget *parent = 0);    
    ~sudoku();
    QList<int> listPosX;
    QList<int> listPosY;
    void llenarsudoku();
    int verificarHorizontal(int matriz[9][9], int x, int y);
    int verificarVertical(int matriz[9][9], int x, int y);
    int verificarRecuadro(int matriz[9][9], int x, int y);
    int verificarSudoku(int matriz[9][9]);
    void sacarCeros();
    void llenarCeros(int matriz[9][9]);
    int esPosible(int posibilidad, int matriz[9][9], int posX, int posY);
    QList<int> reiniciar(int matriz[9][9], int posX, int posY);
    QList<int> listaDePosibilidades(int matriz[9][9], int posX, int posY);
    void guardarPartida();
private slots:
    void on_validar_clicked();

    void on_pushButton_clicked();

private:
    Ui::sudoku *ui;
    QLineEdit *cuadros[81];
    QList<int> posibilidades;
    QFile guardar;
};

#endif // SUDOKU_H
