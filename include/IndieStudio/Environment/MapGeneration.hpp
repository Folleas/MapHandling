/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#ifndef MAPGENERATION_HPP_
#define MAPGENERATION_HPP_

#include "MapParcel.hpp"
#include "Utils.hpp"

namespace map {
    class MapGeneration {
        public :
            MapGeneration();
            ~MapGeneration();

            void generateRectMap(std::size_t xFactor, std::size_t yFactor);
            std::shared_ptr<MapParcel> generateParcel(std::size_t x, std::size_t y);
            void joinPathes();
            void buildMap();

            std::vector<std::pair<std::size_t, std::size_t>> getSpawnPositions();
            std::pair<std::size_t, std::size_t> getSize();
            std::string getMap();
        protected:
            std::pair<std::size_t, std::size_t> _size;
            std::vector<std::shared_ptr<MapParcel>> _mapParcels;
            std::vector<std::pair<std::size_t, std::size_t>> _spawnPositions;
            std::string _map;
    };
};

#endif /* !MAPGENERATION_HPP_ */
