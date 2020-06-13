/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "Map.hpp"

using namespace map;

Map::Map(float x, float y, std::size_t xFactor, std::size_t yFactor)
{
    // if (!_emptyTexture.loadFromFile("res/Textures/Empty.jpg") ||
    // !_softBlockTexture.loadFromFile("res/Textures/SoftBlock.jpg") ||
    // !_hardBlockTexture.loadFromFile("res/Textures/HardBlock.jpg") ||
    // !_softBlockPassTexture.loadFromFile("res/Textures/SoftBlockPass.png") ||
    // !_bombPassBlockTexture.loadFromFile("res/Textures/BombPass.png") ||
    // !_speedUpBlockTexture.loadFromFile("res/Textures/SpeedUp.png") ||
    // !_speedDownBlockTexture.loadFromFile("res/Textures/SpeedDown.png") ||
    // !_fireUpBlockTexture.loadFromFile("res/Textures/FireUp.png") ||
    // !_fireDownBlockTexture.loadFromFile("res/Textures/FireDown.png") ||
    // !_bombUpBlockTexture.loadFromFile("res/Textures/BombUp.png") ||
    // !_bombTexture.loadFromFile("res/Textures/Bomb.png")) {
    //     std::cerr << "Failed to load files" << std::endl;
    //     exit (84);
    // }
    // /*error handling*/
    // this->_emptySprite.setTexture(_emptyTexture);
    // this->_softBlockSprite.setTexture(_softBlockTexture);
    // this->_hardBlockSprite.setTexture(_hardBlockTexture);
    // this->_bombSprite.setTexture(_bombTexture);
    // this->_softBlockPassSprite.setTexture(_softBlockPassTexture);
    // this->_bombPassSprite.setTexture(_bombPassBlockTexture);
    // this->_speedUpBlockSprite.setTexture(_speedUpBlockTexture);
    // this->_speedDownBlockSprite.setTexture(_speedDownBlockTexture);
    // this->_fireUpBlockSprite.setTexture(_fireUpBlockTexture);
    // this->_fireDownSprite.setTexture(_fireDownBlockTexture);
    // this->_bombUpSprite.setTexture(_bombUpBlockTexture);

    // this->_emptySprite.setScale(3, 3);
    // this->_softBlockSprite.setScale(3, 3);
    // this->_hardBlockSprite.setScale(3, 3);
    // this->_bombSprite.setScale(3, 3);
    // this->_softBlockPassSprite.setScale(3, 3);
    // this->_bombPassSprite.setScale(3, 3);
    // this->_speedUpBlockSprite.setScale(3, 3);
    // this->_speedDownBlockSprite.setScale(3, 3);
    // this->_fireUpBlockSprite.setScale(3, 3);
    // this->_fireDownSprite.setScale(3, 3);
    // this->_bombUpSprite.setScale(3, 3);
    this->setPosition(x, y);
    this->generateRectMap(xFactor, yFactor);
    this->_sizeX = this->_size.first * 3;
}

Map::~Map()
{
}

void Map::searchSpawnPositions()
{
    std::size_t y = 0;
    std::size_t x = 0;

    for (std::size_t i = 0; i != this->_map.size(); i++) {
        if (this->_map.at(i) == 'S')
            this->_spawnPositions.push_back({this->_position.first + x * SPRITE_SIZE_X, this->_position.second + y * SPRITE_SIZE_Y});
        if (this->_map.at(i) == '\n') {
            y++;
            x = 0;
        }
        else {
            x++;
        }
    }
}

void Map::display(std::shared_ptr<int> window)
{
    // std::size_t y = 0;
    // std::size_t x = 0;
    // sf::Sprite spriteTemp;

    // for (std::size_t i = 0; i != this->_map.size(); i++) {
    //     switch (this->_map.at(i)) {
    //         case HARD_BLOCK :
    //             spriteTemp = this->_hardBlockSprite;
    //             break;
    //         case EMPTY_BLOCK :
    //             spriteTemp =  this->_emptySprite;
    //             break;
    //         case SPAWN_BLOCK :
    //             spriteTemp =  this->_emptySprite;
    //             break;
    //         case SOFT_BLOCK :
    //             spriteTemp = this->_softBlockSprite;
    //             break;
    //         case BOMB_BLOCK :
    //             spriteTemp = this->_bombSprite;
    //             break;
    //         case SOFT_BLOCK_PASS_BLOCK :
    //             spriteTemp = this->_softBlockPassSprite;
    //             break;
    //         case BOMB_PASS_BLOCK :
    //             spriteTemp = this->_bombPassSprite;
    //             break;
    //         case FIRE_UP_BLOCK :
    //             spriteTemp = this->_fireUpBlockSprite;
    //             break;
    //         case FIRE_DOWN_BLOCK :
    //             spriteTemp = this->_fireDownSprite;
    //             break;
    //         case SPEED_UP_BLOCK :
    //             spriteTemp = this->_speedUpBlockSprite;
    //             break;
    //         case SPEED_DOWN_BLOCK :
    //             spriteTemp = this->_speedDownBlockSprite;
    //             break;
    //         case BOMB_UP_BLOCK :
    //             spriteTemp = this->_bombUpSprite;
    //             break;
    //         case '\n' :
    //             y++;
    //             x = 0;
    //             continue;
    //     }
    //     spriteTemp.setPosition(this->_position.first + x++ * SPRITE_SIZE_X, this->_position.second + y * SPRITE_SIZE_Y);
    //     window->draw(spriteTemp);
    // }
}

int Map::event(std::shared_ptr<Event> event)
{
    return (0);
}

std::pair<int, MenuScreens> Map::engine(std::shared_ptr<int> window)
{
    // std::string str;
    // std::cin >> str;
    // if (str == "gen")
    //     this->generateRectMap(5, 5);
    return (std::make_pair<int, MenuScreens>(0, MenuScreens::UNDEFINED));
}

bool Map::checkMapCharAtPosition(std::string map, std::pair<std::size_t, std::size_t> playerMapPositions, bool wallPass, std::size_t sizeX)
{
    switch (map.at(((playerMapPositions.first) + playerMapPositions.second * sizeX) + playerMapPositions.second)) {
        case EMPTY_BLOCK :
            return (1);
        case SPAWN_BLOCK :
            return (1);
        case SOFT_BLOCK :
            if (wallPass)
                return (1);
            break;
    }
    return (0);
}

char Map::getMapCharAtPosition(std::pair<std::size_t, std::size_t> mapPositions)
{
    return (this->_map.at(((mapPositions.first) + mapPositions.second * _sizeX) + mapPositions.second));
}

void Map::changeMapCharAtPosition(char newStatus, std::pair<std::size_t, std::size_t> target)
{
    this->_map.at(((target.first) + target.second * _sizeX) + target.second) = newStatus;
}