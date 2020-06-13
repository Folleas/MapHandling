/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PlayerStat
*/

#include "Player.hpp"

PlayerStat::PlayerStat()
{
}

PlayerStat::~PlayerStat()
{
}

void PlayerStat::setHealthPoint(std::size_t newValue)
{
    this->_healthPoint = newValue;
}

void PlayerStat::setMaxHealthPoint(std::size_t newValue)
{
    this->_maxHealthPoint = newValue;
}

void PlayerStat::setTotalBombSimultaneously(std::size_t newValue)
{
    this->_totalBombSimultaneously = newValue;
}

void PlayerStat::setSpeed(std::size_t newValue)
{
    this->_speed = newValue;
}

void PlayerStat::setSpeedFactor(std::size_t newValue)
{
    this->_speedFactor = newValue;
}

void PlayerStat::setBombFirePower(std::size_t newValue)
{
    this->_bombFirePower = newValue;
}

void PlayerStat::setWallPass(bool newValue)
{
    this->_wallPass = newValue;
}


std::size_t PlayerStat::getMaxHealthPoint(void)
{
    return (this->_maxHealthPoint);
}

std::size_t PlayerStat::getHealthPoint(void)
{
    return (this->_healthPoint);
}

std::size_t PlayerStat::getTotalBombSimultaneously(void)
{
    return (this->_totalBombSimultaneously);
}

std::size_t PlayerStat::getSpeed(void)
{
    return (this->_speed);
}

std::size_t PlayerStat::getSpeedFactor(void)
{
    return (this->_speedFactor);
}

std::size_t PlayerStat::getBombFirePower(void)
{
    return (this->_bombFirePower);
}

bool PlayerStat::getWallPass(void)
{
    return (this->_wallPass);
}
