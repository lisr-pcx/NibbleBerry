//============================================================================
// Project: NibbleBerry
// File: nb_board.h
// Unlicense, 2024
// Visit site: github.com/lisr-pcx/NibbleBerry
//
// TEMPLATE for the board game element (square shape)
//============================================================================

#ifndef NB_BOARD_H
#define NB_BOARD_H

#include <vector>
#include <QDebug>

// FIXME
// currently std::vector is in charge to checks index value
// and eventually throw "out of range" exception...

// FIXME
// Index(..) is based on std::find(), it means that returns
// first valid element. When board contains multiple elements
// with the same value it has bad behavior...

// FIXME
// _S must be equal or bigger than "2" otherwise indexes
// have bad values...

template <typename _T, unsigned int _S=0>
class Board
{
public:
    struct position_t
    {
        unsigned int x;
        unsigned int y;
    };

    Board(_T default_value)
    {
        for (unsigned int n=0; n<(_S*_S); n++)
        {
            _cell.push_back(default_value);
        }
    }

    void Set(_T value, unsigned int index)
    {
        // set cell based on linear position index
        // Example 3x3
        //      1   2   3
        //      4   5   6
        //      7   8   9
        _cell.at(index - 1) = value;
    }

    void Set(_T value, unsigned int x, unsigned int y)
    {
        // set cell based on (x,y) coordinates
        // example 3x3
        //      1,1     2,1     3,1
        //      1,2     2,2     3,2
        //      1,3     2,3     3,3
        unsigned int index = XYToIndex(x, y);
        _cell.at(index - 1) = value;
    }

    _T& Get(unsigned int index)
    {
        // get cell content based on linear position index
        return (_cell.at(index - 1));
    }

    _T& Get(unsigned int x, unsigned int y)
    {
        // get cell content based on (x,y) coordinates
        unsigned int index = XYToIndex(x, y);
        return (_cell.at(index - 1));
    }

    unsigned int Index(_T value)
    {
        auto iterator = std::find(_cell.begin(), _cell.end(), value);
        auto idx = std::distance(_cell.begin(), iterator);
        return ((unsigned int) idx + 1);
    }

    position_t Position(_T value)
    {
        auto iterator = std::find(_cell.begin(), _cell.end(), value);
        auto idx = std::distance(_cell.begin(), iterator);
        position_t pos = IndexToXY((unsigned int) idx);
        return pos;
    }

    void RotateHorizontally(unsigned int y_position, int value)
    {
        // rotate elements on the same row
        // (using iterators and STL algorithms)
        auto first = _cell.begin() + (y_position-1) * _S;
        if (value > 0)
        {
            value = _S - (value % _S);
        }
        else
        {
            value = (abs(value) % _S);
        }
        auto middle = first + value;
        auto last = first + _S;
        std::rotate(first, middle, last);
    }

    void RotateVertically(unsigned int x_position, int value)
    {
        // rotate elements on the same columns
        // (copy into another structure, then it
        // works on it using iterators and STL
        // algorithms, then copy back)
        std::vector<_T> column;
        for (auto i = _cell.begin() + x_position; i < _cell.end(); i = i + k_board_size)
        {
            column.push_back(*i);
        }

        auto first = column.begin();
        if (value > 0)
        {
            value = _S - (value % _S);
        }
        else
        {
            value = (abs(value) % _S);
        }
        auto middle = first + value;
        auto last = column.end();
        std::rotate(first, middle, last);

        auto col_it = column.begin();
        auto cell_it = _cell.begin();
        for (cell_it += x_position; cell_it < _cell.end(); cell_it += k_board_size)
        {
            *cell_it = *col_it;
            col_it++;
        }
    }

private:

    unsigned int XYToIndex(unsigned int x, unsigned int y)
    {
        return ((x + (y - 1)*_S));
    }

    position_t IndexToXY(unsigned int index)
    {
        position_t value;
        if (index==0)
        {
            value = {0, 0};
        }
        else if (_S==1)
        {
            value = {1, 1};
        }
        else
        {
            value.y = (index/_S) + 1;
            value.x = index - ((value.y - 1)*_S);
        }
        return value;
    }

    std::vector<_T> _cell;
};

#endif // NB_BOARD_H
