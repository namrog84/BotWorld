#pragma once
#include "SFML/Graphics.hpp"

class Entity 
{
public:

    virtual void update(sf::Time deltaTime) = 0;
    virtual void fixedUpdate(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderTarget& renderer) = 0;
};
