/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Button.hpp"
#include "Irrlicht.hpp"

class Menu {
    public:
        Menu(std::shared_ptr<Irrlicht> graphic);
        ~Menu();

        void manageEvent(void);
        MenuScreens manageMenu(void);
        void manageDisplay(void);
        MenuScreens runMenu(void);

        void setGameObjects(std::vector<std::shared_ptr<GameObject>> newValue);
    private:
        bool leftClickReleased = false;
        bool leftClickPressed = false;
        bool _isRunning;

        std::vector<std::shared_ptr<GameObject>> _gameObjects;
        std::pair<std::size_t, std::size_t> _mousePosition;

        std::shared_ptr<Irrlicht> _graphics;
};

#endif /* !MENU_HPP_ */