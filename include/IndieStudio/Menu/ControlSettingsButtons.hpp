/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ControlSettingsButtons
*/

#ifndef CONTROLSETTINGSBUTTONS_HPP_
#define CONTROLSETTINGSBUTTONS_HPP_

#include "GameObject.hpp"
#include "Player/Player.hpp"
#include "SingleCharacterTextInput.hpp"
#include "Button.hpp"

class ControlSettingsButtons : public GameObject {
    public:
        ControlSettingsButtons();
        ControlSettingsButtons(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, std::vector<std::shared_ptr<Player>> players);
        ~ControlSettingsButtons();

        std::pair<int, MenuScreens> engine(std::shared_ptr<int> window);
        int event(std::shared_ptr<Event> event);
        void display(std::shared_ptr<int> window);

        void checkAssignedInput(int selectedPlayer, int selectedTextInput);

        int getSelectedTextInput(std::pair<std::size_t, std::size_t> mousePosition);
        std::size_t getSelectedPlayer(std::shared_ptr<int> window);

        void setTextInputs(std::vector<irr::EKEY_CODE> controlerMap);
        std::vector<irr::EKEY_CODE> getModifiedInput();

        std::shared_ptr<ControlSettingsButtons> setupControlSettingsButtons(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, std::vector<std::shared_ptr<Player>> players);
    private:
        int _selectedTextInput;
        int _selectedPlayer;
        std::size_t _pressed;

        std::vector<std::shared_ptr<Player>> _players;
        std::vector<std::shared_ptr<GameObject>> _textInputs;
        std::vector<std::shared_ptr<GameObject>> _playerObjects;
        std::vector<std::shared_ptr<GameObject>> _displayObjects;
};

#endif /* !CONTROLSETTINGSBUTTONS_HPP_ */