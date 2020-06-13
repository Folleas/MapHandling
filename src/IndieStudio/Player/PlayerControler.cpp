/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerControler
*/

#include "PlayerControler.hpp"

PlayerControler::PlayerControler(irr::EKEY_CODE leftKeyCode, irr::EKEY_CODE rightKeyCode, irr::EKEY_CODE upKeyCode, irr::EKEY_CODE downKeyCode, irr::EKEY_CODE bombKeyCode, irr::EKEY_CODE pauseKeyCode)
{
    this->_leftKeyPressed = false;
    this->_rightKeyPressed = false;
    this->_upKeyPressed = false;
    this->_downKeyPressed = false;

    this->_bombKeyCode = bombKeyCode;
    this->_leftKeyCode = leftKeyCode;
    this->_rightKeyCode = rightKeyCode;
    this->_upKeyCode = upKeyCode;
    this->_downKeyCode = downKeyCode;
    this->_pauseKeyCode = pauseKeyCode;
}

PlayerControler::~PlayerControler()
{
}

irr::EKEY_CODE PlayerControler::getLeftKeyCode()
{
    return (this->_leftKeyCode);
}

irr::EKEY_CODE PlayerControler::getRightKeyCode()
{
    return (this->_rightKeyCode);
}

irr::EKEY_CODE PlayerControler::getUpKeyCode()
{
    return (this->_upKeyCode);
}

irr::EKEY_CODE PlayerControler::getDownKeyCode()
{
    return (this->_downKeyCode);
}

irr::EKEY_CODE PlayerControler::getPauseKeyCode()
{
    return (this->_pauseKeyCode);
}

irr::EKEY_CODE PlayerControler::getBombKeyCode()
{
    return (this->_bombKeyCode);
}


irr::EKEY_CODE PlayerControler::getLastKeyPressed()
{
    return (this->_lastKeyPressed);
}

int PlayerControler::getHorizontalDirection(std::shared_ptr<Event> event)
{
    if (event->IsKeyDown(this->_leftKeyCode)) {
        _rightKeyPressed = true;
        return (1);
    }
    else if (event->IsKeyDown(this->_rightKeyCode)) {
        _rightKeyPressed = true;
        return (-1);
    }
    return (0);
}

int PlayerControler::getVerticalDirection(std::shared_ptr<Event> event)
{
    if (event->IsKeyDown(this->_downKeyCode)) {
        _downKeyPressed = true;
        return (1);
    }
    else if (event->IsKeyDown(this->_upKeyCode)) {
        _upKeyPressed = true;
        return (-1);
    }
    return (0);
}

bool PlayerControler::isBombButtonPressed(std::shared_ptr<Event> event)
{
    if (event->IsKeyDown(this->_bombKeyCode))
        return (true);
    return (false);
}

bool PlayerControler::isPauseButtonPressed(std::shared_ptr<Event> event)
{
    if (event->IsKeyDown(this->_pauseKeyCode))
        return (true);
    return (false);
}

std::vector<irr::EKEY_CODE> PlayerControler::getKeys()
{
    std::vector<irr::EKEY_CODE> keys;

    keys.push_back(_leftKeyCode);
    keys.push_back(_rightKeyCode);
    keys.push_back(_upKeyCode);
    keys.push_back(_downKeyCode);
    keys.push_back(_bombKeyCode);
    keys.push_back(_pauseKeyCode);
    return (keys);
}

void PlayerControler::setKeys(std::vector<irr::EKEY_CODE> newKeys)
{
    this->_leftKeyCode = newKeys.at(TextInputs::Left);
    this->_rightKeyCode = newKeys.at(TextInputs::Right);
    this->_upKeyCode = newKeys.at(TextInputs::Up);
    this->_downKeyCode = newKeys.at(TextInputs::Down);
    this->_bombKeyCode = newKeys.at(TextInputs::Bomb);
    this->_pauseKeyCode = newKeys.at(TextInputs::Pause);
}