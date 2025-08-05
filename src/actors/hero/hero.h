#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Hero : public sf::Drawable, public sf::Transformable  {
public:

    explicit Hero(const std::string &imagePath);

    void jump();

    void attack();

private:
    sf::Texture texture_;

    sf::Sprite sprite_;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif


