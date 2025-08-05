#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "actors/hero/hero.h"

int main() {
    // 窗口
    const int windowWidth = 800;
    const int windowHeight = 600;
    auto mode = sf::VideoMode(windowWidth, windowHeight);
    auto window = sf::RenderWindow(mode, "Lemooo's Secret");
    window.setFramerateLimit(60);

    // 玩家
    auto hero = Hero("../assets/gopher.png");
    hero.setPosition(50.f, windowHeight - 100.f);

    // 地面
    auto size = sf::Vector2f(windowWidth, 50);
    auto ground = sf::RectangleShape(size);
    ground.setFillColor(sf::Color::Black);
    ground.setPosition(0, windowHeight - 50);

    bool gameWon = false;

    while (window.isOpen()) {
        // 确保窗口可以被正常关闭
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 键盘监听
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            hero.move(-10.f, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            hero.move(10.f, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            hero.jump();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            hero.attack();
        }

        // 通关检测
        if (hero.getPosition().x >= windowWidth) {
            std::cout << "你赢了！通关成功！" << std::endl;
            gameWon = true;
            window.close();
        }

        // 元素绘制
        window.clear(sf::Color::White);
        window.draw(ground);
        window.draw(hero);
        window.display();
    }

    if (gameWon) {
        // 可选：显示通关窗口（也可用 SFML 实现）
        std::cout << "游戏结束，感谢游玩！" << std::endl;
    }

    return 0;
}

