//============================================================================
// Project: NibbleBerry
// File: nb_game.cpp
// Unlicense, 2024
//
// Visit site: github.com/lisr-pcx/NibbleBerry
// Silly experiments and games after dinner
//============================================================================

#include "nb_game.h"
#include <QRect>
#include <QVariant>

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
    for (unsigned int idx=0; idx<(k_board_size*k_board_size); idx++)
    {
        NB_Box* ptr_tmp = new NB_Box(idx);
        ptr_tmp->setRect(k_border_size_px+(k_cell_size_px*(idx%k_board_size)),
                         k_border_size_px+(k_cell_size_px*(idx/k_board_size)),
                         k_cell_size_px,
                         k_cell_size_px);

        // default color at start-up
        ptr_tmp->setBrush(Qt::blue);

        // signal-slot
        connect(ptr_tmp, SIGNAL(NewStatus(NB_Box*)), this, SLOT(UpdateBoxColor(NB_Box*)));
        connect(ptr_tmp, SIGNAL(RotateBoxes(NB_Box*, int, int)), this, SLOT(RotateBoxesGUI(NB_Box*, int, int)));

        _boxes.push_back(ptr_tmp);
        ptr_scene->addItem(ptr_tmp);
    }

    this->show();
}

NB_Game::~NB_Game()
{
    // clean-up
    for (auto& item : _boxes)
    {
        delete item;
    }
    delete ptr_scene;
}

// ------------
// PUBLIC SLOTS
// ------------

void NB_Game::ForceUpdateGUI()
{
    // update position of NB_Box elements
    for (unsigned int idx=0; idx<(k_board_size*k_board_size); idx++)
    {
        NB_Box* ptr_tmp = _boxes.at(idx);
        ptr_tmp->setRect(k_border_size_px+(k_cell_size_px*(idx%k_board_size)),
                         k_border_size_px+(k_cell_size_px*(idx/k_board_size)),
                         k_cell_size_px,
                         k_cell_size_px);
        UpdateBoxColor(ptr_tmp);
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
        auto iterator = std::find(_boxes.begin(), _boxes.end(), ptr_box);
        if (iterator != _boxes.end())
        {
            // Find the correspondig index of the box
            unsigned int index = iterator - _boxes.begin();

            if ( ((20>=angle) && (angle>=0)) ||
                 ((360>=angle) && (angle>=340)) )
            {
                ScrollLeftRight(index, intensity);
            }
            if ((200>=angle) && (angle>=160))
            {
                ScrollLeftRight(index, -intensity);
            }

            if ((290>=angle) && (angle>=250))
            {
                ScrollUpDown(index, intensity);
            }
            if ((110>=angle) && (angle>=70))
            {
                ScrollUpDown(index, -intensity);
            }
            ForceUpdateGUI();
        }
    }
}

// ---------------
// PRIVATE METHODS
// ---------------

void NB_Game::ScrollLeftRight(unsigned int box_index, int value)
{
    // identify first element of the row
    unsigned int start = (box_index / k_board_size) * k_board_size;
    // normalize to avoid useless loops and convert
    // to use only left shifting
    if (value>0)
    {
        value=k_board_size-(value%k_board_size);
    }

    // for value times
    for (int t=0; t<abs(value); t++)
    {
        // store first value for later insert
        NB_Box* first = _boxes.at(start);
        // shifting left of one position
        for (int k=start; k<(start+k_board_size-1); k++)
        {
            _boxes.replace(k, _boxes.at(k+1));
        }
        // later insert
        _boxes.replace(start+k_board_size-1, first);
    }
}

void NB_Game::ScrollUpDown(unsigned int box_index, int value)
{
    // identify first element of the column
    unsigned int start = (box_index % k_board_size);
    // normalize to avoid useless loops and convert
    // to use only left shifting
    if (value>0)
    {
        value=k_board_size-(value%k_board_size);
    }
    qDebug() << "shifting up by:" << value << " start on " << start;

    // for value times
    for (int t=0; t<abs(value); t++)
    {
        // store first value for later insert
        NB_Box* first = _boxes.at(start);
        // shifting up of one position
        for (int k=start; k<(k_board_size-1)*k_board_size; k=k+k_board_size)
        {
            _boxes.replace(k, _boxes.at(k+k_board_size));
        }
        // later insert
        _boxes.replace(start+(k_board_size-1)*k_board_size, first);
    }
}

void NB_Game::ConsoleDebug()
{
    printf("\n\n---BOXES---");
    for (int k=0; k<_boxes.size(); k++)
    {
        if ((k%k_board_size)==0)
        {
            printf("\n");
        }
        printf(" %1d", _boxes.at(k)->GetStatus());
    }
    // force manually.. to have it working on C++ (so sad)
    fflush(stdout);
}
