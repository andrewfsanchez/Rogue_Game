//
// Created by Ben on 4/20/2018.
//

#include "DungeonLevel.h"




int Dungeon::randomNumberGenerator(int max, int min)                        //This generator is used to give us a random number so we can keep up constant new levels
{
	return rand() % max + min;
};

int Dungeon::randRoomWidth(int numRooms)                                  //We use two methods to give us the random width and length of each room so we can get varying sizes.
{
	return randomNumberGenerator(18, 13) - numRooms;
}

int Dungeon::randRoomLength(int numRooms)
{
	return randomNumberGenerator(18, 13) - numRooms;
}

int Dungeon::numRoomsGenerator()
{
	return randomNumberGenerator(9, 4);
}

int Dungeon::randDirectionGenerator()
{
	return randomNumberGenerator(1, 4);
}

int Dungeon::randWallGenerator()
{
    return randomNumberGenerator(100,10);
}

void Dungeon::checkerify(Node grid[30][30],int numWalls, int width, int length)
{
    Object* wall = new Wall();
    int currentWalls =0;

    for (int i = 0; i <= length;i++ )
    {
        for (int k = 0; k <= width; k++ )
        {
            int chance = randomNumberGenerator(8,1);

            if(currentWalls == numWalls)
            {
                return;
            }
            if (chance == 1)
            {
                grid[15 - (length / 2) + i][15 - (width / 2) + k].setObject(wall);
                currentWalls++;
            }
        }
    }

}

void Dungeon::makeStartRoom(int width, int length, Node grid[30][30], Object* p)
{
    if (length<5)
    {
        length =5;
    }
    if (width<5)
    {
        width=5;
    }
	for (int i = 0; i <= length; i++)                                //Because the grid should be filled with walls at this point this starting piece will go to the middle
	{                                                               //of the 30 by 30 grid and begin filling in the first room with the random length and width given
		for (int k = 0; k <= width; k++)                           //By creating a static starting position it will be easier to create logic to randomly add
		{                                                           //rooms and corridors in different given directions.
			grid[15-(length/2)+i][15-(width/2)+k] = Node();
		}
	}

	grid[15][15].setObject(p);
}


void Dungeon::dungeonBuild(Node grid[30][30], Object* p, Object* x)                     //We pass in the original grid created which is filled with Nodes that point to nothing. Here we will begin
{                                                              //to populate the grid with rooms. I start by filling it with walls because it is easier to delete walls
															   //delete walls to build a room and it will help with the algorithm later used to place more rooms.

	int numRooms = numRoomsGenerator();                       //Here we will randomly decide how many rooms this dungeon level will have
	int *roomLength = new int[numRooms];
	int *roomWidth = new int[numRooms];
	Object* wall = new Wall();

	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 30; k++)
		{
			grid[i][k] = Node(wall);
		}
	}

	for (int i = 0; i <= numRooms; i++)                          //In this loop we generate a random length and width for each room stored in a 1d array so we can retrieve
																 //them later while building the rooms.
	{

		roomLength[i] = randRoomLength(numRooms);              //It is important for these functions to have the number of rooms passed in as the general sized of the
		roomWidth[i] = randRoomWidth(numRooms);               //rooms will change based on whether or not there are a lot of rooms or a few.

	}

	makeStartRoom(roomWidth[0], roomLength[0], grid, p);           //First room is made so others can build off it. The center is always chosen but size is random
	numRooms = numRooms - 1;

	                                                              //starting from 1 because the 0th room has already been made.
   // makeRoom(numRooms, roomWidth[i], roomLength[i], grid);
    int numWalls = randWallGenerator();
    checkerify(grid,numWalls,roomWidth[0],roomLength[0]);

    addOneItem(roomLength[0],roomWidth[0],grid);

    grid[15][15].setObject(p);
    grid[15][16].setObject(NULL);
    grid[16][16].setObject(NULL);
    grid[16][17].setObject(NULL);
    
    bool exit = false;
    for (int i = 0; i < 30; i++)
    {
        for (int k = 0; k < 30; k++)
        {
            if (grid[i][k].getObject() == NULL)
            {
            	int chance = randomNumberGenerator(100,0);
            	if (i == 15 && k == 15)
            		continue;
            	else if (i > 15 && k > 15)
            	{
            		if (chance >= 95)
            		{
            			grid[i][k] = Node(x);
            			grid[i][k].setObject(x);
            			x->setX(k);
            			x->setY(i);
   						i = 100;
   						k = 100;
   						exit = true;
   						break;
   					}
   				}
   					
   			}
   			if (i == 29 && exit == false)
   			{
   				grid[17][17] = Node(x);
   				x->setX(17);
   				x->setY(17);
   				break;
   			}
   		}
   	}
}

void Dungeon::addOneItem(int length, int width, Node grid[30][30])
{
    int item = randomNumberGenerator(1,0);

    Item* potion = new Item("Potion", 5,  0, 0, 0, false, false,true);


    int itemY = randomNumberGenerator(15+(length/2),15-(length/2));
    int itemX = randomNumberGenerator(15+(width/2),15-(width/2));


    if(item == 1)
    {
        grid[itemY][itemX].setObject(potion);
    }
}


void Dungeon::addEnemiesToMap(Node grid[30][30], int difficulty, vector<Enemy> &enemies, int floor)
{
    for (int i = 0; i < 30; i++)
    {
        for (int k = 0; k < 30; k++)
        {
            if (grid[i][k].getObject() == NULL)
            {
                int chance = randomNumberGenerator(100,0);
                int whatEnemy = randomNumberGenerator(100,0);

                if (chance >= 99-difficulty)                    //This assumes difficult is something like 3 for hard. 2 for med. 1 for easy
                {
                    int direction = randomNumberGenerator(3,0);

                        if (whatEnemy <= 40)
                        {
                            Enemy* Bat = new Enemy(i,k,direction);
							Bat->setType(1);
                            grid[i][k].setObject(Bat);
                            Bat->setX(i);
                            Bat->setY(k);
                            Bat->setAttack(7*floor); //multiplied by floor
                            Bat->setDefense(0); //keep 0
                            Bat->setHealth(10*floor); //multiplied by floor
                            Bat->setExp(5 + floor); //add by floor# multiplied by 1 
                            enemies.push_back (*Bat);
                        }
                        
                        
                        else if (whatEnemy <=86 && whatEnemy >= 66) 
                        {
                            Enemy* Spider = new Enemy(i,k,direction);
                            Spider->setType(2);
                            grid[i][k].setObject(Spider);
                            Spider->setX(i);
                            Spider->setY(k);
                            Spider->setAttack(8*floor); //multiplied by floor
                            Spider->setDefense(5); //keep constant
                            Spider->setHealth(20*floor); //multiplied by floor
                            Spider->setExp(6 + floor); //add by floor# multiplied by 1
                            enemies.push_back (*Spider);
                        }
                        
                        else if (whatEnemy <=100 && whatEnemy >= 87)
						{
                            Enemy* Zombie = new Enemy(i,k,direction);
                            Zombie->setType(3);
                            grid[i][k].setObject(Zombie);
                            Zombie->setX(i);
                            Zombie->setY(k);
                            Zombie->setAttack(15*floor); //multiplied by floor
                            Zombie->setDefense(10); //keep constant
                            Zombie->setHealth(25*floor); //multiplied by floor
                            Zombie->setExp(7 + floor); //add by floor# multiplied by 1
                            enemies.push_back (*Zombie);
						}

                }

            }

        }
    }
}
