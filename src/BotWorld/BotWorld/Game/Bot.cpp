#pragma once

#include "Bot.h"

Bot::Bot()
{
    shape = std::make_shared<sf::CircleShape>(100.0f);
    shape->setFillColor(sf::Color::Red);
}

void Bot::update(sf::Time deltaTime)
{
    auto deltaSeconds = deltaTime.asSeconds();
    sf::Vector2f deltaMove;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        deltaMove.x = -speed * deltaSeconds;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        deltaMove.x = speed * deltaSeconds;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        deltaMove.y = -speed * deltaSeconds;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        deltaMove.y = speed * deltaSeconds;
    }
    shape->move(deltaMove);

}

void Bot::fixedUpdate(sf::Time deltaTime)
{

}

void Bot::render(sf::RenderTarget& renderer)
{
	
	renderer.draw(*shape);
}
