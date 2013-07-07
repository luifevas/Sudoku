#include "ranking.h"
#include "ui_ranking.h"

Ranking::Ranking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
    QList ordenado,ranking;
    ordenado=ordenarRanking(cargarRanking());
    model = new QStandardItemModel(ordenado.size(),2,this);
    model->setHorizontalHeaderItem(0,new QStandardItem("Nombre"));
     model->setHorizontalHeaderItem(1,new QStandardItem("Tiempo"));
    for(int i=0; i<ordenado.size();i++){
        QModelIndex index1 = model->index(i,0,QModelIndex());
        model->setData(index1,ordenado.at(i));
        QModelIndex index2 = model->index(i,1,QModelIndex());
        model->setData(index2,ordenado.at(i));
    }
    ui->tableView->setModel(model);
}

Ranking::~Ranking()
{
    delete ui;
}

QList Ranking:: cargarRanking(){
    QList ranking;
    retturn ranking;
}

QList Ranking:: ordenarRanking(QList ranking){
    QList ordenado;
    int i,pos;
    while(ranking.size()!=0){
        pos=0;
        for(i=1;i<ranking.size();i++){
            if(ranking.at(pos)>ranking.at(i))
                pos=i;
        }
        ordenado.append(ranking.at(pos));
        ranking.removeAt(pos);
    }
    return ordenado
}

