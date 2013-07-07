#include "acercade.h"
#include "ui_acercade.h"

acercade::acercade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acercade)
{
    ui->setupUi(this);

}

acercade::~acercade()
{
    delete ui;
}
