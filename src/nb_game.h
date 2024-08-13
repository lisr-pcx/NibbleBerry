//============================================================================
// Project: NibbleBerry
// File: nb_game.h
// Unlicense, 2024
// Visit site: github.com/lisr-pcx/NibbleBerry
//============================================================================

#ifndef NB_GAME_H
#define NB_GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QVector>
#include <QVectorIterator>
#include "nb_globals.h"
#include "nb_box.h"
#include "nb_board.h"

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

    //QVector<NB_Box*>    _board;
    Board<NB_Box*, k_board_size> _board{Board<NB_Box*, k_board_size>(nullptr)};
};

#endif // NB_GAME_H
