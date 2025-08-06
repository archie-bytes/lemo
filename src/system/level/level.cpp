//
// Created by Archie on 2025/8/6.
//

#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "level.h"


Level::Level() = default;

// 这个函数会在 window.draw(level) 时被调用
void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    auto size = sf::Vector2f(800, 50);
    auto ground = sf::RectangleShape(size);
    ground.setFillColor(sf::Color::Black);
    ground.setPosition(0, 600 - 50);

    target.draw(ground, states);  // 绘制成员图形
}
