#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "eleccion.h"
#include "acercade.h"
#include "ranking.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}


void VentanaPrincipal::on_jugar_clicked()
{

    eleccion *e= new eleccion();
    close();
    e->show();
}


void VentanaPrincipal::on_acerca_clicked()
{
    acercade *a= new acercade();
    close();
    a->show();
}

void VentanaPrincipal::on_pushButton_clicked()
{
    Ranking *r= new Ranking();
    close();
    r->show();
}

void VentanaPrincipal::on_salir_clicked()
{
    this->close();
}
