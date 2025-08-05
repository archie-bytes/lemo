#include <iostream>
#include "hero.h"

Hero::Hero(const std::string& imagePath) {

    if (!texture_.loadFromFile(imagePath)) {
        throw std::runtime_error("Failed to load texture from: " + imagePath);
    }

    sprite_.setTexture(texture_);


    auto texSize = texture_.getSize();

    auto scaleX = 50.f / static_cast<float>(texSize.x);
    auto scaleY = 50.f / static_cast<float>(texSize.y);

    this->setScale(scaleX, scaleY);
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // 将当前变换应用于渲染状态（如位置、旋转、缩放）
    states.transform *= getTransform();

    // 绘制 sprite
    target.draw(sprite_, states);
}

//void Hero::move(float offsetX, float offsetY) {
//    Transformable::move(offsetX, offsetY);
//}

void Hero::jump() {
    std::cout << "jumppppp" << std::endl;
}

void Hero::attack() {
    std::cout << "attack" << std::endl;
}




