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
	player= new Player();
	
	//Create some generic items
	Item potion = Item("Potion", 5,  0, 0, 0, false, false,true);
	Item katana = Item("Katana", 0, 0, 7, 0, true, false, false);
	Item oldShirt = Item("Old Shirt", 0, 2, 0, 0, false, true, false);
	
	//Add to item vector
	items.push_back(potion);
	items.push_back(katana);
	items.push_back(oldShirt);
	
	

	inventory.push_back(potion);
	inventory.push_back(katana);
	inventory.push_back(oldShirt);

	weapon = katana;
	armor = oldShirt;

	level = Dungeon();
}


void Game::startGame()
{
	level.dungeonBuild(grid, player);
	printGrid();
	playerAction();
}


/*void Game::makeLevel()
{
	clearGrid();
	floor++;
	int rooms = rand() % 4 + 3;
	int roomSize = 15 - rooms;
}
*/

void Game::moveEnemies()
{
	for (std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); ++it)
	{if

	}
	
}

void Game::eraseEnemies()
{
	for (int i = enemies.size() - 1; i >= 0; i--) enemies.erase(enemies.begin() + i);
}

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
			playerMove();
		}
		else if (input.compare("D")==0 || input.compare("d") == 0)
		{
			if (!inventory.empty())
			{
				check = false;
				playerDrop();
			}
			else
				cout << "Your inventory is empty.\n";
		}
		else if (input.compare("U") == 0 || input.compare("u") == 0)
		{
			if (!inventory.empty())
			{
				check = false;
				playerUseItem();
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
	/*if(player->getX()==exitX || player->getY()==exitY)
	{
		makeNextFloor(floor, diff, player);
		eraseEnemies();
		playerAction();
		return;
	}
	*/


	//moveEnemies();

	if (player->getHealth()<1) 
	{
		gameOver();
	}
	else
	{
		player->regeneration();
		printGrid();
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

	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i << ". " << inventory[i].getName()<<"\n";
	}

	int index;
	do {
		cout << "Choose the number of the item you want to drop: ";
		cin >> index;

		if (!cin || index > inventory.size() - 1 || index < 0)
		{
			cout << "Invalid input. \n";
		}
	} while (!cin);

	inventory.erase(inventory.begin() + index);

	updateGrid();
}

void Game::playerUseItem()
{


	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i << ". " << inventory[i].getName() << "\n";
	}

	int index;
	do {
		cout << "Choose the number of the item you want to use/equip: ";
		cin >> index;

		if (!cin || index > inventory.size() - 1 || index < 0)
		{
			cout << "Invalid input. \n";
		}
	} while (!cin);

	Item x = inventory[index];

	if (x.isWeapon())
		setWeapon(x, player);
	else if (x.isArmor())
		setArmor(x, player);
	else if (x.isConsumable())
	{
		useItem(x, player);
		inventory.erase(inventory.begin() + index);
	}


	updateGrid();
}
void Game::useItem(Item x, Object* p)
{
	p->setAttack(p->getAttack() + x.getAttackMod());
	p->setDefense( p->getDefense() + x.getDefenseMod());
	p->setHealth( p->getHealth() + x.getHealthMod());
	if (p->getHealth() > p->getMaxHealth())
		p->setHealth( p->getMaxHealth());
	p->setRegen( p->getRegen() + x.getRegenMod());


}

void Game::setWeapon(Item x, Object* p)
{
	p->setAttack(p->getAttack() - weapon.getAttackMod());
	p->setDefense(p->getDefense() - weapon.getDefenseMod());
	p->setHealth(p->getHealth() - weapon.getHealthMod());
	p->setRegen(p->getRegen() - weapon.getRegenMod());

	p->setAttack(p->getAttack() + x.getAttackMod());
	p->setDefense(p->getDefense() + x.getDefenseMod());
	p->setMaxHealth(p->getMaxHealth() + x.getMaxHealth());
	p->setRegen(p->getRegen() + x.getRegenMod());
}

void Game::setArmor(Item x, Object* p)
{
	p->setAttack(p->getAttack() - armor.getAttackMod());
	p->setDefense(p->getDefense() - armor.getDefenseMod());
	p->setHealth(p->getHealth() - armor.getHealthMod());
	p->setRegen(p->getRegen() - armor.getRegenMod());

	p->setAttack(p->getAttack() + x.getAttackMod());
	p->setDefense(p->getDefense() + x.getDefenseMod());
	p->setMaxHealth(p->getMaxHealth() + x.getMaxHealth());
	p->setRegen(p->getRegen() + x.getRegenMod());
}

void Game::playerMove()
{
	//Node currentLoc = grid[player.getX()][player.getY()];
	bool check = true;
	while (check)
	{
		cout << "Where do you want to move? (U= up, D= down, R= right, L= left): ";
		string input = "";
		cin >> input;
		if (input.compare("U") == 0 || input.compare("u") == 0)
		{
			check = false;
			
			
			Node target=grid[player->getX()][player->getY()-1];
			if (target.getObject() == NULL)
			{
				grid[player->getX()][player->getY()]= Node();
				player->setY(player->getY()-1);
				grid[player->getY()][player->getX()].setObject(player);
				target.deleteObject();
			}
			else if(target.getObject()->isEnemy())
			{
				target.getObject()->takeDamage(player->getAttack());
			}
			
		}
		else if (input.compare("D") == 0 || input.compare("d") == 0)
		{
			check = false;
			Node target = grid[player->getX()][player->getY() + 1];
			if (target.getObject() == NULL)
			{
			grid[player->getX()][player->getY()]= Node();
			player->setY(player->getY()+1);
			grid[player->getY()][player->getX()].setObject(player);
			}
			target.deleteObject();
			
		}
		else if (input.compare("L") == 0 || input.compare("l") == 0)
		{
			check = false;
			Node target = grid[player->getX()-1][player->getY()];
			if (target.getObject() == NULL)
			{
			grid[player->getX()][player->getY()]= Node();
			player->setY(player->getX()-1);
			grid[player->getY()][player->getX()].setObject(player);
			target.deleteObject();
			}
		}
		else if (input.compare("R") == 0 || input.compare("r") == 0)
		{
			check = false;
			Node target = grid[player->getX() + 1][player->getY()];
			if (target.getObject() == NULL)
			{
				grid[player->getX()][player->getY()] = Node();
				player->setY(player->getX() - 1);
				grid[player->getY()][player->getX()].setObject(player);
				target.deleteObject();
			}
		}
		else
			cout << "Invalid Direction. \n";
	}
	updateGrid();

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
			player = new Player();
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
			cout << "Invalid Option.\n";
	}

}
