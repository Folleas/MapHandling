/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IndieStudio
*/

#ifndef INDIESTUDIO_HPP_
#define INDIESTUDIO_HPP_

#include "GameCore.hpp"
#include "Menu.hpp"
#include "Button.hpp"
#include "ChoiceButton.hpp"
#include "ControlSettingsButtons.hpp"

class IndieStudio {
    public:
        IndieStudio();
        ~IndieStudio();

        void runIndieStudio();

        MenuScreens launchGame(std::vector<std::shared_ptr<Player>> players);
        MenuScreens launchMainMenu();
        MenuScreens launchPlaySettings();
        MenuScreens launchSettings();
        MenuScreens launchControlSettings(std::vector<std::shared_ptr<Player>> players);

    private:
        std::size_t _nbPlayers;
        std::size_t _nbBots;
        std::size_t _volume;
        std::size_t _soundFXVolume;
        std::size_t _mapSize;
        std::pair<std::size_t, std::size_t> _screenDimension;
        std::shared_ptr<Irrlicht> _graphics;
};

#endif /* !INDIESTUDIO_HPP_ */