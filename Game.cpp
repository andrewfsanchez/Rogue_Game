#include "Game.h"
#include <cstdlib>


Game::Game(int diff) 
{
	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 30; k++)
			{
				grid[i][k] = Node();
			}
	}
	difficulty = diff;
	floor = 0;
	player = Player();
}

void Game::makeLevel()
{
	clearGrid();
	floor++;
	int rooms = rand() % 4 + 3;
	int roomSize = 15 - rooms;



}

void Game::playerAction() 
{
	bool check = true;
	while (check)
	{
		string input="";
		cout << "What will you do? (M= move, D= drop item, U= use item, W= wait)";
		cin >> input;

		if (input.compare("M") == 0 || input.compare("m")==0)
		{
			check = false;
			//playerMove();
		}
		else if (input.compare("D")==0 || input.compare("d") == 0)
		{
			if (!player.isInvEmpty())
			{
				check = false;
				//playerDrop();
			}
			else
				cout << "Your inventory is empty.\n";
		}
		else if (input.compare("U") == 0 || input.compare("u") == 0)
		{
			if (!player.isInvEmpty())
			{
				check = false;
				//playerUseItem();
			}
			else
				cout << "Your inventory is empty.\n";
		}
		else if (input.compare("W") == 0 || input.compare("w") == 0)
		{
			check = false;
			updateGrid();
		}
		else
			cout << "Enter a valid command.\n";
	}
}

void Game::updateGrid()
{
	//moveEnemies();

	if (player.getHealth()<1) 
	{
		//gameOver();
	}
}

void Game::printGrid()
{
	for (int i=0; i<30;i++)
	{
		for (int k = 0; k < 30; k++)
		{
			grid[i][k].print();
		}
		cout << "\n";
	}
}

void Game::clearGrid()
{
	for (int i = 0; i < 50; i++)
		for (int k = 0; k < 50; k++)
			grid[i][k].setObject(NULL);
}