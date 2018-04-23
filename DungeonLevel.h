//
// Created by Ben on 4/20/2018.
//

#ifndef UNTITLED_DUNGEONLEVEL_H
#define UNTITLED_DUNGEONLEVEL_H
#include <random>
#include <vector>
#include <iostream>
#include <Node.cpp>
#include <mmcobj.h>
#include <Object.h>

class Dungeon
{
public:
    enum Tile
    {
        Unused = '',
        Floor = '.',
        Wall = '#',
        ClosedDoor = '+',
        OpenDoor = '=',
    };

    enum Direction
    {
        North,
        South,
        East,
        West,
        DirectionCount
    };
public:
    Dungeon(void buildLevel);

    void generate (int maxFeatures);
    void print();
    void buildlvl();
    bool createFeature;
    bool makeRoom;
    bool placeRoom;
    bool placeObject;
    void moveObject(Object thing);

private:
    int _width, _height;
    std::vector<Node> _tiles;
    std::vector<room> _rooms;
    std::vector<room> _exits;


};

#endif //UNTITLED_DUNGEONLEVEL_H
