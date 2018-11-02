#pragma once

#include "Entity.h"
#include <memory>

class Bot : public Entity {
public:
    Bot();

    void update(sf::Time deltaTime) override;
    void fixedUpdate(sf::Time deltaTime) override;
    void render(sf::RenderTarget& renderer) override;

	float speed = 500.0f;
	std::shared_ptr<sf::CircleShape> shape;

};
