//============================================================================
// Project: NibbleBerry
// File: nb_box.cpp
// Unlicense, 2024
//
// Visit site: github.com/lisr-pcx/NibbleBerry
// Silly experiments and games after dinner
//============================================================================

#include "nb_box.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

NB_Box::NB_Box(unsigned int box_index, QGraphicsItem* parent) :
    QGraphicsEllipseItem(parent)
{
    _status = BoxStatus::BLUEBERRY;
}

void NB_Box::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // store position to identify user scroll
    _start_pos = QCursor::pos();
}

void NB_Box::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // store final position to identify user scroll
    _end_pos = QCursor::pos();

    int angle = 0;
    int intensity = qSqrt( qPow(qAbs(_end_pos.y()-_start_pos.y()),2) + qPow(qAbs(_end_pos.x()-_start_pos.x()),2)) / k_cell_size_px;

    if (intensity>0)
    {
        // User scrolling

        // FIXME: it works, but sucks...
        //        90°
        //      4 | 1
        // 180° --+-- 0°
        //      3 | 2
        //       270°

        if (_end_pos.x() > _start_pos.x())
        {
            if (_end_pos.y() < _start_pos.y())  // 1
                angle = 90 - (qAtan2((_end_pos.x() - _start_pos.x()) , (_start_pos.y() - _end_pos.y()) )  / 3.14 / 2 * 360);
            else    // 2
                angle = 270 + (qAtan2( (_end_pos.x() - _start_pos.x()) , (_end_pos.y() - _start_pos.y() ) )  / 3.14 / 2 * 360);
        }
        else
        {
            if (_end_pos.y() < _start_pos.y()) {
                // 4
                angle =  90 + (qAtan2( (_start_pos.x() - _end_pos.x()) , (_start_pos.y() - _end_pos.y()) )  / 3.14 / 2 * 360);
            } else {
                // 3
                angle =  270 - (qAtan2( (_start_pos.x() - _end_pos.x()) , (_end_pos.y() - _start_pos.y() ))  / 3.14 / 2 * 360);
            }            
        }

        // here call rotate algorithm
        emit RotateBoxes(this, angle, intensity);
    }
    else
    {
        // User clicking
        if (event->button() == Qt::LeftButton)
        {
            _status = BoxStatus::PLAYER1;
        }
        if (event->button() == Qt::RightButton)
        {
            _status = BoxStatus::PLAYER2;
        }
        emit NewStatus(this);
    }
}
