/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(std::shared_ptr<Irrlicht> graphics)
{
    this->_graphics = graphics;
}

Menu::~Menu()
{
}

void Menu::setGameObjects(std::vector<std::shared_ptr<GameObject>> newValue)
{
    this->_gameObjects = newValue;
}

void Menu::manageEvent()
{
    // while (this->_graphics->pollEvent()) {
    //     this->_graphics->closeWindow();
    //     for (std::shared_ptr<GameObject> current : _gameObjects) {
    //         current->event(this->_graphics->getEvent());
    //     }
    // }
}

MenuScreens Menu::manageMenu()
{
    MenuScreens nextMenu = MenuScreens::UNDEFINED;

    for (std::shared_ptr<GameObject> current : _gameObjects) {
        // if ((nextMenu = (current->engine(this->_graphics->getWindow()).second)) != MenuScreens::UNDEFINED) {
        //     return (nextMenu);
        // }
    }
    return (nextMenu);
}

void Menu::manageDisplay()
{
    // this->_graphics->clearWindow();
    // for (std::shared_ptr<GameObject> current : _gameObjects) {
    //     current->display(this->_graphics->getWindow());
    // }
    // this->_graphics->displayWindow();
}

MenuScreens Menu::runMenu(void)
{
    MenuScreens nextMenu = MenuScreens::UNDEFINED;
    bool isRunning = true;

    while (isRunning) {
        this->manageEvent();
        if ((nextMenu = this->manageMenu()) != MenuScreens::UNDEFINED) {
            return (nextMenu);
        }
        this->manageDisplay();
    }
    return (nextMenu);
}