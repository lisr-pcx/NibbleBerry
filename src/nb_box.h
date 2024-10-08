//============================================================================
// Project: NibbleBerry
// File: nb_box.h
// Unlicense, 2024
// Visit site: github.com/lisr-pcx/NibbleBerry
//============================================================================

#ifndef NB_BOX_H
#define NB_BOX_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPoint>
#include <QCursor>
#include "nb_globals.h"

class NB_Box : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    enum BoxStatus
    {
        BLUEBERRY,
        PLAYER1,
        PLAYER2,
        NUMBER_OF_STATES // trick to get the size of enum
    };
    Q_ENUM(BoxStatus)

    NB_Box(QGraphicsItem* parent=0);

    // Getters and Setters
    BoxStatus GetStatus() { return _status; };

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void NewStatus(NB_Box* ptr_box);
    void RotateBoxes(NB_Box* ptr_box, int angle, int intensity);

private:
    BoxStatus       _status;
    QPoint          _start_pos;
    QPoint          _end_pos;
};

#endif // NB_BOX_H
