#include "sudoku.h"
#include "ui_sudoku.h"

sudoku::sudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sudoku)
{
    ui->setupUi(this);
    llenarsudoku();
}

sudoku::~sudoku()
{
    delete ui;
}
void sudoku::llenarsudoku(){
    int k=0;

    for(int i=0 ; i<9; i++){

        for(int j=0; j<9;j++){
            cuadros[k]=new QLineEdit();

            ui->slayout->addWidget(cuadros[k],i,j);
            k++;
        }


    }


}
