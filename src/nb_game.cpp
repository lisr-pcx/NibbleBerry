#include "nb_game.h"
#include <QRect>

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
        connect(ptr_tmp, SIGNAL(NewStatus(unsigned int)), this, SLOT(ForceUpdateGUI(unsigned int)));

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

void NB_Game::ForceUpdateGUI(unsigned int index)
{
    if (index < _boxes.size())
    {
        // update single
        UpdateBoxColor(index);
    }
    else
    {
        // update all
        for (auto& item : _boxes)
        {
            UpdateBoxColor(item->GetIndex());
        }
    }
}

void NB_Game::UpdateBoxColor(unsigned int index)
{
    NB_Box* ptr_box = _boxes.at(index);
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
