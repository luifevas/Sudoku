#include "ranking.h"
#include "ui_ranking.h"
#include <QFile>
#include <QTextStream>
#include "ventanaprincipal.h"

Ranking::Ranking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);
    QList<Jugador> ordenado;
    ordenado=ordenarRanking(cargarRanking());
    model = new QStandardItemModel(ordenado.size(),2,this);
    model->setHorizontalHeaderItem(0,new QStandardItem("Nombre"));
     model->setHorizontalHeaderItem(1,new QStandardItem("Tiempo"));
    for(int i=0; i<ordenado.size();i++){
        Jugador j= ordenado.at(i);
        QModelIndex index1 = model->index(i,0,QModelIndex());
        model->setData(index1,j.getNombre());
        QModelIndex index2 = model->index(i,1,QModelIndex());
        model->setData(index2,j.getPuntaje());
    }
    ui->tableView->setModel(model);
}

Ranking::~Ranking()
{
    delete ui;
}

QList<Jugador> Ranking:: cargarRanking(){
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

QList<Jugador> Ranking:: ordenarRanking(QList<Jugador> ranking){
    QList<Jugador> ordenado;
    int i,pos;
    while(ranking.size()!=0){
        pos=0;
        for(i=1;i<ranking.size();i++){
            Jugador j1=ranking.at(pos);
            Jugador j2=ranking.at(i);
            if(j1.getPuntaje()>j2.getPuntaje())
                pos=i;
        }
        ordenado.append(ranking.at(pos));
        ranking.removeAt(pos);
    }
    return ordenado;
}


void Ranking::on_atras_clicked()
{
    VentanaPrincipal *vp = new VentanaPrincipal();
    this->close();
    vp->show();
}
