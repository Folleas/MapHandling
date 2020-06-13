/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MapParcel
*/

#include "MapParcel.hpp"

using namespace map;

MapParcel::MapParcel()
{
    setupParcelInfo();
}

MapParcel::MapParcel(ParcelEdge top, ParcelEdge bottom, ParcelEdge left, ParcelEdge right)
{
    setupParcelInfo();
    setEdgesStatus(top, bottom, left, right);
}

MapParcel::~MapParcel()
{
}

void MapParcel::setupParcelInfo()
{
    _parcelInfo[ParcelInfo::TopLeft] = "TopLeft";
    _parcelInfo[ParcelInfo::Top] = "Top";
    _parcelInfo[ParcelInfo::TopRight] = "TopRight";
    _parcelInfo[ParcelInfo::Left] = "Left";
    _parcelInfo[ParcelInfo::NoEdge] = "NoEdge";
    _parcelInfo[ParcelInfo::Right] = "Right";
    _parcelInfo[ParcelInfo::BottomLeft] = "BottomLeft";
    _parcelInfo[ParcelInfo::Bottom] = "Bottom";
    _parcelInfo[ParcelInfo::BottomRight] = "BottomRight";
}

void MapParcel::setEdgesStatus(ParcelEdge top, ParcelEdge bottom, ParcelEdge left, ParcelEdge right)
{
    this->_edgesStatus = {top, bottom, left, right};
}

std::vector<ParcelEdge> MapParcel::getEdgesStatus() const
{
    return (_edgesStatus);
}

void MapParcel::generatePath()
{
    for (ParcelEdge &edge : _edgesStatus) {
        if (edge != ParcelEdge::Blocked && rand() % 2 == 0) {
            edge = ParcelEdge::Closed;
        }
    }
}

MapParcel::Edge MapParcel::getOppositeEdge(Edge edge) const
{
    Edge oppositeEdge;

    switch (edge) {
        case Edge::Top :
            oppositeEdge = Edge::Bottom;
            break;
        case Edge::Bottom :
            oppositeEdge = Edge::Top;
            break;
        case Edge::Left :
            oppositeEdge = Edge::Right;
            break;
        case Edge::Right :
            oppositeEdge = Edge::Left;
            break;
    }
    return (oppositeEdge);
}

std::size_t MapParcel::getNbConnections(std::vector<std::shared_ptr<MapParcel>> neighbourParcels)
{
    std::size_t nbConnections = 0;
    int oppositeEdge = 0;

    for (std::size_t edge = Edge::Top; edge != this->_edgesStatus.size(); edge++) {
        if (neighbourParcels.at(edge) == nullptr)
            continue;
        oppositeEdge = getOppositeEdge((Edge)edge);
        if (this->_edgesStatus.at(edge) == ParcelEdge::Open && neighbourParcels.at(edge)->_edgesStatus.at(oppositeEdge) == ParcelEdge::Open) {
            nbConnections++;
        }
    }
    return (nbConnections);
}

void MapParcel::joinPath(std::vector<std::shared_ptr<MapParcel>> neighbourParcels)
{
    std::vector<Edge> unlinkedEdges;
    std::vector<Edge> linkedEdges;
    std::vector<Edge> chosenEdges;
    std::size_t nbConnections = getNbConnections(neighbourParcels);
    int oppositeEdge = 0;
    int randomEdge = 0;

    while (nbConnections < 2) {
        for (std::size_t edge = Edge::Top; edge != this->_edgesStatus.size(); edge++) {
            if (neighbourParcels.at(edge) == nullptr)
                continue;
            oppositeEdge = getOppositeEdge((Edge)edge);
            if ((this->_edgesStatus.at(edge) == ParcelEdge::Closed && neighbourParcels.at(edge)->_edgesStatus.at(oppositeEdge) == ParcelEdge::Open) || (this->_edgesStatus.at(edge) == ParcelEdge::Open && neighbourParcels.at(edge)->_edgesStatus.at(oppositeEdge) == ParcelEdge::Closed)) {
                unlinkedEdges.push_back((Edge)edge);
            }
            else {
                linkedEdges.push_back((Edge)edge);
            }
        }
        if (unlinkedEdges.size() == 0) {
            randomEdge = rand() % linkedEdges.size();
            chosenEdges = linkedEdges;
        }
        else {
            randomEdge = rand() % unlinkedEdges.size();
            chosenEdges = unlinkedEdges;
        }
        oppositeEdge = getOppositeEdge(chosenEdges.at(randomEdge));
        this->_edgesStatus.at(chosenEdges.at(randomEdge)) = ParcelEdge::Open;
        neighbourParcels.at(chosenEdges.at(randomEdge))->_edgesStatus.at(oppositeEdge) = ParcelEdge::Open;
        nbConnections++;
    }
}

ParcelInfo MapParcel::getParcelInfo()
{
    std::vector<Edge> blockedEdges;
    ParcelInfo parcelInfo = ParcelInfo::UNDEFINED;

    for (std::size_t i = Edge::Top; i != this->_edgesStatus.size(); i++) {
        if (this->_edgesStatus.at(i) == ParcelEdge::Blocked)
            blockedEdges.push_back((Edge)i);
    }
    if (blockedEdges.size() != 0) {
        parcelInfo = (ParcelInfo)(blockedEdges.at(0) * 10);
        if (blockedEdges.size() > 1)
            parcelInfo = (ParcelInfo)(parcelInfo + blockedEdges.at(1));
        parcelInfo = (ParcelInfo)(parcelInfo + 1);
    }
    else {
        parcelInfo = ParcelInfo::NoEdge;
    }
    return (parcelInfo);
}

void MapParcel::generateMapParcelString()
{
    static int count = 0;
    ParcelInfo parcelInfo = getParcelInfo();
    std::string parcelInfoString(this->_parcelInfo[parcelInfo]);
    std::ifstream file("res/MapParcel/" + parcelInfoString);
    std::vector<std::string> lines;
    std::string lineTemp;
    std::string line;
    std::size_t i = 0;

    while (std::getline(file, lineTemp)) {
        if (lineTemp.size() == 3) {
            line.append(lineTemp);
            i++;
            if (i == 3) {
                if (line.at(1) - '0' == this->_edgesStatus.at(Edge::Top) && line.at(7) - '0' == this->_edgesStatus.at(Edge::Bottom) && line.at(3) - '0' == this->_edgesStatus.at(Edge::Left) && line.at(5) - '0' == this->_edgesStatus.at(Edge::Right)) {
                    lines.push_back(line);
                }
                i = 0;
                line = "";
            }
        }
    }
    if (lines.size() != 0) {
        this->_mapParcelString = lines.at(rand() % (lines.size()));
    }
    else {
        std::cerr << "Error : No matching Parcel in file " << parcelInfoString << std::endl;
        exit (84);
    }
}

std::string MapParcel::getMapParcelString()
{
    return (_mapParcelString);
}