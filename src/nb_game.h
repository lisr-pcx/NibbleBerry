#ifndef NB_GAME_H
#define NB_GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QVector>
#include <QVectorIterator>
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
    void UpdateBoxColor(NB_Box* ptr_box);
    void RotateBoxesGUI(NB_Box* ptr_box, int angle, int intensity);

private:
    void ForceUpdateGUI();
    void ScrollLeftRight(unsigned int box_index, int value);
    void ScrollUpDown(unsigned int box_index, int value);

    void ConsoleDebug();

    QVector<NB_Box*>    _boxes;
};

#endif // NB_GAME_H
