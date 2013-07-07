#include "ranking.h"
#include "ui_ranking.h"

Ranking::Ranking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
    model = new QStandardItemModel(3,2,this);
    for(int i=0; i<3;i++){
        QModelIndex index1 = model->index(i,0,QModelIndex());
        model->setData(index1,"h");
        QModelIndex index2 = model->index(i,1,QModelIndex());
        model->setData(index2,"hol");
    }
    ui->tableView->setModel(model);
}

Ranking::~Ranking()
{
    delete ui;
}
