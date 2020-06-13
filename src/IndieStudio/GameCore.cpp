/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameCore
*/

#include "GameCore.hpp"

GameCore::GameCore(std::shared_ptr<Irrlicht> graphics, std::vector<std::shared_ptr<Player>> players, std::size_t xFactor, std::size_t yFactor)
{
    std::vector<std::shared_ptr<GameObject>> _buttons;
    std::shared_ptr<Button> settingsMenuButton = std::make_shared<Button>();
    std::shared_ptr<Button> backToGameButton = std::make_shared<Button>();
    std::size_t count = 0;

    this->_isPaused = false;
    this->_map = std::make_shared<map::Map>(0, 0, xFactor, yFactor);
    this->_map->searchSpawnPositions();
    for (std::shared_ptr<Player> player : players) {
        player->setMap(this->_map);
        player->setPosition(this->_map->getSpawnPositions().at(count++));
        player->move();
    }
    this->_graphics = graphics;
    this->_players = players;

    settingsMenuButton = settingsMenuButton->setupButton(0, 1080 / 24, 1920 / 8, 1080 / 16, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Settings", MenuScreens::Settings);
    backToGameButton = backToGameButton->setupButton(0, (1080 / 24) * 4, 1920 / 8, 1080 / 16, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Back To Game", MenuScreens::Game);
    _buttons.push_back(settingsMenuButton);
    _buttons.push_back(backToGameButton);
    this->_pauseObjects = _buttons;
}

GameCore::~GameCore()
{
}

void GameCore::managePlayersEvent(std::shared_ptr<Event> event)
{
    bool isPausedTemp = false;

    for (std::shared_ptr<Player> currentPlayer : this->_players) {
        isPausedTemp = currentPlayer->event(event);
        if (isPausedTemp)
            this->_isPaused = isPausedTemp;
    }
}

void GameCore::manageEvent()
{
    while (this->_graphics->pollEvent()) {
        // this->_graphics->closeWindow();
        // this->managePlayersEvent(this->_graphics->getEvent());
        // this->_map->event(this->_graphics->getEvent());
    }
}

void GameCore::managePlayersActions()
{
    for (std::shared_ptr<Player> currentPlayer : this->_players) {
        // currentPlayer->engine(this->_graphics->getWindow());
    }
}

void GameCore::manageGame()
{
    this->managePlayersActions();
    // this->_map->engine(this->_graphics->getWindow());
}

void GameCore::manageDisplay()
{
    this->_graphics->startScene();
    this->_graphics->computeScene();
    this->_graphics->displayScene();
    // this->_graphics->clearWindow();
    // this->_map->display(this->_graphics->getWindow());
    for (std::shared_ptr<Player> player : this->_players) {
        // player->display(this->_graphics->getWindow());
    }
    // this->_graphics->displayWindow();
}

MenuScreens GameCore::runGame()
{
    MenuScreens mainMenu = MenuScreens::UNDEFINED;
    bool isRunning = true;

    while (isRunning) {
        this->manageEvent();
        if (!this->_isPaused) {
            this->manageGame();
            this->manageDisplay();
        }
        else {
            this->managePause();
        }
    }
    return (mainMenu);
}

void GameCore::managePause()
{
    MenuScreens nextMenu = MenuScreens::UNDEFINED;

    for (std::shared_ptr<GameObject> object : this->_pauseObjects) {
        // object->event(this->_graphics->getEvent());
        // if (object->engine(this->_graphics->getWindow()).second == MenuScreens::Game) {
        //     _isPaused = false;
        //     return;
        // }
        // this->_graphics->clearWindow();
        // object->display(this->_graphics->getWindow());
        // this->_graphics->displayWindow();
    }
}