/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"
#include "Bomb.hpp"

Player::Player(std::size_t maxHealth, std::size_t totalBombSimultaneously, std::size_t speed, std::size_t speedFactor, std::size_t bombFirePower, bool wallPass)
{
    this->_maxHealthPoint = maxHealth;
    this->_totalBombSimultaneously = totalBombSimultaneously;
    this->_speed = speed;
    this->_bombFirePower = bombFirePower;
    this->_wallPass = wallPass;
    this->_speedFactor = speedFactor;
    this->_position = std::make_pair<int, int>(0, 0);
    this->_bombButtonPressed = false;
    this->_pauseButtonPressed = false;
    this->_isDead = false;

    // if (!this->_texture.loadFromFile("res/Textures/dot.png")) {
    //     std::cerr << "Failed to load files" << std::endl;
    //     exit (84);
    // }
    // /*error handling*/
    // this->_sprite.setTexture(_texture);
    // this->_sprite.setScale(3, 3);
}

Player::~Player()
{
}

void Player::setControler(irr::EKEY_CODE leftKeyCode, irr::EKEY_CODE rightKeyCode, irr::EKEY_CODE upKeyCode, irr::EKEY_CODE downKeyCode, irr::EKEY_CODE bombKeyCode, irr::EKEY_CODE pauseKeyCode)
{
    this->_controler = std::make_unique<PlayerControler>(leftKeyCode, rightKeyCode, upKeyCode, downKeyCode, bombKeyCode, pauseKeyCode);
}

void Player::setControler(std::vector<irr::EKEY_CODE> newKeys)
{
    this->_controler = std::make_unique<PlayerControler>(newKeys.at(TextInputs::Left), newKeys.at(TextInputs::Right), newKeys.at(TextInputs::Up), newKeys.at(TextInputs::Down), newKeys.at(TextInputs::Bomb), newKeys.at(TextInputs::Pause));
}

void Player::setScreenSize(std::pair<std::size_t, std::size_t> screenSize)
{
    this->_screenSize = screenSize;
}

void Player::manageAxis(int direction, float &position, std::size_t &mapPosition, std::size_t sizeX, Axis axis)
{
    std::pair<std::size_t, std::size_t> mapSize = this->_map->getSize();

    if (direction != 0) {
        std::size_t positionTemp = position + (direction * (int)_speed * (int)this->_speedFactor);
        std::size_t mapPositionTemp = (positionTemp * mapSize.first * BLOCK_PER_PARCEL) / (SPRITE_SIZE_X * (mapSize.first * BLOCK_PER_PARCEL));
        std::size_t offsetPositionXTemp = (position + SPRITE_OFFSET_X) + (direction * (int)_speed * (int)this->_speedFactor);
        std::size_t offsetMapPositionXTemp = (offsetPositionXTemp * mapSize.first * BLOCK_PER_PARCEL) / (SPRITE_SIZE_X * (mapSize.first * BLOCK_PER_PARCEL));
        std::size_t offsetPositionYTemp = (position + SPRITE_OFFSET_Y) + (direction * (int)_speed * (int)this->_speedFactor);
        std::size_t offsetMapPositionYTemp = (offsetPositionYTemp * mapSize.first * BLOCK_PER_PARCEL) / (SPRITE_SIZE_X * (mapSize.first * BLOCK_PER_PARCEL));
        if (axis == Axis::Horizontal) {
            // if (map::Map::checkMapCharAtPosition(map, {mapPositionTemp, this->_mapPosition.second}, _wallPass, sizeX) && map::Map::checkMapCharAtPosition(map, {offsetMapPositionXTemp, this->_mapPosition.second}, _wallPass, sizeX) && \
            // map::Map::checkMapCharAtPosition(map, {mapPositionTemp, offsetMapPositionYTemp}, _wallPass, sizeX) && map::Map::checkMapCharAtPosition(map, {offsetMapPositionXTemp, offsetMapPositionYTemp}, _wallPass, sizeX)) {
                position = positionTemp;
            // }
        }
        if (axis == Axis::Vertical) {
            // if (map::Map::checkMapCharAtPosition(map, {this->_mapPosition.first, mapPositionTemp}, _wallPass, sizeX) && map::Map::checkMapCharAtPosition(map, {this->_mapPosition.first, offsetMapPositionYTemp}, _wallPass, sizeX) && \
            // map::Map::checkMapCharAtPosition(map, {offsetMapPositionXTemp, mapPositionTemp}, _wallPass, sizeX) && map::Map::checkMapCharAtPosition(map, {offsetMapPositionXTemp, offsetMapPositionYTemp}, _wallPass, sizeX)) {
                position = positionTemp;
            // }
        }
    }
    mapPosition = (position * mapSize.first * BLOCK_PER_PARCEL) / (SPRITE_SIZE_X * (mapSize.first * BLOCK_PER_PARCEL));
}

void Player::managePowerUps()
{
    switch (this->_map->getMapCharAtPosition(this->_mapPosition)) {
        case SOFT_BLOCK_PASS_BLOCK :
            this->_wallPass = true;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
            break;
        case BOMB_PASS_BLOCK :
            this->_bombPass = true;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
            break;
        case FIRE_UP_BLOCK :
            this->_bombFirePower++;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
            break;
        case FIRE_DOWN_BLOCK :
            if (this->_bombFirePower > 1)
                this->_bombFirePower--;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
            break;
        case SPEED_UP_BLOCK :
            this->_speedFactor++;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
            break;
        case SPEED_DOWN_BLOCK :
            if (this->_speedFactor > 1)
                this->_speedFactor--;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
            break;
        case BOMB_UP_BLOCK :
            this->_totalBombSimultaneously++;
            this->_map->changeMapCharAtPosition(BlockType::EMPTY_BLOCK, this->_mapPosition);
            break;
    }
}

void Player::move()
{
    irr::EKEY_CODE lastKeyPressed = this->getControler()->getLastKeyPressed();
    std::pair<std::size_t, std::size_t> mapSize = {this->_map->getSize().first * 3, this->_map->getSize().second * 3};

    if (lastKeyPressed == this->getControler()->getLeftKeyCode() || lastKeyPressed == this->getControler()->getRightKeyCode())
        this->manageAxis(this->_directions.first, this->_position.first, this->_mapPosition.first, mapSize.first, Axis::Horizontal);
    if (lastKeyPressed == this->getControler()->getUpKeyCode() || lastKeyPressed == this->getControler()->getDownKeyCode())
        this->manageAxis(this->_directions.second, this->_position.second, this->_mapPosition.second, mapSize.first, Axis::Vertical);
    managePowerUps();
    // std::cout << "char " << map.at((this->_mapPosition.first + this->_mapPosition.second * sizeX) + this->_mapPosition.second) << "\nx = " << this->_mapPosition.first << "\ty = " << this->_mapPosition.second << std::endl;
    // std::cout << "\t" << map.at((this->_mapPosition.first + (this->_mapPosition.second - 1) * sizeX) + (this->_mapPosition.second - 1)) << "\t" << std::endl;
    // std::cout << map.at(((this->_mapPosition.first - 1) + (this->_mapPosition.second) * sizeX) + (this->_mapPosition.second)) << "\t" << map.at((this->_mapPosition.first + this->_mapPosition.second * sizeX) + this->_mapPosition.second) << "\t" << map.at(((this->_mapPosition.first + 1) + this->_mapPosition.second * sizeX) + this->_mapPosition.second) << std::endl;
    // std::cout << "\t" << map.at((this->_mapPosition.first + (this->_mapPosition.second + 1) * sizeX) + (this->_mapPosition.second + 1)) << "\t" << std::endl;
}

void Player::pauseGame()
{
    if (this->_pauseButtonPressed) {
        this->_pause = true;
        this->_pauseButtonPressed = false;
        std::cout << "Game Paused" << std::endl;
    }
}

void Player::updateInputStatus(std::shared_ptr<Event> event)
{
    this->_directions.first = this->_controler->getHorizontalDirection(event);
    this->_directions.second = this->_controler->getVerticalDirection(event);
    if (!_bombButtonPressed)
        this->_bombButtonPressed = this->_controler->isBombButtonPressed(event);
    if (!_pauseButtonPressed)
        this->_pauseButtonPressed = this->_controler->isPauseButtonPressed(event);
}

void Player::manageBomb()
{
    if (this->_layedBombs.size() < this->_totalBombSimultaneously) {
        if (this->_bombButtonPressed) {
            std::shared_ptr<IS::Bomb> bomb = std::make_shared<IS::Bomb>(this->_map, this->getPosition(), this->getMapPosition(), this->_bombFirePower);
            bomb->setPlayer(this->_players);
            this->_layedBombs.push_back(bomb);
        }
    }
    this->_bombButtonPressed = false;
    for (std::size_t i = 0; i < this->_layedBombs.size(); i++) {
        if (!this->_layedBombs.at(i)->isActive()) {
            this->_layedBombs.erase(this->_layedBombs.begin() + i);
        }
    }
}

std::shared_ptr<PlayerControler> Player::getControler() const
{
    return (this->_controler);
}

void Player::setPosition(std::pair<float, float> newValues)
{
    this->_position = newValues;
}

std::pair<float, float> Player::getPosition(void)
{
    return (this->_position);
}

void Player::display(std::shared_ptr<int> window)
{
    // if (!this->_isDead) {
    //     this->_sprite.setPosition(sf::Vector2f(this->_position.first, this->_position.second - 12 * 3));
    //     window->draw(this->_sprite);
    //     for (std::shared_ptr<IS::Bomb> bomb : this->_layedBombs) {
    //         bomb->display(window);
    //     }
    // }
}

int Player::event(std::shared_ptr<Event> event)
{
    // if (!this->_isDead) {
    //     this->updateInputStatus(event);
    //     for (std::shared_ptr<IS::Bomb> bomb : this->_layedBombs) {
    //         bomb->event(event);
    //     }
    // }
    // if (this->_pause) {
    //     this->_pause = false;
    //     return (1);
    // }
    return (0);
}

std::pair<int, MenuScreens> Player::engine(std::shared_ptr<int> window)
{
    // if (!this->_isDead) {
    //     this->move();
    //     this->manageBomb();
    //     this->pauseGame();
    //     for (std::shared_ptr<IS::Bomb> bomb : this->_layedBombs) {
    //         bomb->engine(window);
    //     }
    // }
    return (std::make_pair<int, MenuScreens>(0, MenuScreens::UNDEFINED));
}

void Player::death()
{
    this->_isDead = true;
}

std::pair<std::size_t, std::size_t> Player::getMapPosition() const
{
    return (this->_mapPosition);
}

void Player::setMap(std::shared_ptr<map::Map> map)
{
    this->_map = map;
}

void Player::setPlayers(std::vector<std::shared_ptr<Player>> players)
{
    this->_players = players;
}