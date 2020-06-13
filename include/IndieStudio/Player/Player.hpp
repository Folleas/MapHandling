/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <memory>

#include "PlayerControler.hpp"
#include "GameObject.hpp"
#include "Utils.hpp"
#include "Map.hpp"
#include "Bomb.hpp"

#define SPRITE_OFFSET_X (16 * 3)
#define SPRITE_OFFSET_Y (12 * 3)

class PlayerStat {
    public:
        PlayerStat();
        ~PlayerStat();

        void setHealthPoint(std::size_t newValue);
        void setMaxHealthPoint(std::size_t newValue);
        void setTotalBombSimultaneously(std::size_t newValue);
        void setSpeed(std::size_t newValue);
        void setSpeedFactor(std::size_t newValue);
        void setBombFirePower(std::size_t newValue);
        void setWallPass(bool newValue);

        std::size_t getMaxHealthPoint(void);
        std::size_t getHealthPoint(void);
        std::size_t getTotalBombSimultaneously(void);
        std::size_t getSpeed(void);
        std::size_t getSpeedFactor(void);
        std::size_t getBombFirePower(void);
        bool getWallPass(void);
    protected:
        std::size_t _maxHealthPoint;
        std::size_t _healthPoint;
        std::size_t _totalBombSimultaneously;
        std::size_t _speedFactor;
        std::size_t _speed;
        std::size_t _bombFirePower;
        bool _wallPass;
        bool _bombPass;
};

class Player : public GameObject, PlayerStat {
    public:
        Player(std::size_t maxHealth = 1, std::size_t totalBombSimultaneously = 1, std::size_t speed = 1, std::size_t speedFactor = 1, std::size_t bombFirePower = 1, bool wallPass = false);
        ~Player();

        void setControler(irr::EKEY_CODE leftKeyCode, irr::EKEY_CODE rightKeyCode, irr::EKEY_CODE upKeyCode, irr::EKEY_CODE downKeyCode, irr::EKEY_CODE bombKeyCode, irr::EKEY_CODE pauseKeyCode);
        void setControler(std::vector<irr::EKEY_CODE> newKeys);

        void move();
        void manageAxis(int direction, float &position, std::size_t &mapPosition, std::size_t sizeX, Axis axis);
        void manageBomb();
        void managePowerUps();
        void pauseGame();
        void death();

        void display(std::shared_ptr<int> graphics);
        int event(std::shared_ptr<Event> event);
        std::pair<int, MenuScreens> engine(std::shared_ptr<int> window);

        void updateInputStatus(std::shared_ptr<Event> event);

        void setScreenSize(std::pair<std::size_t, std::size_t> screenSize);
        void setMapSize(std::pair<std::size_t, std::size_t> mapSize);
        void setMap(std::shared_ptr<map::Map> map);
        void setPosition(std::pair<float, float> newValues);
        void setPlayers(std::vector<std::shared_ptr<Player>> players);

        std::shared_ptr<PlayerControler> getControler() const;
        std::pair<float, float> getPosition(void);
        std::pair<std::size_t, std::size_t> getMapPosition() const;
    private:
        bool _bombButtonPressed;
        bool _pauseButtonPressed;
        bool _isDead;
        bool _pause;

        std::shared_ptr<map::Map> _map;
        std::pair<std::size_t, std::size_t> _screenSize;

        std::pair<std::size_t, std::size_t> _mapPosition;
        std::pair<int, int> _directions;

        std::vector<std::shared_ptr<Player>> _players;
        std::vector<std::shared_ptr<IS::Bomb>> _layedBombs;
        std::shared_ptr<PlayerControler> _controler;

        // sf::Texture _texture;
        // sf::Sprite _sprite;
};

#endif /* !PLAYER_HPP_ */