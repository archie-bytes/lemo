#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Lemooo's Secret");
    window.setFramerateLimit(60);

    // 玩家小球
    sf::CircleShape player(25.f);
    player.setFillColor(sf::Color::Black);
    player.setPosition(50.f, windowHeight - 100.f);

    // 地面
    sf::RectangleShape ground(sf::Vector2f(windowWidth, 50));
    ground.setFillColor(sf::Color::Black);
    ground.setPosition(0, windowHeight - 50);

    // 移动速度
    const float moveSpeed = 10.f;

    bool gameWon = false;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 玩家移动逻辑
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-moveSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(moveSpeed, 0);
        }

        // 通关检测：小球右边到达窗口右边
        if (player.getPosition().x + player.getRadius() * 2 >= windowWidth) {
            std::cout << "你赢了！通关成功！" << std::endl;
            gameWon = true;
            window.close();
        }

        // 绘制部分
        window.clear(sf::Color::White);
        window.draw(ground);
        window.draw(player);
        window.display();
    }

    if (gameWon) {
        // 可选：显示通关窗口（也可用 SFML 实现）
        std::cout << "游戏结束，感谢游玩！" << std::endl;
    }

    return 0;
}
