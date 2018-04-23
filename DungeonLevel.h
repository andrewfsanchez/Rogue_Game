//
// Created by Ben on 4/20/2018.
//

#ifndef UNTITLED_DUNGEONLEVEL_H
#define UNTITLED_DUNGEONLEVEL_H
#include <random>
#include <vector>
#include <iostream>

struct room
{
    int x,y;
    int width,height;
};

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
	int randomNumberGenerator(int max, int min);
    void generate (int maxFeatures);
    void print();
    bool createFeature;
    bool makeRoom;
    bool placeRoom;
    bool placeObject;

private:
    int _width, _height;
    std::vector<Node> _tiles;
    std::vector<room> _rooms;
    std::vector<room> _exits;

};

#endif //UNTITLED_DUNGEONLEVEL_H
