/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SingleCharacterTextInput
*/

#include "SingleCharacterTextInput.hpp"

SingleCharacterTextInput::SingleCharacterTextInput()
{
}

SingleCharacterTextInput::SingleCharacterTextInput(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, std::string str)
{
    this->_position.first = position.first;
    this->_position.second = position.second;
    this->_dimension.first = dimension.first;
    this->_dimension.second = dimension.second;
    this->_color = color;
    this->_string = str;
    // if (!(this->_font.loadFromFile("res/font/font.ttf"))) {
    //     std::cerr << "Couldn't open font" << std::endl;
    //     exit(84);
    // }
    // this->_text.setFont(this->_font);
    // this->_text.setString(this->_string);
}

SingleCharacterTextInput::~SingleCharacterTextInput()
{
}

void SingleCharacterTextInput::setString(std::string newString)
{
    this->_string = newString;
}

std::string SingleCharacterTextInput::getString() const
{
    return (this->_string);
}

std::pair<int, MenuScreens> SingleCharacterTextInput::engine(std::shared_ptr<int> window)
{
    return (std::make_pair<int, MenuScreens>(0, MenuScreens::UNDEFINED));
}

void SingleCharacterTextInput::display(std::shared_ptr<int> window)
{
    // sf::RectangleShape rect(sf::Vector2f(this->_dimension.first, this->_dimension.second));

    // rect.setFillColor(sf::Color(this->_color.r, this->_color.g, this->_color.b, this->_color.a));
    // rect.setPosition(sf::Vector2f(this->_position.first, this->_position.second));
    // this->_text.setPosition(sf::Vector2f(this->_position.first + this->_dimension.first / 2, this->_position.second + this->_dimension.second / 2));
    // this->_text.setString(this->_string);
    // window->draw(rect);
    // window->draw(this->_text);
}

int SingleCharacterTextInput::event(std::shared_ptr<Event> event)
{
    // if (event->type == sf::Event::KeyPressed) {
    //     std::string tmp;
    //     switch (event->key.code) {
    //         case sf::Keyboard::Key::Left :
    //             tmp.assign("Left");
    //             break;
    //         case sf::Keyboard::Key::Right :
    //             tmp.assign("Right");
    //             break;
    //         case sf::Keyboard::Key::Up :
    //             tmp.assign("Up");
    //             break;
    //         case sf::Keyboard::Key::Down :
    //             tmp.assign("Down");
    //             break;
    //         default :
    //             tmp.assign(Irrlicht::sfKeyToChar(event->key.code));
    //             break;
    //     }
    //     this->setString(tmp);
    //     this->setKey(event->key.code);
    //     return (1);
    // }
    return (0);
}

std::shared_ptr<SingleCharacterTextInput> SingleCharacterTextInput::setupSingleCharacterTextInput(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, std::string str)
{
    std::pair<std::size_t, std::size_t> buttonPosition;
    std::pair<std::size_t, std::size_t> buttonDimension;
    std::shared_ptr<SingleCharacterTextInput> tmpButton;

    buttonPosition.first = x;
    buttonPosition.second = y;
    buttonDimension.first = w;
    buttonDimension.second = h;
    tmpButton = std::make_shared<SingleCharacterTextInput>(buttonPosition, buttonDimension, color, str);
    return (tmpButton);
}

void SingleCharacterTextInput::setKey(irr::EKEY_CODE newKey)
{
    this->_key = newKey;
}


irr::EKEY_CODE SingleCharacterTextInput::getKey() const
{
    return (this->_key);
}
