/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SingleCharacterTextInput
*/

#ifndef TEXTINPUT_HPP_
#define TEXTINPUT_HPP_

#include "GameObject.hpp"

class SingleCharacterTextInput : public GameObject {
    public:
        SingleCharacterTextInput();
        SingleCharacterTextInput(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, std::string str);
        ~SingleCharacterTextInput();

        std::pair<int, MenuScreens> engine(std::shared_ptr<int> window);
        int event(std::shared_ptr<Event> event);
        void display(std::shared_ptr<int> window);

        void setString(std::string newString);
        void setKey(irr::EKEY_CODE newKey);

        irr::EKEY_CODE getKey() const;
        std::string getString() const;

        std::shared_ptr<SingleCharacterTextInput> setupSingleCharacterTextInput(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, std::string str);
    private:
        std::string _string;
        irr::EKEY_CODE _key;

        // sf::Text _text;
        // sf::Font _font;
};

#endif /* !TEXTINPUT_HPP_ */