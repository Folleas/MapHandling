/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameObject
*/

#include "GameObject.hpp"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::setColor(RGBA_t newColor)
{
    this->_color.r = newColor.r;
    this->_color.g = newColor.g;
    this->_color.b = newColor.b;
    this->_color.a = newColor.a;
}

void GameObject::setPosition(float x, float y)
{
    this->_position.first = x;
    this->_position.second = y;
}