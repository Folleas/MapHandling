/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>

class Utils {
    public:
        Utils();
        ~Utils();

        static int doubleToSingleCoordinate(int x, int y, std::size_t sizeX, std::size_t sizeY);
    private:
};

#endif /* !UTILS_HPP_ */