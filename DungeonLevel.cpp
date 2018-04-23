//
// Created by Ben on 4/20/2018.
//

#include "DungeonLevel.h"
#include <node.cpp>
#include <wall.cpp>
#include <random>
#include <iostream>
#include <random>
#include <vector>

int randomNumberGenerator(int max, int min)                        //This generator is used to give us a random number so we can keep up constant new levels
 {

     std::default_random_engine generator;
     std::uniform_int_distribution<int> distribution(min,max);
     return distribution(generator);
 };

int randRoomWidth (int numRooms)                                  //We use two methods to give us the random width and length of each room so we can get varying sizes.
{
    return randomNumberGenerator(18,13) - numRooms;
}

int randRoomLength(int numRooms)
{
    return randomNumberGenerator(18,13) - numRooms;
}

int numRoomsGenerator ()
{
    return randomNumberGenerator(9,4);
}

int randDirectionGenerator()
{
   return randomNumberGenerator(1,4);
}


void makeStartRoom(int width, int length, Node grid[30][30])
{
    for (int i = 0; i <= width; i++)                                //Because the grid should be filled with walls at this point this starting piece will go to the middle
    {                                                               //of the 30 by 30 grid and begin filling in the first room with the random length and width given
        for (int k = 0; k<= length; k++ )                           //By creating a static starting position it will be easier to create logic to randomly add
        {                                                           //rooms and corridors in different given directions.
            grid[i+15][k+15] = Node();
        }
    }
}

void printRoom(int direction, int width, int length, int row, int col, Node grid[30][30])
{
    Object* door = new door();

    switch (direction)
{

    case 1:           //up

        grid[row][col].setObject(door);            //the original point selected becomes a door to the new room.

        for (int i = 1; i<= length; i++)
        {
            for (int k = 0; k<=width; k++)
            {
                grid[row-i][col+k].setObject(NULL);
            }
        }
        break;

    case 2:           //down

        grid[row][col].setObject(door);

        for (int i = 1; i<= length; i++)
        {
            for (int k = 0; k<=width; k++)
            {
                grid[row+i][col+k].setObject(NULL);
            }
        }
        break;

    case 3:           //left

        grid[row][col].setObject(door);

        for (int i = 0; i<= length; i++)
        {
            for (int k = 1; k<=width; k++)
            {
                grid[row+i][col-k].setObject(NULL);
            }
        }
        break;

    case 4:           //right

        grid[row][col].setObject(door);

        for (int i = 0; i<= length; i++)
        {
            for (int k = 1; k<=width; k++)
            {
                grid[row+i][col+k].setObject(NULL);
            }
        }
        break;

    default:
    {
        break;
    }
}

}

bool isValidDirection (int direction, int width, int length, int row, int col, Node grid[30][30])                        //1 = up, 2 = down, 3 = left, 4 = right.
{
    Object* wall = new wall();
    switch (direction)
    {
        case 1:
        {
            for (int i = 0; i <= length; i++)
            {
                if (row - length >= 0) {
                    if (grid[row - i][col].getObject() == wall)
                    {
                        for (int k = 0; k <= width; k++)
                        {
                            if (col + width <= 30)
                            {
                                if (grid[row - i][col + k].getObject() == wall)
                                {
                                    continue;
                                }

                                else
                                {
                                    return false;
                                }
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        case 2:
        {
            for (int i = 0; i <= length; i++)
            {
                if (row + length <= 30) {
                    if (grid[row + i][col].getObject() == wall)
                    {
                        for (int k = 0; k <= width; k++)
                        {
                            if (col + width <= 30)
                            {
                                if (grid[row + i][col + k].getObject() == wall)
                                {
                                    continue;
                                }

                                else
                                {
                                    return false;
                                }
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        case 3:
        {
            for (int i = 0; i <= width; i++)
            {
                if (col - width >= 0) {
                    if (grid[row][col-i].getObject() == wall)
                    {
                        for (int k = 0; k <= length; k++)
                        {
                            if (length + row  <= 30)
                            {
                                if (grid[row + i][col - k].getObject() == wall)
                                {
                                    continue;
                                }

                                else
                                {
                                    return false;
                                }
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        case 4:
        {
            for (int i = 0; i <= width; i++)
            {
                if (col + width <= 30) {
                    if (grid[row][col+i].getObject() == wall)
                    {
                        for (int k = 0; k <= length; k++)
                        {
                            if (length + row  <= 30)
                            {
                                if (grid[row + i][col + k].getObject() == wall)
                                {
                                    continue;
                                }

                                else
                                {
                                    return false;
                                }
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        default:
        {
            return false;
        }
    }
}

bool isEdge(Node grid[30][30], int i, int k)              //This function finds whether or not a node is the edge of a room by checking the rooms around it
                                                          //seeing if it has exactly 1 open/ground tile above, below, left or right of it then returns true
                                                          //for each point that is an edge. This will be used to determine edges of rooms where corridors and other
                                                          //rooms will be added
{
   int numFloor = 0;
                                                          //checks the spot above, below, left or right of the original point
       if (grid[i+1][k].getObject() ==NULL )
       {
           numFloor++;
       }

       if (grid[i-1][k].getObject() ==NULL )
       {
           numFloor++;
       }

       if (grid[i][k+1].getObject() ==NULL )
       {
           numFloor++;
       }
       if (grid[i][k-1].getObject() ==NULL)
       {
           numFloor++;
       }

    if (numFloor == 1)
    {
        return true;
    }
    else
    {
        return false;
    }

};

bool roomMadeHere()
{
   int chance = randomNumberGenerator(100,0);
    if (chance<= 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void makeRoom(int numRooms, int width, int length, Node grid[30][30])
{
                                                                 //This next piece of the method chooses a random direction, places a corridor of random length,
                                                                 //then attempts to put a room at the end of that corridor on a random direction.

    for (int r = 0; r<= numRooms;)
    {
        for (int i= 0; i <= 30; i++)
        {
            for (int k = 0; k <= 30; k++)
            {
                if ( isEdge(grid,i,k))
                {
                    if (roomMadeHere())
                    {
                        int direction= randDirectionGenerator();                    //random direction decided to start

                        if (isValidDirection(direction, width,length,i,k,grid))
                        {
                            printRoom(direction,width,length,i,k,grid);
                        }
                        else                                                        //if direction fails try every other direction starting with 4 and going down to 1.
                        {
                            for (direction = 4; direction >= 1; direction--)
                            {
                                if (isValidDirection(direction, width,length,i,k,grid))
                                {
                                    printRoom(direction,width,length,i,k,grid);
                                }
                            }
                        }

                        switch (direction)
                        {
                            case 1:
                                if (isValidDirection(direction,width,length,i,k,grid))
                                {
                                    printRoom(direction,width,length,i,k,grid);
                                }
                                break;
                            case 2:
                                if (isValidDirection(direction,width,length,i,k,grid))
                                {
                                    printRoom(direction,width,length,i,k,grid);
                                }
                                break;
                            case 3:
                                if (isValidDirection(direction,width,length,i,k,grid))
                                {
                                    printRoom(direction,width,length,i,k,grid);
                                }
                                break;

                            case 4:
                                if (isValidDirection(direction,width,length,i,k,grid))
                                {
                                    printRoom(direction,width,length,i,k,grid);
                                }
                                break;

                            default:
                                {
                                    break;
                                }

                        }

                    }
                    else
                    {
                        continue;
                    }

                }
                else
                {
                    continue;
                }
            }
        }
    }

    for (int i = 0; i < 30; i++)
    {
        for (int k = 0; k < 30; k++)                               //todo this is where I left off
        {
            grid[i][k] = Node();                                   //todo look into this error later
        }
    }
};

void dungeonBuild (Node grid[30][30])                     //We pass in the original grid created which is filled with Nodes that point to nothing. Here we will begin
{                                                              //to populate the grid with rooms. I start by filling it with walls because it is easier to delete walls
                                                              //delete walls to build a room and it will help with the algorithm later used to place more rooms.

    int numRooms = numRoomsGenerator();                       //Here we will randomly decide how many rooms this dungeon level will have
    int roomLength[numRooms];
    int roomWidth[numRooms];
    Object* wall = new wall();

    for (int i = 0; i < 30; i++)
    {
        for (int k = 0; k < 30; k++)
        {
            grid[i][k] = Node.setObject(wall);                     //todo look into this error later
        }
    }

    for (int i = 0;i<=numRooms; i++)                          //In this loop we generate a random length and width for each room stored in a 1d array so we can retrieve
                                                              //them later while building the rooms.
    {

       roomLength[i] = randRoomLength(numRooms);              //It is important for these functions to have the number of rooms passed in as the general sized of the
       roomWidth[i]  = randRoomWidth(numRooms);               //rooms will change based on whether or not there are a lot of rooms or a few.

    }

    makeStartRoom(roomWidth[0],roomLength[0],grid);           //First room is made so others can build off it. The center is always chosen but size is random

    numRooms = numRooms-1;

    int i = 1;                                                //starting from 1 because the 0th room has already been made.
        makeRoom(numRooms, roomWidth[i],roomLength[i], grid);



}