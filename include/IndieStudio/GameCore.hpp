/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameCore
*/

#ifndef GAMECORE_HPP_
#define GAMECORE_HPP_

#include "Player.hpp"
#include "Map.hpp"
#include "Menu.hpp"
#include "Button.hpp"
#include "ChoiceButton.hpp"
#include "ControlSettingsButtons.hpp"

class GameCore {
    public:
        GameCore(std::shared_ptr<Irrlicht> graphics, std::vector<std::shared_ptr<Player>> players, std::size_t xFactor, std::size_t yFactor);
        ~GameCore();

        MenuScreens runGame();
        void manageGame();
        void managePlayersActions();

        void manageEvent();
        void managePlayersEvent(std::shared_ptr<Event> event);

        void manageDisplay();

        void managePause();

    private:
        bool _isPaused;

        std::shared_ptr<map::Map> _map;
        std::shared_ptr<Irrlicht> _graphics;
        std::vector<std::shared_ptr<Player>> _players;

        std::vector<std::shared_ptr<GameObject>> _pauseObjects;
};

#endif /* !GAMECORE_HPP_ */