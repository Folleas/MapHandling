/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Event
*/

#include "Event.hpp"

Event::Event()
{
    for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

Event::~Event()
{
}

bool Event::OnEvent(const irr::SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    return false;
}

bool Event::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}
