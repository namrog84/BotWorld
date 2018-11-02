#pragma once

#include "../GUI/Button.h"
#include "../Game/Entity.h"
#include "StateBase.h"

#include <memory>
#include <vector>


/**
Game state for the main part of the game
*/
class StatePlaying : public StateBase {
public:
    StatePlaying(Game& game);

    void handleEvent(sf::Event e) override;
    void handleInput() override;
    void update(sf::Time deltaTime) override;
    void fixedUpdate(sf::Time deltaTime) override;
    void render(sf::RenderTarget& renderer) override;

	std::vector<std::shared_ptr<Entity>> entities;
public:
    // todo make into a menu/gui or array?
    std::unique_ptr<gui::Button> m_buttonWidget;
};
