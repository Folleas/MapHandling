/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <memory>
#include <iostream>
#include <string>

typedef struct RGBA_s {
    std::size_t r;
    std::size_t g;
    std::size_t b;
    std::size_t a;
}RGBA_t;

#define ITEM(x) case sf::Keyboard::x : ret = #x; break;
#define ITEM2(x) case #x; : ret = sf::Keyboard::x break;

class Sfml {
    public:
        Sfml();
        ~Sfml();

        void initDisplay(std::size_t windowSizeX, std::size_t windowSizeY);
        static std::string sfKeyToChar(sf::Keyboard::Key key);

        bool eventManager(void);
        bool isKeyPressed(void);
        std::size_t eventWhichKey(void);
        bool pollEvent();

        void displayWindow();
        void closeWindow();
        void clearWindow();

        void drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color);

        std::shared_ptr<sf::RenderWindow> getWindow() {return _window;};
        std::shared_ptr<sf::Event> getEvent() {return _event;};
    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<sf::Event> _event;
};

#endif /* !SFML_HPP_ */
