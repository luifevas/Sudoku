#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLineEdit>
#include <QGridLayout>


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
private:
    Ui::sudoku *ui;
    QLineEdit *cuadros[81];
};

#endif // SUDOKU_H
