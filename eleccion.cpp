#include "eleccion.h"
#include "ui_eleccion.h"
#include "sudoku.h"

eleccion::eleccion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eleccion)
{
    ui->setupUi(this);
}

eleccion::~eleccion()
{
    delete ui;
}

void eleccion::on_empezar_clicked()
{
    int numero=0;
    if(ui->comboBox->currentText()=="Facil"){
        numero=4;

    }
    if(ui->comboBox->currentText()=="Medio"){
        numero=5;

    }
    if(ui->comboBox->currentText()=="Dificil"){
        numero=6;

    }

    sudoku *s= new sudoku(0,numero,ui->nombre->text());
    close();
    s->show();
}


void eleccion::on_nombre_textEdited(const QString &arg1)
{

}
