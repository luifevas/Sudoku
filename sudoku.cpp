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

int Sudoku::verificarHorizontal(int matriz[9][9], int x, int y){
    int numero= matriz[x][y];
    int temp;
    for(int i=0;i<9;i++){
        temp=matriz[x][i];
        if(i!=y){
            if(temp==numero)
                return 1;
        }
    }
    return 0;
}





int Sudoku::verificarVertical(int matriz[9][9], int x, int y){
    int numero= matriz[x][y];
    int temp;
    for(int i=0;i<9;i++){
        temp=matriz[i][y];
        if(i!=x){
            if(temp==numero)
                return 1;
        }
    }
    return 0;
}




int Sudoku::verificarRecuadro(int matriz[9][9], int x, int y){
    int numero=matriz[x][y];
    int posX=3*(x/3);
    int posY=3*(y/3);
    for(int i=(0+posX);i<(3+posX);i++){
        for(int j=(0+posY);j<(3+posY);j++){
            if(x!=i && y!=j){
                if(numero==matriz[i][j])
                    return 1;
            }
        }
    }
    return 0;
}




int Sudoku::verificarSudoku(int matriz[9][9]){
    int numero;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            numero=matriz[i][j];
            if(numero>9 || numero<1){
               return 1;
            }
            if(verificarHorizontal(matriz,i,j)==1 || verificarVertical(matriz,i,j)==1 || verificarRecuadro(matriz,i,j)==1){
                return 1;
            }
        }
    }
    return 0;
}
