/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "GameObject.hpp"

class Button : public GameObject {
    public:
        Button();
        Button(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, RGBA_t clickedColor, std::string category, MenuScreens nextScreen);
        ~Button();

        std::pair<int, MenuScreens> engine(std::shared_ptr<int> window);
        int event(std::shared_ptr<Event> event);
        void display(std::shared_ptr<int> window);

        int launchCallBack(void);

        RGBA_t getColor(void) const;

        void setDisplay(bool display);
        void setClickedColor(std::size_t r, std::size_t g, std::size_t b, std::size_t a);
        void setColor(RGBA_t newColor);
        void setClickedColor(RGBA_t newColor);
        void setAlpha(std::size_t a);
        void setClickable(bool newValue);
        void setCategory(std::string newValue);

        std::shared_ptr<Button> setupButton(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, RGBA_t clickedColor, std::string category, MenuScreens nextScreen);
    private:
        std::pair<std::size_t, std::size_t> _mousePosition;

        // sf::Text _text;
        // sf::Font _font;

        bool _display;
        bool _clickable;
        std::size_t _pressed;
        int (*callback)();
        std::string _category;

        MenuScreens _nextMenu;
        RGBA_t _clickedColor;
};

#endif /* !BUTTON_HPP_ */