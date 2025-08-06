//
// Created by Archie on 2025/8/6.
//

#ifndef LEMO_LEVEL_H
#define LEMO_LEVEL_H


class Level : public sf::Drawable {

public:

    Level();

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif
