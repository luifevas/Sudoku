#ifndef RANKING_H
#define RANKING_H

#include <QDialog>
#include <QtGui>

namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT
    
public:
    explicit Ranking(QWidget *parent = 0);
    QList cargarRanking();
    QList ordenarRanking(QList ranking);
    ~Ranking();
    
private:
    Ui::Ranking *ui;
     QStandardItemModel *model;
};

#endif // RANKING_H
