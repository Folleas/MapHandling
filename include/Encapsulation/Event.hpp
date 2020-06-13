/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <irrlicht.h>

class Event : public irr::IEventReceiver {
    public:
        Event();
        ~Event();

        virtual bool OnEvent(const irr::SEvent& event);
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

    private:
        bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif /* !EVENT_HPP_ */
