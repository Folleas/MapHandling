/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Irrlicht
*/

#ifndef IRRLICHT_HPP_
#define IRRLICHT_HPP_

#include <irrlicht.h>

#include <memory>
#include <iostream>
#include <string>

typedef struct RGBA_s {
    std::size_t r;
    std::size_t g;
    std::size_t b;
    std::size_t a;
}RGBA_t;

class Irrlicht {
    public:
        Irrlicht(std::size_t windowSizeX, std::size_t windowSizeY);
        ~Irrlicht();

        bool eventManager(void);
        bool isKeyPressed(void);
        std::size_t eventWhichKey(void);
        bool pollEvent();

        void startScene();
        void computeScene();
        void displayScene();

        void drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color);

        // std::shared_ptr<> getWindow() {return _window;};
        // std::shared_ptr<> getEvent() {return _event;};
    private:
        irr::IrrlichtDevice* _device;
        irr::video::IVideoDriver* _driver;
        irr::scene::ISceneManager* _sceneManager;
        // std::shared_ptr<> _event;
};

#endif /* !IRRLICHT_HPP_ */