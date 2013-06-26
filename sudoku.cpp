#include "sudoku.h"
#include "ui_sudoku.h"
#include "QFile"
#include "string"

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

int sudoku::verificarHorizontal(int matriz[9][9], int x, int y){
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





int sudoku::verificarVertical(int matriz[9][9], int x, int y){
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




int sudoku::verificarRecuadro(int matriz[9][9], int x, int y){
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




int sudoku::verificarSudoku(int matriz[9][9]){
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

void sudoku::on_validar_clicked()
{
    int matriz [9][9];
    int k=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            matriz[i][j]= cuadros[k]->text().toInt();
            k++;


        }


    }
    if (verificarSudoku(matriz)==0){
        ui->validar->setText("Esta correcto");


    }else{
         ui->validar->setText("Esta incorrecto");

    }

}

void sudoku:: guardarPartida(){
    int k=0;

    QFile file ("guardar.txt");
   file.open(QIODevice::WriteOnly);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){

            QDataStream out(&file);
            out <<cuadros[k]->text();
            k++;
        }
        QDataStream out(&file);
        out << "\n";
}

    file.close();

}
/*
void sudoku:: cargarPartida(){

    QFile file ("guardar.txt"),
    file.open(QIODevide::ReadOnly);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            QTextStream in(&file);
            while (in.readline != "\n") {
                QString line = in.readLine();
                process_line(line);

            }


        }





}
}
*/
void sudoku::on_pushButton_clicked()
{

    guardarPartida();

}
