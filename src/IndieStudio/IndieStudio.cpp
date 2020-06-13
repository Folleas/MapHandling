/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IndieStudio
*/

#include "IndieStudio.hpp"

IndieStudio::IndieStudio()
{
    this->_graphics = std::make_shared<Irrlicht>(1920, 1080);
    // this->_graphics->initDisplay();
    this->_screenDimension = std::make_pair<std::size_t, std::size_t>(1920, 1080);
    this->_volume = 1;
    this->_soundFXVolume = 1;
}

IndieStudio::~IndieStudio()
{
}

void IndieStudio::runIndieStudio()
{
    std::shared_ptr<Player> p1 = std::make_shared<Player>();
    std::shared_ptr<Player> p2 = std::make_shared<Player>();
    std::shared_ptr<Player> p3 = std::make_shared<Player>();
    std::shared_ptr<Player> p4 = std::make_shared<Player>();
    std::vector<std::shared_ptr<Player>> players;
    MenuScreens nextMenu = MenuScreens::Game;
    bool isRunning = true;

    p1->setControler(irr::EKEY_CODE::KEY_KEY_Q, irr::EKEY_CODE::KEY_KEY_D, irr::EKEY_CODE::KEY_KEY_Z, irr::EKEY_CODE::KEY_KEY_S, irr::EKEY_CODE::KEY_KEY_F, irr::EKEY_CODE::KEY_KEY_G);
    // p2->setControler(irr::EKEY_CODE::KEY_KEY_Left, irr::EKEY_CODE::KEY_KEY_Right, irr::EKEY_CODE::KEY_KEY_Up, irr::EKEY_CODE::Down, irr::EKEY_CODE::RShift, irr::EKEY_CODE::Space);
    players.push_back(p1);
    // players.push_back(p2);
    p1->setPlayers(players);
    // p2->setPlayers(players);
    while (isRunning) {
        switch (nextMenu) {
            case MenuScreens::MainMenu :
                nextMenu = this->launchMainMenu();
                break;
            case MenuScreens::Game :
                nextMenu = this->launchGame(players);
                break;
            case MenuScreens::PlaySettings :
                nextMenu = this->launchPlaySettings();
                break;
            case MenuScreens::ControlSettings :
                nextMenu = this->launchControlSettings(players);
                break;
            case MenuScreens::Settings :
                nextMenu = this->launchSettings();
                break;
            case MenuScreens::Exit :
                exit (0);
        }
    }
}

MenuScreens IndieStudio::launchGame(std::vector<std::shared_ptr<Player>> players)
{
    for (std::shared_ptr<Player> player : players) {
        player->setScreenSize(this->_screenDimension);
    }
    GameCore gameCore(this->_graphics, players, 5, 5);
    return (gameCore.runGame());
}

MenuScreens IndieStudio::launchMainMenu()
{
    Menu menu(this->_graphics);
    std::vector<std::shared_ptr<GameObject>> _buttons;
    std::shared_ptr<Button> playButton = std::make_shared<Button>();
    std::shared_ptr<Button> settingsButton = std::make_shared<Button>();
    std::shared_ptr<Button> exitButton = std::make_shared<Button>();

    playButton = playButton->setupButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 7, this->_screenDimension.first / 16 * 6, this->_screenDimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Play", MenuScreens::PlaySettings);
    settingsButton = settingsButton->setupButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 10, this->_screenDimension.first / 16 * 6, this->_screenDimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Settings", MenuScreens::Settings);
    exitButton = exitButton->setupButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 13, this->_screenDimension.first / 16 * 6, this->_screenDimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Exit", MenuScreens::Exit);

    _buttons.push_back(playButton);
    _buttons.push_back(settingsButton);
    _buttons.push_back(exitButton);
    menu.setGameObjects(_buttons);
    return (menu.runMenu());
}

MenuScreens IndieStudio::launchPlaySettings()
{
    Menu menu(this->_graphics);
    std::vector<std::shared_ptr<GameObject>> _buttons;
    std::shared_ptr<ChoiceButton> playerNbButton = std::make_shared<ChoiceButton>();
    std::shared_ptr<ChoiceButton> botNbButton = std::make_shared<ChoiceButton>();
    std::shared_ptr<ChoiceButton> mapSizeButton = std::make_shared<ChoiceButton>();
    std::shared_ptr<Button> genButton = std::make_shared<Button>();
    std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>();

    playerNbButton = playerNbButton->setupChoiceButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 2, this->_screenDimension.first / 8 * 3, this->_screenDimension.second / 8, BUTTONCOLOR, CLICKEDBUTTONCOLOR, 0, 4, this->_nbPlayers);
    botNbButton = botNbButton->setupChoiceButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 6, this->_screenDimension.first / 8 * 3, this->_screenDimension.second / 8, BUTTONCOLOR, CLICKEDBUTTONCOLOR, 0, 4, this->_nbBots);
    mapSizeButton = botNbButton->setupChoiceButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 10, this->_screenDimension.first / 8 * 3, this->_screenDimension.second / 8, BUTTONCOLOR, CLICKEDBUTTONCOLOR, 1, 5, this->_mapSize);
    genButton = genButton->setupButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 13, this->_screenDimension.first / 8 * 3, this->_screenDimension.second / 8, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Generate Map", MenuScreens::Game);
    mainMenuButton = mainMenuButton->setupButton(0, this->_screenDimension.second / 24, this->_screenDimension.first / 8, this->_screenDimension.second / 16, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Back to main Menu", MenuScreens::MainMenu);

    _buttons.push_back(playerNbButton);
    _buttons.push_back(botNbButton);
    _buttons.push_back(mapSizeButton);
    _buttons.push_back(genButton);
    _buttons.push_back(mainMenuButton);

    menu.setGameObjects(_buttons);
    return (menu.runMenu());
}

MenuScreens IndieStudio::launchSettings()
{
    Menu menu(this->_graphics);
    std::vector<std::shared_ptr<GameObject>> _buttons;
    std::shared_ptr<ChoiceButton> volumeButton = std::make_shared<ChoiceButton>();
    std::shared_ptr<ChoiceButton> soundFXButton = std::make_shared<ChoiceButton>();
    std::shared_ptr<Button> controlButton = std::make_shared<Button>();
    std::shared_ptr<Button> mainMenuButton = std::make_shared<Button>();

    volumeButton = volumeButton->setupChoiceButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 8, this->_screenDimension.first / 16 * 6, this->_screenDimension.second / 16 * 3, BUTTONCOLOR, CLICKEDBUTTONCOLOR, 1, 10, this->_volume);
    soundFXButton = soundFXButton->setupChoiceButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 16 * 7, this->_screenDimension.first / 16 * 6, this->_screenDimension.second / 16 * 3, BUTTONCOLOR, CLICKEDBUTTONCOLOR, 1, 10, this->_soundFXVolume);
    controlButton = controlButton->setupButton(this->_screenDimension.first / 16 * 5, this->_screenDimension.second / 8 * 6, this->_screenDimension.first / 16 * 6, this->_screenDimension.second / 16 * 3, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Controls", MenuScreens::ControlSettings);
    mainMenuButton = mainMenuButton->setupButton(0, this->_screenDimension.second / 24, this->_screenDimension.first / 8, this->_screenDimension.second / 16, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Back to main Menu", MenuScreens::MainMenu);

    _buttons.push_back(volumeButton);
    _buttons.push_back(soundFXButton);
    _buttons.push_back(controlButton);
    _buttons.push_back(mainMenuButton);

    menu.setGameObjects(_buttons);
    return (menu.runMenu());
}

MenuScreens IndieStudio::launchControlSettings(std::vector<std::shared_ptr<Player>> players)
{
    Menu menu(this->_graphics);
    std::vector<std::shared_ptr<GameObject>> _buttons;
    std::shared_ptr<Button> settingsMenuButton = std::make_shared<Button>();
    std::shared_ptr<ControlSettingsButtons> controlSettingsButton = std::make_shared<ControlSettingsButtons>();

    settingsMenuButton = settingsMenuButton->setupButton(0, this->_screenDimension.second / 24, this->_screenDimension.first / 8, this->_screenDimension.second / 16, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "Back to settings", MenuScreens::Settings);
    controlSettingsButton = controlSettingsButton->setupControlSettingsButtons(this->_screenDimension.first / 8, this->_screenDimension.second / 4, this->_screenDimension.first - this->_screenDimension.first / 4, this->_screenDimension.second - this->_screenDimension.second / 4, CONTROLERBUTTONCOLOR, players);

    _buttons.push_back(settingsMenuButton);
    _buttons.push_back(controlSettingsButton);

    menu.setGameObjects(_buttons);
    return (menu.runMenu());
}