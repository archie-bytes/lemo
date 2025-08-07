#ifndef LEMO_GAME_H
#define LEMO_GAME_H

#include <array>
#include <SFML/Graphics.hpp>
#include "../level/level.h"

class Game {
public:
    explicit Game(std::array<Level, 3> levels);

    void run();

private:

    std::array<Level, 3> levels;

    sf::RenderWindow* window;

};


#endif //LEMO_GAME_H
