#include "sudoku.h"
#include "ui_sudoku.h"
#include "QFile"
#include "string"
#include <QTime>
#include <QTextStream>
#include <iostream>
#include <QStringList>
#include <QPalette>
#include <QMessageBox>

sudoku::sudoku(QWidget *parent,int dificultad,QString nomJugador) :
    QMainWindow(parent),
    ui(new Ui::sudoku)
{
    nombre=nomJugador;
    ui->setupUi(this);
    llenarsudoku(dificultad,nomJugador);

   crono = new LCDNumber(0,0);
   ui->tlayout->addWidget(crono);
    crono->start();

}

sudoku::~sudoku()
{
    delete ui;
}
void sudoku::llenarsudoku(int dif, QString jugador){
    QTime time = QTime::currentTime();
    qsrand (time.msec());
    int a=0,k=0,numero=0,size=0,pos=0,x=0,y=0,posibilidadesSize=0;
    QList<int> removidoX;
    for(int i=0 ; i<9; i++){
        for(int j=0; j<9;j++){
            cuadros[k]=new QLineEdit();
            ui->slayout->addWidget(cuadros[k],i,j);
            //llenado las listas listPosX y listPosY con todas las casilla disponibles
            listPosX.append(i);
            listPosY.append(j);
            k++;
        }
    }
// comienzo de la creacion del sudoku
    // Se llena las matriz con ceros
    llenarCeros(matriz);
        while(listPosX.size()!=0){
            // Se eliminan todos los datos que se encuentran almacenados en la lista de posibilidades
            posibilidades.clear();
            // Se obtiene el tamaño de las lista de posibles casilla
            size=listPosX.size();
            // Se genera un numero aleatorio entre 0 y el tamaño de la lista para obtener una casilla disponble
            pos= qrand()%size;
            // obtiene las posiciones X y Y que se encuentran en la posicion "pos" de las listas
            x=listPosX.at(pos);
            y=listPosY.at(pos);
            // Se genera una lista de posibles numero a colocar en la casilla
            posibilidades=listaDePosibilidades(matriz,x,y);
         // matriz[x][y]=0;
            // Se obtiene el tamaño de la lista de posibilidades
            posibilidadesSize=posibilidades.size();
            if(posibilidadesSize!=0){
                // Se obtiene un numero aleatorio entre 0 y el numero de posibles numeros
                numero= qrand()%posibilidadesSize;
                // Se coloca el numero obtenido en el sudoku
                matriz[x][y]=posibilidades.at(numero);
                // Se remueve de las listas los elementos que se encuentran en las posicion "pos"
                listPosX.removeAt(pos);
                listPosY.removeAt(pos);
            }else{
                // Se eliminan los datos almacenado en la lista de numero removidos
                removidoX.clear();
                // Se añaden las posiciones de los numeros removidos a una lista temporal
                removidoX=reiniciar(matriz,x,y);
                for(a=0;a<removidoX.size();a=a+2){
                    //Se añaden los elementos que se encuentran en la lista temporal a la lista de posibles casillas
                    listPosX.append(removidoX.at(a));
                    listPosY.append(removidoX.at(a+1));
                }
            }
        }
        // Se llena una matriz de ceros con pista para ser resuelto
        colocarPistas(matriz,matrizSudoku,dif);
        k=0;
        for(int i=0 ; i<9; i++){
            for(int j=0; j<9;j++){
                numero=matrizSudoku[i][j];
                cuadros[k]->setText(QString::number(numero));
                if(numero!=0){
                    cuadros[k]->setEnabled(false);
                }
                k++;
            }
        }
        sacarCeros();
}

void sudoku:: llenarCeros(int matriz[9][9]){

    for(int i=0 ; i<9; i++){

        for(int j=0; j<9;j++){
            matriz[i][j]=0;
        }
    }
}

void sudoku:: sacarCeros(){
    int k=0;
    for(int i=0 ; i<9; i++){

        for(int j=0; j<9;j++){
            if((cuadros[k]->text().toInt())==0){
                cuadros[k]->setText("");
            }
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

int sudoku::esPosible(int posibilidad, int matriz[9][9], int posX, int posY){
    int bandera=2;
    matriz[posX][posY]=posibilidad;
    bandera=verificarHorizontal(matriz,posX,posY);
    if(bandera==1){
        matriz[posX][posY]=0;
        return 1;
    }
    bandera=verificarVertical(matriz,posX,posY);
    if(bandera==1){
        matriz[posX][posY]=0;
        return 1;
    }
    bandera=verificarRecuadro(matriz,posX,posY);
    if(bandera==1){
        matriz[posX][posY]=0;
        return 1;
    }
    matriz[posX][posY]=0;
    return 0;
}

QList<int> sudoku::reiniciar(int matriz[9][9], int posX, int posY){
    QList<int> posiciones;
    int i,j;
    // Se colocaran ceros en la respectiva columna, fila, recuadro ademas se actualizara la lista de posibles posiciones
    // Se coloca ceros en la toda la fila posX
    for(i=0;i<9;i++){
        if(matriz[posX][i]!=0){
            posiciones.append(posX);
            posiciones.append(i);
        }
        matriz[posX][i]=0;
    }
    // Se coloca ceros en toda la columna posY
    for(i=0;i<9;i++){
        if(matriz[i][posY]!=0){
            posiciones.append(i);
            posiciones.append(posY);
        }
        matriz[i][posY]=0;
    }
    // Se coloca ceros en todo el recuadro donde se encuantra contenido la posicion posX y posY
    int X=3*(posX/3);
    int Y=3*(posY/3);
    for(i=(0+X);i<(3+X);i++){
        for(j=(0+Y);j<(3+Y);j++){
            if(matriz[i][j]!=0){
                posiciones.append(i);
                posiciones.append(j);
            }
            matriz[i][j]=0;
        }
    }
    return posiciones;
}

QList<int> sudoku::listaDePosibilidades(int matriz[9][9], int posX, int posY){
    int i=0;
    QList<int> posibilidad;
    for(i=1;i<10;i++){
        if(esPosible(i,matriz,posX,posY)==0)
            posibilidad.append(i);
    }
    return posibilidad;
}

// Proporciona una copia de la matriz

void sudoku:: copiarMatriz(int matriz[9][9], int matrizCopia[9][9]){
    int i=0,j=0;
    llenarCeros(matrizCopia);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            matrizCopia[i][j]=matriz[i][j];
        }
    }
}

// Se colocan las Pista segun el nivel de dificultad elegido

void sudoku:: colocarPistas(int matriz[9][9], int matrizSudoku[9][9], int numPistas){
    copiarMatriz(matriz,matrizSudoku);
    int i=0,j=0,x=0,y=0,cont=0;
    QTime time = QTime::currentTime();
    qsrand (time.msec());
    int random;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            while(cont<=numPistas){
                for(x=0;x<9;x++){
                    for(y=0;y<9;y++){
                        if(cont<=numPistas){
                            if(i==(x/3) && j==(y/3)){
                                random = qrand()%2;
                                //vaciar=rnd.nextInt(2);
                                if (random==1){
                                    matrizSudoku[x][y]=0;
                                    cont++;
                                }
                            }
                        }
                    }
                }
            }
            cont=0;
        }
    }
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
        QMessageBox::information(this,"Felicitaciones!","Ha terminado este sudoku!");
        crono->stop();
        int p1=crono->timeValue->second();
        int p2=crono->timeValue->minute();
        p2=p2*60;
        guardarRanking(p1+p2);
    }else{
         QMessageBox::warning(this,"Lo siento","Hay errores en este sudoku");
    }
}

void sudoku:: guardarPartida(){
    int matriz[9][9];
    llenarCeros(matriz);
    obtenerMatriz(matriz);
    QFile file ("guardar.txt");
    file.open(QIODevice::WriteOnly);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             QTextStream out(&file);
             if((i==8)&&(j==8)){
             out <<encriptar(matriz[i][j]);}
             else
             out <<encriptar(matriz[i][j]).append(",");
        }
         QTextStream out(&file);
            out << "\n";
}
    file.close();
}

void sudoku:: cargarPartida(){
    int k=0;
    QFile file ("guardar.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line = in.readAll();
    QStringList listastr;
    listastr.clear();
    listastr=line.split(",",QString::SkipEmptyParts);
    for(k=0;k<81;k++){
        int numero=decode(listastr.at(k));
        if(numero==0){
            cuadros[k]->setText("");
        }
        else
            cuadros[k]->setText(QString::number(numero));
    }
    file.close();
}

void sudoku::guardarSolucion(){
    QFile file ("guardarS.txt");
    file.open(QIODevice::WriteOnly);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             QTextStream out(&file);
             if((i==8)&&(j==8)){
             out <<encriptar(matriz[i][j]);}
             else
             out <<encriptar(matriz[i][j]).append(",");
        }
         QTextStream out(&file);
            out << "\n";
}
    file.close();
}

void sudoku::cargarSolucion(){
    int i=0, j=0,k=0;
    QFile file ("guardarS.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString line = in.readAll();
    QStringList listastr;
    listastr.clear();
    listastr=line.split(",",QString::SkipEmptyParts);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            int numero=decode(listastr.at(k));
            matriz[i][j]= numero;
            k++;
        }
    }
}

void sudoku::guardarOriginal(){
    QFile file ("guardarO.txt");
    file.open(QIODevice::WriteOnly);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             QTextStream out(&file);
             if((i==8)&&(j==8)){
             out <<encriptar(matrizSudoku[i][j]);}
             else
             out <<encriptar(matrizSudoku[i][j]).append(",");
        }
         QTextStream out(&file);
            out << "\n";
}
    file.close();
}

void sudoku::cargarOriginal(){
    int i=0, j=0,k=0;
    QFile file ("guardarO.txt");
    file.open(QIODevice::ReadOnly);
                QTextStream in(&file);
                QString line = in.readAll();
                QStringList listastr;
                listastr.clear();
                listastr=line.split(",",QString::SkipEmptyParts);
                for(i=0;i<9;i++){
                    for(j=0;j<9;j++){
                        int numero=decode(listastr.at(k));
                        matrizSudoku[i][j]= numero;
                        if(numero!=0){
                            cuadros[k]->setEnabled(false);
                        }
                     k++;
                    }
                }
}

void sudoku:: obtenerMatriz(int matriz[9][9]){
    int k=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(cuadros[k]->text()==NULL){
                matriz[i][j]=0;
            }
            matriz[i][j]=cuadros[k]->text().toInt();
            k++;
        }
    }
}

void sudoku:: pistaJugador(){
    int matrizTemp[9][9],i,j,k=0;
    QList<int> posX,posY;
    QTime time = QTime::currentTime();
    qsrand (time.msec());
    int random;
    posX.clear();
    posY.clear();
    llenarCeros(matrizTemp);
    obtenerMatriz(matrizTemp);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matrizTemp[i][j]==0){
                posX.append(i);
                posY.append(j);
            }
        }
    }
    random = qrand()%(posX.size());
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i==posX.at(random) && j==posY.at(random)){
                cuadros[k]->setText(QString::number(matriz[i][j]));
            }
            k++;
        }
    }
}

void sudoku:: jugadasInvalidas(){
    int i,j,k=0;
    int matrizTemp[9][9];
    llenarCeros(matrizTemp);
    obtenerMatriz(matrizTemp);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matrizTemp[i][j]<10 && matrizTemp[i][j]>0){
                if(verificarHorizontal(matrizTemp,i,j)==1 || verificarVertical(matrizTemp,i,j)==1 || verificarRecuadro(matrizTemp,i,j)==1){
                    //cambio de la casilla en la ventana
                    QPalette *palette = new QPalette();
                     palette->setColor(QPalette::Base,Qt::red);
                     cuadros[k]->setPalette(*palette);
                }
            }else{
                QPalette *palette = new QPalette();
                 palette->setColor(QPalette::Base,Qt::red);
                 cuadros[k]->setPalette(*palette);
            }
            k++;
        }
    }
}

void sudoku:: jugadasIncorrectas(){
    int i,j,k=0;
    int matrizTemp[9][9];
    llenarCeros(matrizTemp);
    obtenerMatriz(matrizTemp);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matrizTemp[i][j]<10 && matrizTemp[i][j]>0){
                if(matriz[i][j]!=matrizTemp[i][j]){
                    QPalette *palette = new QPalette();
                     palette->setColor(QPalette::Base,Qt::red);
                     cuadros[k]->setPalette(*palette);
                }
            }else{
                QPalette *palette = new QPalette();
                 palette->setColor(QPalette::Base,Qt::red);
                 cuadros[k]->setPalette(*palette);
            }
            k++;
        }
    }
}

void sudoku::on_pushButton_clicked()
{
    guardarOriginal();
    guardarPartida();
    guardarSolucion();
}

void sudoku::on_pista_clicked()
{
    pistaJugador();
}

QString sudoku:: encriptar(int num){
            if(num==0){
              return "0011";
            }
            if(num==1){
              return "0100";
            }
            if(num==2){
             return "0101";
            }
            if(num==3){
              return "0110";
            }
            if(num==4){
              return "0111";
            }
            if(num==5){
              return "1000";
            }
            if(num==6){
              return "1001";
            }
            if(num==7){
              return "1010";
            }
            if(num==8){
              return "1011";
            }
            if(num==9){
              return "1100";
            }
}

int sudoku::decode(QString codigo){
    int code = codigo.toInt();
    if(code==11){
      return 0;
    }
    if(code==100){
      return 1 ;
    }
    if(code==101){
     return 2 ;
    }
    if(code==110){
      return 3;
    }
    if(code==111){
      return 4;
    }
    if(code==1000){
      return 5;
    }
    if(code==1001){
      return 6;
    }
    if(code==1010){
      return 7;
    }
    if(code==1011){
      return 8;
    }
    if(code==1100){
      return 9;
    }
}

void sudoku::on_cargar_clicked()
{
    for(int i=0;i<81;i++){
        cuadros[i]->setEnabled(true);
    }
    cargarOriginal();
    cargarPartida();
    cargarSolucion();
}

void sudoku::on_invalido_toggled(bool checked)
{
    if(checked){
     jugadasInvalidas();
}
    if(!checked){
        int k=0;
        for(k=0;k<81;k++){
            QPalette *palette = new QPalette();
             palette->setColor(QPalette::Base,Qt::white);
             cuadros[k]->setPalette(*palette);
        }
    }
}

void sudoku::on_incorrecto_toggled(bool checked)
{
    if(checked){
     jugadasIncorrectas();
}
    if(!checked){
        int k=0;
        for(k=0;k<81;k++){
            QPalette *palette = new QPalette();
             palette->setColor(QPalette::Base,Qt::white);
             cuadros[k]->setPalette(*palette);
        }
    }
}

QList<Jugador> sudoku:: cargarRanking(){
    QList<Jugador> ranking;
    QFile file ("ranking.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd()){
        QString linea= in.readLine();
        Jugador *tmp= new Jugador(linea.section(',',0,0),linea.section(',',1,1).toInt());
        ranking.append(*tmp);
    }
    return ranking;
}

void sudoku::guardarRanking(int puntaje){
    QList<Jugador> ranking=cargarRanking();
    Jugador *tmp=new Jugador(nombre,puntaje);
    ranking.append(*tmp);
    QFile file ("ranking.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    for(int i=0; i<ranking.size();i++){
       Jugador j=ranking.at(i);
       QString str1=j.getNombre();
       QString str2= QString::number(j.getPuntaje());
       str1.append(',');
       str1.append(str2);
       out<<str1;
       out << "\n";
    }
    file.close();
}

