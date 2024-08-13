//============================================================================
// Project: NibbleBerry
// File: nb_game.cpp
// Unlicense, 2024
// Visit site: github.com/lisr-pcx/NibbleBerry
//============================================================================

#include "nb_game.h"
#include <QRect>
#include <QVariant>
#include <stdio.h>      // C-print style debugging

NB_Game::NB_Game(QWidget* parent)
{
    // create scene
    ptr_scene = new QGraphicsScene();
    ptr_scene->setSceneRect(0,
                            0,
                            k_border_size_px*2 + k_cell_size_px*k_board_size,
                            k_border_size_px*2 + k_cell_size_px*k_board_size);

    this->setScene(ptr_scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(k_border_size_px*2 + k_cell_size_px*k_board_size,
                       k_border_size_px*2 + k_cell_size_px*k_board_size);

    // build board
    for (unsigned int y=1; y<=k_board_size; y++)
    {
        for (unsigned int x=1; x<=k_board_size; x++)
        {
            NB_Box* ptr_box = new NB_Box();

            // position, shape, colors...
            ptr_box->setRect(k_border_size_px+(k_cell_size_px*(x-1)),
                             k_border_size_px+(k_cell_size_px*(y-1)),
                             k_cell_size_px,
                             k_cell_size_px);
            ptr_box->setBrush(Qt::blue);

            // add to graphics
            ptr_scene->addItem(ptr_box);

            // signal-slot
            connect(ptr_box, SIGNAL(NewStatus(NB_Box*)), this, SLOT(UpdateBoxColor(NB_Box*)));
            connect(ptr_box, SIGNAL(RotateBoxes(NB_Box*, int, int)), this, SLOT(RotateBoxesGUI(NB_Box*, int, int)));

            // store into data structure
            _board.Set(ptr_box, x, y);
        }
    }
    this->show();
}

NB_Game::~NB_Game()
{
//    // clean-up
//    for (auto& item : _board)
//    {
//        delete item;
//    }
    delete ptr_scene;
}

// ------------
// PUBLIC SLOTS
// ------------

void NB_Game::ForceUpdateGUI()
{
    // update position of NB_Box elements
    for (unsigned int y=1; y<=k_board_size; y++)
    {
        for (unsigned int x=1; x<=k_board_size; x++)
        {
            NB_Box* ptr_box = _board.Get(x, y);
            ptr_box->setRect(k_border_size_px+(k_cell_size_px*(x-1)),
                             k_border_size_px+(k_cell_size_px*(y-1)),
                             k_cell_size_px,
                             k_cell_size_px);
            UpdateBoxColor(ptr_box);
        }
    }
    ConsoleDebug();
}

void NB_Game::UpdateBoxColor(NB_Box* ptr_box)
{
    switch(ptr_box->GetStatus())
    {
    case NB_Box::BoxStatus::BLUEBERRY:
        ptr_box->setBrush(Qt::blue);
        break;
    case NB_Box::BoxStatus::PLAYER1:
        ptr_box->setBrush(Qt::yellow);
        break;
    case NB_Box::BoxStatus::PLAYER2:
        ptr_box->setBrush(Qt::red);
        break;
    default:
        qDebug() << "ERR: invalid status";
        break;
    }
}

void NB_Game::RotateBoxesGUI(NB_Box* ptr_box, int angle, int intensity)
{
    if (ptr_box != nullptr)
    {
        Board<NB_Box*, k_board_size>::position_t pos = _board.Position(ptr_box);

        if ((pos.x > 0) &&
            (pos.y > 0))
        {
            // horizontal
            if ( ((25>=angle) && (angle>=0)) ||
                ((360>=angle) && (angle>=335)) )
            {
                _board.RotateHorizontally(pos.y, intensity);
            }
            if ((195>=angle) && (angle>=155))
            {
                _board.RotateHorizontally(pos.y, -intensity);
            }
            // vertical
            if ((285>=angle) && (angle>=245))
            {
                _board.RotateVertically(pos.x, intensity);
            }
            if ((105>=angle) && (angle>=65))
            {
                _board.RotateVertically(pos.x, -intensity);
            }
        }
        ForceUpdateGUI();
    }
}

// ---------------
// PRIVATE METHODS
// ---------------

void NB_Game::ConsoleDebug()
{
    printf("\n\n---BOXES---\n");
    for (unsigned int y=1; y<=k_board_size; y++)
    {
        for (unsigned int x=1; x<=k_board_size; x++)
        {
            printf(" %1d", _board.Get(x,y)->GetStatus());
        }
        printf("\n");
    }
    // force manually.. to have it working on C++ (so sad)
    fflush(stdout);
}
