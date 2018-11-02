#pragma once

#include <functional>

#include "Widget.h"

namespace gui {

class Button : public gui::Widget {
public:
    Button(float width = 128.f, float height = 64.f);

    void setFunction(std::function<void(void)> func);
    void setText(const std::string& str);
    void setTexture(const sf::Texture& tex);

    void handleEvent(sf::Event e, const sf::RenderWindow& window) override;
    void render(sf::RenderTarget& renderer) override;
    void setPosition(const sf::Vector2f& pos) override;
    sf::Vector2f getSize() const override;

    int tempTest = 0;
private:
    void updateText();

    sf::Vector2f m_position;

    Rectangle m_button;
    Text m_text;
    std::function<void(void)> m_function = []() {};

};

inline std::unique_ptr<Button> makeButton()
{
    return std::make_unique<Button>();
}
}