/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, RGBA_t clickedColor, std::string category, MenuScreens nextScreen)
{
    this->_position.first = position.first;
    this->_position.second = position.second;
    this->_dimension.first = dimension.first;
    this->_dimension.second = dimension.second;
    this->_color = color;
    this->_clickedColor = clickedColor;
    this->_clickable = true;
    this->_pressed = 0;
    this->_category = category;
    // if (!(this->_font.loadFromFile("res/font/font.ttf"))) {
    //     std::cerr << "Couldn't open font" << std::endl;
    //     exit(84);
    // }
    // this->_text.setFont(this->_font);
    // this->_text.setString(this->_category);
    this->_nextMenu = nextScreen;
    this->_display = true;
}


Button::Button()
{
}

Button::~Button()
{
}

void Button::setColor(RGBA_t newColor)
{
    this->_color.r = newColor.r;
    this->_color.g = newColor.g;
    this->_color.b = newColor.b;
    this->_color.a = newColor.a;
}

void Button::setClickedColor(std::size_t r, std::size_t g, std::size_t b, std::size_t a)
{
    this->_clickedColor.r = r;
    this->_clickedColor.g = g;
    this->_clickedColor.b = b;
    this->_clickedColor.a = a;
}

void Button::setClickedColor(RGBA_t newColor)
{
    this->_clickedColor.r = newColor.r;
    this->_clickedColor.g = newColor.g;
    this->_clickedColor.b = newColor.b;
    this->_clickedColor.a = newColor.a;
}

void Button::setAlpha(std::size_t a)
{
    this->_color.a = a;
}

RGBA_t Button::getColor() const
{
    return (_color);
}

std::pair<int, MenuScreens> Button::engine(std::shared_ptr<int> window)
{
    // if (_clickable) {
    //     sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    //     this->_mousePosition.first = mousePosition.x;
    //     this->_mousePosition.second = mousePosition.y;
    //     if (_mousePosition.first >= this->_position.first && _mousePosition.first <=  this->_position.first + this->_dimension.first && _mousePosition.second >= this->_position.second && _mousePosition.second <= this->_position.second + this->_dimension.second) {
    //         this->setColor((RGBA_t){78, 0, 22, 200});
    //         if (_pressed == 1) {
    //             this->setColor((RGBA_t){56, 5, 25, 255});
    //         }
    //         if (_pressed == 2) {
    //             _pressed = 0;
    //             return (std::make_pair<int, MenuScreens>(1, (MenuScreens)this->_nextMenu));
    //         }
    //         return (std::make_pair<int, MenuScreens>(-1, MenuScreens::UNDEFINED));
    //     }
    //     this->setColor((RGBA_t){78, 0, 22, 128});
    // }
    // this->_pressed = 0;
    return (std::make_pair<int, MenuScreens>(0, MenuScreens::UNDEFINED));
}

void Button::setDisplay(bool display)
{
    this->_display = display;
}

int Button::event(std::shared_ptr<Event> event)
{
    // switch (event->type) {
    //     case sf::Event::MouseButtonPressed :
    //         this->_pressed = 1;
    //         return (1);
    //     case sf::Event::MouseButtonReleased :
    //         this->_pressed = 2;
    //         return (1);
    // }
    return (0);
}

void Button::setCategory(std::string newValue)
{
    this->_category = newValue;
}

void Button::setClickable(bool newStatus)
{
    this->_clickable = newStatus;
}

std::shared_ptr<Button> Button::setupButton(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, RGBA_t clickedColor, std::string category, MenuScreens nextScreen)
{
    std::pair<std::size_t, std::size_t> buttonPosition;
    std::pair<std::size_t, std::size_t> buttonDimension;
    std::shared_ptr<Button> tmpButton;

    buttonPosition.first = x;
    buttonPosition.second = y;
    buttonDimension.first = w;
    buttonDimension.second = h;
    tmpButton = std::make_shared<Button>(buttonPosition, buttonDimension, color, clickedColor, category, nextScreen);
    return (tmpButton);
}

void Button::display(std::shared_ptr<int> window)
{
    // if (_display) {
    //     sf::RectangleShape rect(sf::Vector2f(this->_dimension.first, this->_dimension.second));

    //     rect.setFillColor(sf::Color(this->_color.r, this->_color.g, this->_color.b, this->_color.a));
    //     rect.setPosition(sf::Vector2f(this->_position.first, this->_position.second));
    //     this->_text.setPosition(sf::Vector2f(this->_position.first + this->_dimension.first / 2, this->_position.second + this->_dimension.second / 2));
    //     this->_text.setString(this->_category);
    //     window->draw(rect);
    //     window->draw(this->_text);
    // }
}

int Button::launchCallBack()
{
    return (this->callback());
}