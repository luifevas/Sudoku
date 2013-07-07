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
    sudoku *s= new sudoku();
    close();
    s->show();
}
