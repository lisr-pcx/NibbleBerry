#ifndef NB_GAME_H
#define NB_GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QVector>
#include "nb_globals.h"
#include "nb_box.h"

class NB_Game : public QGraphicsView
{
    Q_OBJECT

public:    
    NB_Game(QWidget* parent=0);
    ~NB_Game();

    QGraphicsScene*     ptr_scene;    

public slots:
    void ForceUpdateGUI(unsigned int index);
    void UpdateBoxColor(unsigned int index);

private:
    QVector<NB_Box*>    _boxes;
};

#endif // NB_GAME_H
