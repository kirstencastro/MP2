#include "2048.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

int main(int argc, char** argv) {
    G2048 game(argc > 1 ? argv[1] : NULL);
    game.startGame();
}
