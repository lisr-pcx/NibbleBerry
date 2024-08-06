#ifndef NB_BOX_H
#define NB_BOX_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPoint>
#include <QCursor>
#include "nb_globals.h"

class NB_Box : public QObject, public QGraphicsRectItem
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

    NB_Box(unsigned int box_index, QGraphicsItem* parent=0);

    // Getters and Setters
    unsigned int GetIndex() { return _index; };
    BoxStatus GetStatus() { return _status; };

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void NewStatus(unsigned int index);

private:
    unsigned int    _index;
    BoxStatus       _status;
    QPoint          _start_pos;
    QPoint          _end_pos;
};

#endif // NB_BOX_H
