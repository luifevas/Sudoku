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
    void llenarsudoku();
    int verificarHorizontal(int matriz[9][9], int x, int y);
    int verificarVertical(int matriz[9][9], int x, int y);
    int verificarRecuadro(int matriz[9][9], int x, int y);
    int verificarSudoku(int matriz[9][9]);
    void guardarPartida();
private slots:
    void on_validar_clicked();

    void on_pushButton_clicked();

private:
    Ui::sudoku *ui;
    QLineEdit *cuadros[81];
    QFile guardar;
};

#endif // SUDOKU_H
