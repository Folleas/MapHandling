/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "MapGeneration.hpp"
#include "GameObject.hpp"

#define BLOCK_PER_PARCEL 3

namespace map {
    typedef enum BlockType {
        HARD_BLOCK = '0',
        EMPTY_BLOCK = '1',
        SOFT_BLOCK = '2',
        SPAWN_BLOCK = 'S',
        BOMB_BLOCK = 'B',
        SOFT_BLOCK_PASS_BLOCK = 'w',
        BOMB_PASS_BLOCK = 'b',
        SPEED_UP_BLOCK = 'u',
        SPEED_DOWN_BLOCK = 'd',
        FIRE_UP_BLOCK = 'F',
        FIRE_DOWN_BLOCK = 'f',
        BOMB_UP_BLOCK = 'U',
        BOM_DOWN_BLOCK = 'D',
    }BlockType;

    class Map : public GameObject, public MapGeneration {
        public:
            Map(float x, float y, std::size_t xFactor, std::size_t yFactor);
            ~Map();

            void display(std::shared_ptr<int> window);
            int event(std::shared_ptr<Event> event);
            std::pair<int, MenuScreens> engine(std::shared_ptr<int> window);

            void searchSpawnPositions();

            static bool checkMapCharAtPosition(std::string map, std::pair<std::size_t, std::size_t> playerMapPositions, bool wallPass, std::size_t sizeX);
            char getMapCharAtPosition(std::pair<std::size_t, std::size_t> mapPositions);
            void changeMapCharAtPosition(char newStatus, std::pair<std::size_t, std::size_t> target);
        private:
            std::size_t _sizeX;

            // sf::Texture _emptyTexture;
            // sf::Texture _softBlockTexture;
            // sf::Texture _hardBlockTexture;
            // sf::Texture _bombTexture;
            // sf::Texture _softBlockPassTexture;
            // sf::Texture _bombPassBlockTexture;
            // sf::Texture _speedUpBlockTexture;
            // sf::Texture _speedDownBlockTexture;
            // sf::Texture _fireUpBlockTexture;
            // sf::Texture _fireDownBlockTexture;
            // sf::Texture _bombUpBlockTexture;

            // sf::Sprite _emptySprite;
            // sf::Sprite _hardBlockSprite;
            // sf::Sprite _softBlockSprite;
            // sf::Sprite _bombSprite;
            // sf::Sprite _softBlockPassSprite;
            // sf::Sprite _bombPassSprite;
            // sf::Sprite _speedUpBlockSprite;
            // sf::Sprite _speedDownBlockSprite;
            // sf::Sprite _fireUpBlockSprite;
            // sf::Sprite _fireDownSprite;
            // sf::Sprite _bombUpSprite;
    };
};

#endif /* !MAP_HPP_ */