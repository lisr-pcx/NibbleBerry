//============================================================================
// Project: NibbleBerry
// File: main.cpp
// Unlicense, 2024
//
// Visit site: github.com/lisr-pcx/NibbleBerry
// Silly experiments and games after dinner
//============================================================================

#include <QApplication>
#include "nb_game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NB_Game* ptr_game = new NB_Game();
    ptr_game->show();

    return a.exec();
}
