/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerInput
*/

#ifndef PLAYERINPUT_HPP_
#define PLAYERINPUT_HPP_

#include "Irrlicht.hpp"
#include "Event.hpp"

#include <vector>

typedef enum TextInputs {
    Left = 0,
    Right = 1,
    Up = 2,
    Down = 3,
    Bomb = 4,
    Pause = 5
} TextInputs;

class PlayerControler {
    public:
        PlayerControler(irr::EKEY_CODE leftKeyCode, irr::EKEY_CODE rightKeyCode, irr::EKEY_CODE upKeyCode, irr::EKEY_CODE downKeyCode, irr::EKEY_CODE bombKeyCode, irr::EKEY_CODE pauseKeyCode);
        ~PlayerControler();

        int getHorizontalDirection(std::shared_ptr<Event> event);
        int getVerticalDirection(std::shared_ptr<Event> event);
        bool isBombButtonPressed(std::shared_ptr<Event> event);
        bool isPauseButtonPressed(std::shared_ptr<Event> event);

        std::vector<irr::EKEY_CODE> getKeys();
        irr::EKEY_CODE getLastKeyPressed();
        irr::EKEY_CODE getLeftKeyCode();
        irr::EKEY_CODE getRightKeyCode();
        irr::EKEY_CODE getUpKeyCode();
        irr::EKEY_CODE getDownKeyCode();
        irr::EKEY_CODE getPauseKeyCode();
        irr::EKEY_CODE getBombKeyCode();
        void setKeys(std::vector<irr::EKEY_CODE> newKeys);
    protected:
        bool _leftKeyPressed;
        bool _rightKeyPressed;
        bool _upKeyPressed;
        bool _downKeyPressed;

        irr::EKEY_CODE _leftKeyCode;
        irr::EKEY_CODE _rightKeyCode;
        irr::EKEY_CODE _upKeyCode;
        irr::EKEY_CODE _downKeyCode;
        irr::EKEY_CODE _bombKeyCode;
        irr::EKEY_CODE _pauseKeyCode;

        irr::EKEY_CODE _lastKeyPressed;
};

#endif /* !PLAYERINPUT_HPP_ */