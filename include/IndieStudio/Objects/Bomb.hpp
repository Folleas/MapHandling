/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "PlayerControler.hpp"
#include "GameObject.hpp"
#include "Utils.hpp"
#include "Map.hpp"

#include <array>

#define BOMB_DURATION 3
#define EXPOSION_DURATION 3

typedef std::chrono::_V2::system_clock::time_point TIME_POINT;

using namespace map;

class Player;

namespace IS {
    class Bomb : public GameObject {
        public:
            Bomb(std::shared_ptr<Map> map, std::pair<float, float> position, std::pair<std::size_t, std::size_t> mapPosition, std::size_t range);
            ~Bomb();

            void display(std::shared_ptr<int> window);
            int event(std::shared_ptr<Event> event);
            std::pair<int, MenuScreens> engine(std::shared_ptr<int> window);

            void checkInRange();
            void modifyBlock(std::pair<std::size_t, std::size_t> searchedCell);
            bool manageMap(std::pair<std::size_t, std::size_t> searchedCell);
            void managePlayer(std::shared_ptr<Player> player, std::pair<std::size_t, std::size_t> searchedCell);

            void setupDirections();

            bool isExploded();
            bool isActive();
            void setPlayer(std::vector<std::shared_ptr<Player>> players);
        private:
            std::size_t _duration;
            std::size_t _explosionDuration;
            std::size_t _range;
            std::size_t _sizeX;

            bool _penetrateWalls;
            bool _isExploded;
            bool _isActive;

            std::pair<std::size_t, std::size_t> _mapPosition;
            std::array<std::pair<int, int>, 4> _directions;
            std::vector<std::shared_ptr<Player>> _players;
            std::vector<std::pair<float, float>> _explosionPositions;

            std::shared_ptr<Map> _map;
            TIME_POINT _clock;

            // sf::Texture _explosionTexture;
            // sf::Sprite _explosionSprite;
    };
};

#endif /* !BOMB_HPP_ */