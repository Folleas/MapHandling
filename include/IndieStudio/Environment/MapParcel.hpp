/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MapParcel
*/

#ifndef MAPPARCEL_HPP_
#define MAPPARCEL_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <fstream>
#include <bits/stdc++.h>

namespace map {
    typedef enum ParcelEdge {
        Blocked = 0,
        Open = 1,
        Closed = 2
    }ParcelEdge;

    typedef enum ParcelInfo {
        UNDEFINED = -1,
        TopLeft = 3,
        Top = 1,
        TopRight = 4,
        Left = 21,
        NoEdge = 0,
        Right = 31,
        BottomLeft = 13,
        Bottom = 11,
        BottomRight = 14
    }ParcelInfo;

    class MapParcel {
        public:
            typedef enum Edge {
                Top = 0,
                Bottom = 1,
                Left = 2,
                Right = 3
            }Edge;

            MapParcel();
            MapParcel(ParcelEdge top, ParcelEdge bottom, ParcelEdge left, ParcelEdge right);
            ~MapParcel();

            void generatePath();
            void joinPath(std::vector<std::shared_ptr<MapParcel>> neighbourParcels);
            void generateMapParcelString();

            void setupParcelInfo();

            void setEdgesStatus(ParcelEdge top, ParcelEdge bottom, ParcelEdge left, ParcelEdge right);
            std::vector<ParcelEdge> getEdgesStatus() const;
            Edge getOppositeEdge(Edge edge) const;
            std::size_t getNbConnections(std::vector<std::shared_ptr<MapParcel>> neighbourParcels);
            ParcelInfo getParcelInfo();
            std::string getMapParcelString();
        private:
            std::unordered_map<ParcelInfo, std::string> _parcelInfo;
            std::pair<std::size_t, std::size_t> _position;
            std::vector<ParcelEdge> _edgesStatus;
            std::string _mapParcelString;
    };
};

#endif /* !MAPPARCEL_HPP_ */
