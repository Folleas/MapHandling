/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <chrono>

#include "Irrlicht.hpp"
#include "Event.hpp"

typedef std::chrono::high_resolution_clock Clock;

#define BUTTONCOLOR (RGBA_t){78, 0, 22, 255}
#define CONTROLERBUTTONCOLOR (RGBA_t){78, 0, 22, 125}
#define CLICKEDBUTTONCOLOR (RGBA_t){56, 5, 25, 255}
#define BACKGROUNDCOLOR (RGBA_t){32, 9, 27, 255}

#define SPRITE_SIZE_X (16 * 3)
#define SPRITE_SIZE_Y (16 * 3)

#define NB_POWER_UPS 8
#define EMPTY_BLOCK_PROB 4

typedef enum MenuScreens {
    UNDEFINED = -1,
    MainMenu = 0,
    PlaySettings = 1,
    ControlSettings = 2,
    Settings = 3,
    Game = 4,
    Exit = 5
}MenuScreens;

typedef enum Axis {
    Vertical = 0,
    Horizontal = 1
}Axis;

class GameObject {
    public:
        GameObject();
        ~GameObject();

        virtual void display(std::shared_ptr<int> window) = 0;
        virtual int event(std::shared_ptr<Event> event) = 0;
        virtual std::pair<int, MenuScreens> engine(std::shared_ptr<int> window) = 0;

        void setColor(RGBA_t newColor);
        void setPosition(float x, float y);
        std::pair<float, float> getPosition() {return (_position);};
        std::pair<std::size_t, std::size_t> getDimension() {return (_dimension);};
    protected:
        std::pair<float, float> _position;
        std::pair<std::size_t, std::size_t> _dimension;

        RGBA_t _color;
};

#endif /* !GAMEOBJECT_HPP_ */