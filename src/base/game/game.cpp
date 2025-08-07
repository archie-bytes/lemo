#include "game.h"
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <utility>
#include "../../actors/hero/hero.h"


Game::Game(std::array<Level, 3> value) {
    this->levels = std::move(value);
    const int windowWidth = 800;
    const int windowHeight = 600;
    auto mode = sf::VideoMode(windowWidth, windowHeight);
    auto window_ = new sf::RenderWindow(mode, "Lemooo's Secret");
    window_->setFramerateLimit(60);
    this->window = window_;
}

void Game::run() {
    bool gameWon = false;
    auto hero = Hero("../assets/gopher.png");
    hero.setPosition(50.f, 600 - 100.f);

    float speedX = 0.0f;
    float velocityY = 0.0f;
    const float gravity = 0.5f;     // 每帧下落加速度
    const float jumpStrength = -12.0f; // 跳跃初速度（向上）

    bool isJumping = false;

    while (this->window->isOpen()) {
        // 确保窗口可以被正常关闭
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // 键盘监听
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (!isJumping) {
                hero.move(-10.f, 0);
                speedX = -5.f;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (!isJumping) {
                hero.move(10.f, 0);
                speedX = 5.f;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (!isJumping) {
                velocityY = jumpStrength;  // 给一个向上的速度
                isJumping = true;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            hero.attack();
        }

        // 重力机制
        velocityY += gravity;
        hero.move(speedX, velocityY);

        // 落地检测
        if (hero.getPosition().y >= 500) {
            hero.setPosition(hero.getPosition().x, 500);
            velocityY = 0;
            speedX = 0.0f;
            isJumping = false;
        }

        // 通关检测
        if (hero.getPosition().x >= 800) {
            std::cout << "你赢了！通关成功！" << std::endl;
            gameWon = true;
            window->close();
        }

        // 元素绘制
        window->clear(sf::Color::White);
        this->window->draw(hero);
        this->window->draw(this->levels.at(0));
        this->window->display();
    }

    if (gameWon) {
        // 可选：显示通关窗口（也可用 SFML 实现）
        std::cout << "游戏结束，感谢游玩！" << std::endl;
    }
}
