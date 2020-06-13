/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "Player.hpp"

using namespace IS;

Bomb::Bomb(std::shared_ptr<Map> map, std::pair<float, float> position, std::pair<std::size_t, std::size_t> mapPosition, std::size_t range)
{
    this->_range = range;
    this->_duration = BOMB_DURATION;
    this->_explosionDuration = EXPOSION_DURATION;
    this->_penetrateWalls = false;
    this->_map = map;
    this->_position = position;
    this->_mapPosition = mapPosition;
    this->_map->changeMapCharAtPosition(BlockType::BOMB_BLOCK, this->_mapPosition);
    this->_sizeX = map->getSize().first;
    this->setupDirections();
    this->_clock = Clock::now();
    this->_isExploded = false;
    this->_isActive = true;
    // if (!this->_explosionTexture.loadFromFile("res/Textures/Bomb.png")) {
    //     std::cerr << "Failed to load files" << std::endl;
    //     exit (84);
    // }
    // /*error handling*/
    // this->_explosionSprite.setTexture(_explosionTexture);
    // this->_explosionSprite.setScale(3, 3);
    srand((unsigned)time(NULL));
}

Bomb::~Bomb()
{

}

void Bomb::setupDirections()
{
    std::pair<int, int> left = std::make_pair<int, int>(-1, 0);
    std::pair<int, int> right = std::make_pair<int, int>(1, 0);
    std::pair<int, int> up = std::make_pair<int, int>(0, -1);
    std::pair<int, int> down = std::make_pair<int, int>(0, 1);

    std::array<std::pair<int, int>, 4> directions{left, right, up, down};
    this->_directions = directions;
}

void Bomb::display(std::shared_ptr<int> window)
{
    if (this->_isExploded) {
        for (std::pair<float, float> explosionPosition : this->_explosionPositions) {
            // this->_explosionSprite.setPosition(explosionPosition.first + SPRITE_SIZE_X, explosionPosition.second + SPRITE_SIZE_Y);
            // window->draw(this->_explosionSprite);
        }
    }
}

int Bomb::event(std::shared_ptr<Event> event)
{
    return (0);
}

void Bomb::modifyBlock(std::pair<std::size_t, std::size_t> searchedCell)
{
    std::size_t rand = std::rand() % (NB_POWER_UPS + EMPTY_BLOCK_PROB);
    // this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, searchedCell);

    switch (rand) {
        case 0 :
            this->_map->changeMapCharAtPosition(BlockType::SOFT_BLOCK_PASS_BLOCK, searchedCell);
            break;
        case 1 :
            this->_map->changeMapCharAtPosition(BlockType::BOMB_PASS_BLOCK, searchedCell);
            break;
        case 2 :
            this->_map->changeMapCharAtPosition(BlockType::SPEED_UP_BLOCK, searchedCell);
            break;
        case 3 :
            this->_map->changeMapCharAtPosition(BlockType::SPEED_DOWN_BLOCK, searchedCell);
            break;
        case 4 :
            this->_map->changeMapCharAtPosition(BlockType::FIRE_UP_BLOCK, searchedCell);
            break;
        case 5 :
            this->_map->changeMapCharAtPosition(BlockType::FIRE_DOWN_BLOCK, searchedCell);
            break;
        case 6 :
            this->_map->changeMapCharAtPosition(BlockType::BOMB_UP_BLOCK, searchedCell);
            break;
        default :
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, searchedCell);
    }
}

bool Bomb::manageMap(std::pair<std::size_t, std::size_t> searchedCell)
{
    switch (this->_map->getMapCharAtPosition(searchedCell)) {
        case '\n' :
            break;
        case BlockType::EMPTY_BLOCK :
            this->_explosionPositions.push_back(searchedCell);
            break;
        case BlockType::HARD_BLOCK :
            break;
        case BlockType::SOFT_BLOCK :
            this->modifyBlock(searchedCell);
            this->_explosionPositions.push_back(searchedCell);
            if (!_penetrateWalls)
                return (true);
            break;
        default :
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, searchedCell);
            this->_explosionPositions.push_back(searchedCell);
            if (!_penetrateWalls)
                return (true);
            break;
    }
    return (false);
}

void Bomb::managePlayer(std::shared_ptr<Player> player, std::pair<std::size_t, std::size_t> searchedCell)
{
    std::pair<std::size_t, std::size_t> playerMapPosition = player->getMapPosition();

    if (playerMapPosition == searchedCell) {
        player->death();
    }
}

void Bomb::checkInRange()
{
    // std::cout << "Map Position : " << this->_mapPosition.first << "\t" << this->_mapPosition.second << std::endl;
    for (std::pair<int, int> direction : this->_directions) {
        for (std::size_t j = 1; j <= this->_range; j++) {
            std::pair<std::size_t, std::size_t> searchedCell = {this->_mapPosition.first + j * direction.first, this->_mapPosition.second + j * direction.second};
            if (manageMap(searchedCell)) {
                break;
            }
            for (std::shared_ptr<Player> player : _players) {
                managePlayer(player, searchedCell);
            }
            // std::cout << "Searched cell : " << searchedCell.first << "\t" << searchedCell.second << std::endl;
        }
    }
}

std::pair<int, MenuScreens> Bomb::engine(std::shared_ptr<int> window)
{
    if (!_isExploded) {
        if (std::chrono::duration_cast<std::chrono::seconds>(Clock::now() - _clock).count() > _duration) {
            this->checkInRange();
            this->_isExploded = true;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
        }
    }
    if (_isActive) {
        if (std::chrono::duration_cast<std::chrono::seconds>(Clock::now() - _clock).count() > _duration + _explosionDuration) {
            this->_isActive = false;
        }
    }
    return (std::make_pair<int, MenuScreens>(0, MenuScreens::UNDEFINED));
}

void Bomb::setPlayer(std::vector<std::shared_ptr<Player>> players)
{
    this->_players = players;
}

bool Bomb::isExploded()
{
    return (this->_isExploded);
}

bool Bomb::isActive()
{
    return (this->_isActive);
}