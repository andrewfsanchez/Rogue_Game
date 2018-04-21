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

/*void Game::makeLevel()
{
	clearGrid();
	floor++;
	int rooms = rand() % 4 + 3;
	int roomSize = 15 - rooms;
}
*/

void Game::playerAction() 
{
	bool check = true;
	while (check)
	{
		string input="";
		cout << "What will you do? (M= move, D= drop item, U= use item, W= wait, Q= quit game)";
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
		else if (input.compare("Q") == 0 || input.compare("q") == 0)
		{
			cout << "Are you sure you want to quit? (Y/N) ";
			string a="";
			cin >> a;
			if (a.compare("Y")==0||a.compare("y")==0)
			{
				deleteGrid();
				check = false;
				cout << "Successfully quit game.";
			}
		}
		else
			cout << "Enter a valid command.\n";
	}
}

void Game::updateGrid()
{
	/*if(player.getX()==exitX || player.getY()==exitY)
	{
		makeNextFloor(floor, diff, player);
		return;
	}
	*/


	//moveEnemies();

	if (player.getHealth()<1) 
	{
		gameOver();
	}
	else
	{
		playerAction();
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
	for (int i = 0; i < 30; i++)
		for (int k = 0; k < 30; k++)
			grid[i][k] = Node();
}

void Game::deleteGrid()
{
	for (int i = 0; i < 30; i++)
		for (int k = 0; k < 30; k++)
		{
			grid[i][k].deleteObject();
		}
}

void Game::playerDrop()
{
	vector<Item> inventory= player.getInventory();

	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i << ". " << inventory[i].getName();
	}
}



void Game::gameOver()
{
	cout << "                 uuuuuuu\n";
	cout << "             uu$$$$$$$$$$$uu\n";
	cout << "          uu$$$$$$$$$$$$$$$$$uu\n";
	cout << "         u$$$$$$$$$$$$$$$$$$$$$u\n";
	cout << "        u$$$$$$$$$$$$$$$$$$$$$$$u\n";
	cout << "       u$$$$$$$$$$$$$$$$$$$$$$$$$u\n";
	cout << "       u$$$$$$$$$$$$$$$$$$$$$$$$$u\n";
	cout << "       u$$$$$$\"   \"$$$\"   \"$$$$$$u\n";
	cout << "       \"$$$$\"      u$u       $$$$\"\n";
	cout << "        $$$u       u$u       u$$$\n";
	cout << "        $$$u      u$$$u      u$$$\n";
	cout << "         \"$$$$uu$$$   $$$uu$$$$\"\n";
	cout << "          \"$$$$$$$\"   \"$$$$$$$\"\n";
	cout << "            u$$$$$$$u$$$$$$$u\n";
	cout << "             u$\"$\"$\"$\"$\"$\"$u\n";
	cout << "  uuu        $$u$ $ $ $ $u$$       uuu\n";
	cout << " u$$$$        $$$$$u$u$u$$$       u$$$$\n";
	cout << "  $$$$$uu      \"$$$$$$$$$\"     uu$$$$$$\n";
	cout << "u$$$$$$$$$$$uu    \"\"\"\"\"    uuuu$$$$$$$$$$\n";
	cout << "$$$$\"\"\"$$$$$$$$$$uuu   uu$$$$$$$$$\"\"\"$$$\"\n";
	cout << " \"\"\"      \"\"$$$$$$$$$$$uu \"\"$\"\"\"\n";
	cout << "           uuuu \"\"$$$$$$$$$$uuu\n";
	cout << "  u$$$uuu$$$$$$$$$uu \"\"$$$$$$$$$$$uuu$$$\n";
	cout << "  $$$$$$$$$$\"\"\"\"           \"\"$$$$$$$$$$$\"\n";
	cout << "   \"$$$$$\"                      \"\"$$$$\"\"\n";
	cout << "     $$$\"                         $$$$\"\n\n";
	
	cout << "You were slain on floor "<< floor<< ".\n";
	bool check = true;
	while (check)
	{
		cout << "Play again? (Y/N) ";
		string a = "";
		cin >> a;
		if (a.compare("N") == 0 || a.compare("n") == 0)
		{
			deleteGrid();
			cout << "Successfully quit game.\n";
			check = false;
		}
		else if (a.compare("y") == 0 || a.compare("Y") == 0)
		{
			floor = 0;
			player = Player();
			clearGrid();
			int diff;
			do
			{
				cout << "Choose your difficulty: \n 1. Easy\n 2. Normal\n 3. Hard\n";
				
				cin >> diff;
				if (!cin || diff > 3 || diff < 1)
				{
					cout << "Invalid option. Choose 1, 2, or 3. \n";
					cin.clear();
					cin.ignore();
				}
				else
					difficulty = diff;
				
			} while (!cin || diff > 3 || diff < 1);

			check = false;

			if (difficulty == 1)
				cout << "Easy Difficulty. Enter anything to continue: ";
			else if (difficulty == 1)
				cout << "Normal Difficulty. Enter anything to continue: ";
			else
				cout << "Hard Difficulty. Enter anything to continue: ";
			
			string nothing;
			cin >> nothing;

			//makeNextFloor(floor, difficulty, player);


		}
		else
			cout << "Invalid Opiton.\n";
	}

}