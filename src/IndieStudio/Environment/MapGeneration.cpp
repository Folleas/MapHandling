/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MapGeneration
*/

#include "MapGeneration.hpp"

using namespace map;

MapGeneration::MapGeneration()
{
    srand((unsigned)time(NULL));
}

MapGeneration::~MapGeneration()
{
}

std::shared_ptr<MapParcel> MapGeneration::generateParcel(std::size_t x, std::size_t y)
{
    std::shared_ptr<MapParcel> parcel = std::make_shared<MapParcel>();
    ParcelEdge left = ParcelEdge::Open;
    ParcelEdge right = ParcelEdge::Open;
    ParcelEdge top = ParcelEdge::Open;
    ParcelEdge bottom = ParcelEdge::Open;

    if (y == 0)
        top = ParcelEdge::Blocked;
    else if (y == this->_size.second - 1)
        bottom = ParcelEdge::Blocked;
    if (x == 0)
        left = ParcelEdge::Blocked;
    else if (x == this->_size.first - 1)
        right = ParcelEdge::Blocked;
    parcel->setEdgesStatus(top, bottom, left, right);
    return (parcel);
}

void MapGeneration::joinPathes()
{
    std::shared_ptr<MapParcel> up;
    std::shared_ptr<MapParcel> down;
    std::shared_ptr<MapParcel> left;
    std::shared_ptr<MapParcel> right;
    int currentPosition = 0;
    int upPosition = 0;
    int downPosition = 0;
    int leftPosition = 0;
    int rightPosition = 0;

    for (std::size_t j = 0; j != this->_size.second; j++) {
        for (std::size_t i = 0; i != this->_size.first; i++) {
            currentPosition = Utils::doubleToSingleCoordinate(i, j, this->_size.first, this->_size.second);
            upPosition = Utils::doubleToSingleCoordinate(i, j - 1, this->_size.first, this->_size.second);
            downPosition = Utils::doubleToSingleCoordinate(i, j + 1, this->_size.first, this->_size.second);
            leftPosition = Utils::doubleToSingleCoordinate(i - 1, j, this->_size.first, this->_size.second);
            rightPosition = Utils::doubleToSingleCoordinate(i + 1, j, this->_size.first, this->_size.second);
            if (upPosition != -1)
                up = this->_mapParcels.at(upPosition);
            else
                up = nullptr;
            if (downPosition != -1)
                down = this->_mapParcels.at(downPosition);
            else
                down = nullptr;
            if (leftPosition != -1)
                left = this->_mapParcels.at(leftPosition);
            else
                left = nullptr;
            if (rightPosition != -1)
                right = this->_mapParcels.at(rightPosition);
            else
                right = nullptr;
            this->_mapParcels.at(currentPosition)->joinPath({up, down, left, right});
        }
    }
}

void MapGeneration::buildMap()
{
    std::string map;
    char tmp = 0;

    for (std::shared_ptr<MapParcel> parcel : this->_mapParcels)
        parcel->generateMapParcelString();
    for (std::size_t y = 0; y != this->_size.second; y++) {
        for (std::size_t offset = 0; offset < 9; offset += 3) {
            for (std::size_t x = 0; x != this->_size.first; x++) {
                for (std::size_t i = offset; i != offset + 3; i++) {
                    tmp = this->_mapParcels.at(x + (y * this->_size.first))->getMapParcelString().at(i);
                    map.push_back(tmp);
                }
            }
            map.push_back('\n');
        }
    }
    std::cout << map << std::endl;
    this->_map = map;
}

std::string MapGeneration::getMap()
{
    return (this->_map);
}

void MapGeneration::generateRectMap(std::size_t xFactor, std::size_t yFactor)
{
    this->_size.first = 3 + (rand() % xFactor);
    this->_size.second = 3 + (rand() % yFactor);
    std::string mapTemp;
    std::vector<std::shared_ptr<MapParcel>> mapParcelsTemp;

    for (std::size_t i = 0; i != this->_size.second; i++) {
        for (std::size_t y = 0; y != this->_size.first; y++) {
            std::shared_ptr<MapParcel> parcelTmp = generateParcel(y, i);
            parcelTmp->generatePath();
            mapParcelsTemp.push_back(parcelTmp);
            // std::cout << "\t" << parcelTmp->getEdgesStatus().at(MapParcel::Edge::Top) << "\t" << std::endl;
            // std::cout << parcelTmp->getEdgesStatus().at(MapParcel::Edge::Left) << "\t*\t" << parcelTmp->getEdgesStatus().at(MapParcel::Edge::Right) << std::endl;
            // std::cout << "\t" << parcelTmp->getEdgesStatus().at(MapParcel::Edge::Bottom) << "\t" << std::endl;
        }
    }
    this->_mapParcels = mapParcelsTemp;
    this->joinPathes();
    buildMap();
}

std::vector<std::pair<std::size_t, std::size_t>> MapGeneration::getSpawnPositions()
{
    return (this->_spawnPositions);
}

std::pair<std::size_t, std::size_t> MapGeneration::getSize()
{
    return (this->_size);
}