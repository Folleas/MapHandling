/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Irrlicht
*/

#include "Irrlicht.hpp"

Irrlicht::Irrlicht(std::size_t windowSizeX, std::size_t windowSizeY)
{
    _device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(windowSizeX, windowSizeY), 32);
    _driver = _device->getVideoDriver();
    _sceneManager = _device->getSceneManager();
    _device->getCursorControl()->setVisible(true);
    _sceneManager->addCameraSceneNode(0, irr::core::vector3df(0,180,0), irr::core::vector3df(0,15,0));
}

Irrlicht::~Irrlicht()
{
    _device->drop();
}

bool Irrlicht::eventManager(void)
{

}

bool Irrlicht::isKeyPressed(void)
{

}

std::size_t Irrlicht::eventWhichKey(void)
{

}

bool Irrlicht::pollEvent()
{

}

void Irrlicht::startScene()
{
    _driver->beginScene(true, true, irr::video::SColor(0,255,255,255));
}

void Irrlicht::computeScene()
{
    _sceneManager->drawAll();
}

void Irrlicht::displayScene()
{
    _driver->endScene();
}

void Irrlicht::drawRect(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color)
{

}

