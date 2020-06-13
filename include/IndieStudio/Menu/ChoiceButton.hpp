/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ChoiceButton
*/

#ifndef CHOICEBUTTON_HPP_
#define CHOICEBUTTON_HPP_

#include "Button.hpp"

class ChoiceButton : public GameObject {
    public:
        ChoiceButton() = default;
        ChoiceButton(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, RGBA_t clickedColor, std::size_t statMinValue, std::size_t statMaxValue, std::size_t &modifiedStat);
        ~ChoiceButton() = default;

        std::pair<int, MenuScreens> engine(std::shared_ptr<int> window);
        int event(std::shared_ptr<Event> event);
        void display(std::shared_ptr<int> window);

        std::shared_ptr<ChoiceButton> setupChoiceButton(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, RGBA_t clickedColor, std::size_t statMinValue, std::size_t statMaxValue, std::size_t &modifiedStat);
    private:
        std::size_t _statMax;
        std::size_t _statMin;
        std::size_t _actualStat;
        std::size_t _modifiedStat;

        std::pair<std::size_t, std::size_t> _dimension;
        std::pair<std::size_t, std::size_t> _mousePosition;

        std::vector<std::shared_ptr<GameObject>> _buttons;
};

#endif /* !CHOICEBUTTON_HPP_ */
