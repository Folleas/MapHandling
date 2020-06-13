/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sfml
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
    this->_event = std::make_shared<sf::Event>();
}

Sfml::~Sfml()
{
}

bool Sfml::pollEvent()
{
    return (_window->pollEvent(*_event));
}

void Sfml::closeWindow(void)
{
    if (_event->type == sf::Event::Closed)
        _window->close();
}

void Sfml::drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color)
{
    sf::RectangleShape rect(sf::Vector2f(dimension.first, dimension.second));
    rect.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
    rect.setPosition(sf::Vector2f(position.first, position.second));
    _window->draw(rect);
}

void Sfml::clearWindow(void)
{
    _window->clear(sf::Color(32, 9, 27, 255));
}

void Sfml::displayWindow(void)
{
    _window->display();
}

void Sfml::initDisplay(std::size_t windowSizeX, std::size_t windowSizeY)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowSizeX, windowSizeY), "Bomberman");
    _window->setVerticalSyncEnabled(true);
    _window->setFramerateLimit(60);
}

std::string Sfml::sfKeyToChar(sf::Keyboard::Key key)
{
    std::string ret;

    switch (key) {
        ITEM(A)
        ITEM(B)
        ITEM(C)
        ITEM(D)
        ITEM(E)
        ITEM(F)
        ITEM(G)
        ITEM(H)
        ITEM(I)
        ITEM(J)
        ITEM(K)
        ITEM(L)
        ITEM(M)
        ITEM(N)
        ITEM(O)
        ITEM(P)
        ITEM(Q)
        ITEM(R)
        ITEM(S)
        ITEM(T)
        ITEM(U)
        ITEM(V)
        ITEM(W)
        ITEM(X)
        ITEM(Y)
        ITEM(Z)
        ITEM(Escape)
        ITEM(LShift)
        ITEM(LAlt)
        ITEM(LControl)
        ITEM(LSystem)
        ITEM(RControl)
        ITEM(RShift)
        ITEM(RAlt)
        ITEM(RSystem)
        ITEM(Menu)
        ITEM(Space)
        ITEM(Return)
        ITEM(BackSpace)
        ITEM(Tab)
        ITEM(PageUp)
        ITEM(PageDown)
        ITEM(End)
        ITEM(Home)
        ITEM(Insert)
        ITEM(Delete)
        ITEM(Add)
        ITEM(Subtract)
        ITEM(Multiply)
        ITEM(Divide)
        ITEM(Left)
        ITEM(Right)
        ITEM(Up)
        ITEM(Down)
        ITEM(Numpad0)
        ITEM(Numpad1)
        ITEM(Numpad2)
        ITEM(Numpad3)
        ITEM(Numpad4)
        ITEM(Numpad5)
        ITEM(Numpad6)
        ITEM(Numpad7)
        ITEM(Numpad8)
        ITEM(Numpad9)
        ITEM(Pause)
        ITEM(Unknown)
    }
    return (ret);
}