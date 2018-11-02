#include "Button.h"

#include <iostream>
#include <sstream>


namespace gui {

Button::Button(float width, float height)
{
    m_button.setOutlineThickness(1);
    m_button.setOutlineColor(sf::Color::Green);
    m_button.setFillColor(sf::Color::Black);
    m_button.setSize({ width, height });

    setPosition({ 500, 500 });
}

void Button::setFunction(std::function<void(void)> func)
{
    m_function = func;
}

void Button::setText(const std::string& str)
{
    m_text.setString(str);
    updateText();
}

void Button::setTexture(const sf::Texture& tex)
{
    m_button.setTexture(&tex);
}

void Button::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    auto pos = sf::Mouse::getPosition(window);

    switch (e.type) {
    case sf::Event::MouseButtonPressed:
        switch (e.mouseButton.button) {
        case sf::Mouse::Left:

            if (m_button.getGlobalBounds().contains((float)pos.x, (float)pos.y)) {

				switch (tempTest) {
				case 0:
                    m_button.setFillColor(sf::Color::Magenta);
                    break;
                case 1:
					m_button.setFillColor({0, 0, 0});
                    break;
                case 2:
                    m_button.setFillColor(sf::Color::Red);
                    break;
                }
                tempTest++;
                tempTest %= 3;
				std::stringstream ss;
				ss << "Click " << tempTest;
				setText(ss.str());

                m_function();
            }

        default:
            break;
        }

    default:
        break;
    }
}

void Button::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_button);
    renderer.draw(m_text);
}

void Button::setPosition(const sf::Vector2f& pos)
{
    m_position = pos;

    m_button.setPosition(m_position);
    m_text.setPosition(m_position);

    updateText();
}

void Button::updateText()
{
    m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);

    m_text.setPosition(m_button.getPosition().x +(m_button.getGlobalBounds().width / 2.0f), m_button.getPosition().y + m_button.getGlobalBounds().height / 2.5f);
}

sf::Vector2f Button::getSize() const
{
    return m_button.getSize();
}

}
