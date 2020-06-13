/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ChoiceButton
*/

#include "ChoiceButton.hpp"

ChoiceButton::ChoiceButton(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, RGBA_t clickedColor, std::size_t statMinValue, std::size_t statMaxValue, std::size_t &modifiedStat)
{
    std::shared_ptr<Button> minusButton = std::make_shared<Button>();
    std::shared_ptr<Button> displayButton = std::make_shared<Button>();
    std::shared_ptr<Button> plusButton = std::make_shared<Button>();

    minusButton = minusButton->setupButton(position.first + dimension.first / 3 / 4, position.second + dimension.second / 4, dimension.first / 3 / 2, dimension.second / 2, color, clickedColor, "-", MenuScreens::UNDEFINED);
    displayButton = displayButton->setupButton(position.first + dimension.first / 3, position.second, dimension.first / 3, dimension.second, color, clickedColor, "0", MenuScreens::UNDEFINED);
    plusButton = plusButton->setupButton(position.first + (dimension.first / 3 * 2) + (dimension.first / 3 / 4), position.second + dimension.second / 4, dimension.first / 3 / 2, dimension.second / 2, color, clickedColor, "+", MenuScreens::UNDEFINED);
    displayButton->setClickable(false);
    this->_buttons.push_back(minusButton);
    this->_buttons.push_back(displayButton);
    this->_buttons.push_back(plusButton);
    this->_statMax = statMaxValue;
    this->_statMin = statMinValue;
    this->_actualStat = _statMax / 2;
    this->_modifiedStat = modifiedStat;
}

std::shared_ptr<ChoiceButton> ChoiceButton::setupChoiceButton(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, RGBA_t clickedColor, std::size_t statMinValue, std::size_t statMaxValue, std::size_t &modifiedStat)
{
    std::pair<std::size_t, std::size_t> buttonPosition;
    std::pair<std::size_t, std::size_t> buttonDimension;
    std::shared_ptr<ChoiceButton> tmpButton;

    buttonPosition.first = x;
    buttonPosition.second = y;
    buttonDimension.first = w;
    buttonDimension.second = h;
    tmpButton = std::make_shared<ChoiceButton>(buttonPosition, buttonDimension, color, clickedColor, statMinValue, statMaxValue, modifiedStat);
    return (tmpButton);
}

std::pair<int, MenuScreens> ChoiceButton::engine(std::shared_ptr<int> window)
{
    if (this->_buttons.at(0)->engine(window).first == 1 && this->_actualStat > 0) {
        this->_actualStat--;
    }
    if (this->_buttons.at(2)->engine(window).first == 1 && this->_actualStat < this->_statMax) {
        this->_actualStat++;
    }
    this->_modifiedStat = _actualStat;
    dynamic_cast<Button *>(this->_buttons.at(1).get())->setCategory(std::to_string(this->_actualStat));
    return (std::make_pair<int, MenuScreens>(_actualStat, MenuScreens::UNDEFINED));
}

void ChoiceButton::display(std::shared_ptr<int> window)
{
    for (std::shared_ptr<GameObject> elem : this->_buttons) {
        elem->display(window);
    }
}

int ChoiceButton::event(std::shared_ptr<Event> event)
{
    for (std::shared_ptr<GameObject> elem : this->_buttons) {
        elem->event(event);
    }
    return (0);
}