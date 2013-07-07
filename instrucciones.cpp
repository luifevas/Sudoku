#include "instrucciones.h"
#include "ui_instrucciones.h"

instrucciones::instrucciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instrucciones)
{
    ui->setupUi(this);
}

instrucciones::~instrucciones()
{
    delete ui;
}
