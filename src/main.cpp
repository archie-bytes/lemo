#include "actors/hero/hero.h"
#include "system/game/game.h"

int main() {
    auto levels = std::array{
        Level(),
        Level(),
        Level()
    };

    auto game = Game(levels);
    game.run();

    return 0;
}
