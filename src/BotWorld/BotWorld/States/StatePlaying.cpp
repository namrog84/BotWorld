#include "StatePlaying.h"

#include "../GUI/Button.h"
#include "../Game.h"
#include "../Game/Bot.h"

#include <memory.h>

std::string test;

std::shared_ptr<Bot> bot;

StatePlaying::StatePlaying(Game& game)
    : StateBase(game)
{
    m_buttonWidget = std::make_unique<gui::Button>(200.f, 100.f);
    m_buttonWidget->setText("Button 1");
    m_buttonWidget->setFunction([=]() {
		
    });

	bot = std::make_shared<Bot>();
	entities.push_back(bot);
}

void StatePlaying::handleEvent(sf::Event e)
{

    m_buttonWidget->handleEvent(e, m_pGame->getWindow());
}

void StatePlaying::handleInput()
{
}

void StatePlaying::update(sf::Time deltaTime)
{
    for (auto entity : entities) {
        entity->update(deltaTime);
    }
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{
    for (auto entity : entities) {
        entity->fixedUpdate(deltaTime);
    }
}

void StatePlaying::render(sf::RenderTarget& renderer)
{
	for (auto entity : entities) {
		entity->render(renderer);
	}

    m_buttonWidget->render(renderer);
}
