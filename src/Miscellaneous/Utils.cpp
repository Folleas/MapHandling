/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Utils
*/

#include "Utils.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{
}

int Utils::doubleToSingleCoordinate(int x, int y, std::size_t sizeX, std::size_t sizeY)
{
    if (x < 0 || y < 0 || x >= sizeX || y >= sizeY) {
        return (-1);
    }
    return (x + y * sizeX);
}