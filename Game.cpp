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
	floor = 1;
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
	clearGrid();

	level.dungeonBuild(grid, player, x);

	level.addEnemiesToMap(grid, difficulty, enemies, floor);

	printGrid();
	playerAction();
}

void Game::makeNextLevel()
{

	clearGrid();

	level.dungeonBuild(grid, player, x);

	level.addEnemiesToMap(grid, difficulty, enemies, floor);

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
	for (std::vector<Enemy>::size_type i = 0; i != enemies.size(); i++)
	{
		if (enemies[i].getType() == 1)
		{
			int direction = enemies[i].getDirection();
			Node target = grid[enemies[i].getY()][enemies[i].getX()];
			switch (direction)
			{
			case 0:   // up
				target = grid[enemies[i].getY() - 1][enemies[i].getX()];

				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setY(enemies[i].getY() - 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();
				break;

			case 1:   //right
				target = grid[enemies[i].getY()][enemies[i].getX() + 1];
				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setX(enemies[i].getX() + 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();
				break;

			case 2:  // down
				target = grid[enemies[i].getY() + 1][enemies[i].getX()];
				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setY(enemies[i].getY() + 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();
				break;

			case 3: // left
				target = grid[enemies[i].getY()][enemies[i].getX() - 1];
				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setX(enemies[i].getX() - 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();	
				break;
			}
		}
		/*
		else if (enemies[i].getType() == 2)
		{
			if (17 > enemies[i].getX() && 17 > enemies[i].getY())
			{
				if (abs(17 - enemies[i].getX()) > abs(17 - enemies[i].getY()))
				{
					Node target = grid[enemies[i].getX() + 1][enemies[i].getY()];
					
					if (target.getObject() != NULL) {
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setY(enemies[i].getY() + 1);
							break;
						}
						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setX(enemies[i].getX() + 1);
						break;
					}
				}
				else if (abs(17 - enemies[i].getX()) < abs(17 - enemies[i].getY()))
				{
					Node target = grid[enemies[i].getX()][enemies[i].getY() + 1];

					if (target.getObject() != NULL)
					{
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setX(enemies[i].getX() + 1);
							break;
						}
						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setY(enemies[i].getY() + 1);
						break;
					}
				}
			}
			else if (17 < enemies[i].getX() && 17 > enemies[i].getY())
			{
				if (abs(17 - enemies[i].getX()) > abs(17 - enemies[i].getY()))
				{
					Node target = grid[enemies[i].getX() - 1][enemies[i].getY()];

					if (target.getObject() != NULL)
					{
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setY(enemies[i].getY() + 1);
							break;
						}
						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setX(enemies[i].getX() - 1);
						break;
					}
				}

				else if (abs(17 - enemies[i].getX()) < abs(17 - enemies[i].getY()))
				{
					Node target = grid[enemies[i].getX()][enemies[i].getY() + 1];

					if (target.getObject() != NULL)
					{
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setX(enemies[i].getX() - 1);
							break;
						}
						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setY(enemies[i].getY() + 1);
						break;
					}
				}
			}
			else if (17 > enemies[i].getX() && 17 < enemies[i].getY())
			{
				if (abs(17 - enemies[i].getX()) > abs(17 - enemies[i].getY()))
				{
					Node target = grid[enemies[i].getX() + 1][enemies[i].getY()];
					if (target.getObject() != NULL)
					{
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setY(enemies[i].getY() - 1);
							break;
						}

						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setX(enemies[i].getX() + 1);
						break;
					}
				}

				else if (abs(17 - enemies[i].getX()) < abs(17 - enemies[i].getY()))
				{
					Node target = grid[enemies[i].getX()][enemies[i].getY() - 1];

					if (target.getObject() != NULL)
					{
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setX(enemies[i].getX() + 1);
							break;
						}
						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setY(enemies[i].getY() - 1);
						break;
					}
				}
			}
			else if (17 < enemies[i].getX() && 17 < enemies[i].getY())
			{
				if (abs(17 - enemies[i].getX()) > abs(17 - enemies[i].getY()))
				{
					Node target = grid[enemies[i].getX() - 1][enemies[i].getY()];

					if (target.getObject() != NULL)
					{
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setY(enemies[i].getY() - 1);
							break;
						}
						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setX(enemies[i].getX() - 1);
						break;
					}
				}

				else if (abs(17 - enemies[i].getX()) < abs(17 - enemies[i].getY()))

				{
					Node target = grid[enemies[i].getX()][enemies[i].getY() - 1];

					if (target.getObject() != NULL)
					{
						if (target.getObject()->isItem() || target.getObject()->isWall())
						{
							enemies[i].setX(enemies[i].getX() - 1);
							break;
						}
						else if (target.getObject()->isPlayer())
						{
							target.getObject()->takeDamage(enemies[i].getAttack());
						}
					}
					else
					{
						enemies[i].setY(enemies[i].getY() - 1);
						break;
					}
				}
			}
		}
		*/
		else if (enemies[i].getType() == 3)
		{
			int direction = enemies[i].getDirection();
			Node target = grid[enemies[i].getY()][enemies[i].getX()];
			switch (direction)
			{
			case 0:   // up
				target = grid[enemies[i].getY() - 1][enemies[i].getX()];

				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setY(enemies[i].getY() - 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();
				break;

			case 1:   //right
				target = grid[enemies[i].getY()][enemies[i].getX() + 1];
				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setX(enemies[i].getX() + 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();
				break;

			case 2:  // down
				target = grid[enemies[i].getY() + 1][enemies[i].getX()];
				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setY(enemies[i].getY() + 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();
				break;

			case 3: // left
				target = grid[enemies[i].getY()][enemies[i].getX() - 1];
				if (target.getObject() == NULL)
				{
					grid[enemies[i].getY()][enemies[i].getX()].deleteObject();
					enemies[i].setX(enemies[i].getX() - 1);
					grid[enemies[i].getY()][enemies[i].getX()].setObject(&enemies[i]);
				}
				else if (target.getObject()->isPlayer())
				{
					target.getObject()->takeDamage(enemies[i].getAttack());
				}
				else if (target.getObject()->isWall() || target.getObject()->isItem() || target.getObject()->isEnemy() || target.getObject()->isExit())
					enemies[i].reverseDirection();	
				break;
			}
		}
	}
}

/*void Game::eraseEnemies()
{

	for (int i = enemies.size() - 1; i >= 0; i--)
	{
	delete &enemies[i];                    // Unsure if this line is necessary based on how we implemented the Vector
	enemies.erase(enemies.begin() + i);
	}
}*/

void Game::playerAction() 
{
	bool check = true;
	while (check)
	{
		string input="";
		cout << "Current Health: "<<player->getHealth()<<"\n";
		cout << "Player Level: " << player->getLevel() << endl;
		cout << "Exp to Next Level: " << player->getExp() << endl;
		if (AI == true)
		{
			string cont;
			bool loop = true;
			while (loop)
			{
				cout << "Press 'C' to continue or 'X' to quit AI movement" << endl;
				cin >> cont;
				if (cont.compare("C") == 0 || cont.compare("c") == 0)
					loop = false;
				else if (cont.compare("X") == 0 || cont.compare("x") == 0)
				{
					AI = false;
					loop = false;
				}
				else
					continue;
			}
		}
		cout << "What will you do? (M= move, D= drop item, U= use item, W= wait, Q= quit game)";
		if (AI == true)
		{
			cout << " m " << endl;
			input = "m";
		}
		else
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
				check = false;
				cout << "Successfully quit game.\n";
			}
		}
		else
			cout << "Enter a valid command.\n";
	}
}

void Game::updateGrid()
{

	//deletes dead enemies from vector<enemy>

	for (std::vector<Enemy>::size_type i = 0; i != enemies.size(); i++)
	{

		if (enemies[i].getHealth() < 1)
		{
			// delete &enemies[i];  Unsure if this line is necessary based on how we implemented the Vector
			enemies.erase (enemies.begin()+i);
		}

	}

	
	moveEnemies();

	if (player->getHealth()<1) //if player is dead, game over
	{
		gameOver();
	}
	else
	{
		player->regeneration();       //keeps going until
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

	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << i << ". " << inventory[i].getName()<<"\n";
	}

	unsigned int index;
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


	for (unsigned int i = 0; i < inventory.size(); i++)
	{
		cout << i << ". " << inventory[i].getName() << "\n";
	}

	unsigned int index;
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
	bool check = true;
	while (check)
	{
		cout << "Where do you want to move? (U= up, D= down, R= right, L= left): ";
		string input = "";
		if (AI == true)
			input = "AI";
		else 
			cin >> input;
			
		cout << endl;
		

		if (input.compare("U") == 0 || input.compare("u") == 0)
		{
			check = false;
			
			
			Node target=grid[player->getY() - 1][player->getX()];
			if (target.getObject() == NULL)
			{
				grid[player->getY()][player->getX()].deleteObject();
				player->setY(player->getY()-1);
				grid[player->getY()][player->getX()].setObject(player);
				
			}
			else if(target.getObject()->isEnemy())
			{

				target.getObject()->takeDamage(player->getAttack());
				if (target.getObject()->getHealth() < 1)
					cout << "Enemy Health: " << 0 << endl;
				else
					cout << "Enemy Health: " << target.getObject()->getHealth() << endl;
				if (target.getObject()->getHealth() <= 0)
				{
					player->addExp(target.getObject()->getExperience());
					grid[player->getY() - 1][player->getX()]=Node();
				}
			}
			else if (target.getObject()->isExit())
			{
				floor++;
				player->setX(15);
				player->setY(15);
				makeNextLevel();
			}
			else if (target.getObject()->isItem())
			{
				cout << "Found an item.\n";
				Item x = Item(target.getObject()->getName(), target.getObject()->getHealthMod(), target.getObject()->getDefenseMod(), target.getObject()->getAttackMod(), target.getObject()->getRegenMod(), target.getObject()->isWeapon(), target.getObject()->isArmor(), target.getObject()->isConsumable());
				inventory.push_back(x);

				grid[player->getY()][player->getX()] = Node();
				player->setY(player->getY() - 1);
				grid[player->getY()][player->getX()].setObject(player);

			}
			else if (target.getObject()->getSymbol().compare(" # ") == 0)
			{
				check = false;
			}
			
		}
		else if (input.compare("D") == 0 || input.compare("d") == 0)
		{
			check = false;
			Node target = grid[player->getY() + 1][player->getX()];
			if (target.getObject() == NULL)
			{
				grid[player->getY()][player->getX()]= Node();
				player->setY(player->getY()+1);
				grid[player->getY()][player->getX()].setObject(player);
			}
			else if (target.getObject()->isEnemy())
			{
				target.getObject()->takeDamage(player->getAttack());
				if (target.getObject()->getHealth() < 1)
					cout << "Enemy Health: " << 0 << endl;
				else
					cout << "Enemy Health: " << target.getObject()->getHealth() << endl;
				if (target.getObject()->getHealth() <= 0)
				{
					player->addExp(target.getObject()->getExperience());
					grid[player->getY() + 1][player->getX()] = Node();
				}
			}
			else if (target.getObject()->isExit())
			{
				floor++;
				player->setX(15);
				player->setY(15);
				makeNextLevel();
			}
			else if (target.getObject()->isItem())
			{
				Item x = Item(target.getObject()->getName(), target.getObject()->getHealthMod(), target.getObject()->getDefenseMod(), target.getObject()->getAttackMod(), target.getObject()->getRegenMod(), target.getObject()->isWeapon(), target.getObject()->isArmor(), target.getObject()->isConsumable());
				inventory.push_back(x);

				grid[player->getY()][player->getX()] = Node();
				player->setY(player->getY() + 1);
				grid[player->getY()][player->getX()].setObject(player);

			}
			else if (target.getObject()->getSymbol().compare(" # ")==0)
			{
				check = false;
				cout << "You hit a wall.\n";
			}
			

		}
		else if (input.compare("L") == 0 || input.compare("l") == 0)
		{
			check = false;
			Node target = grid[player->getY()][player->getX()-1];
			if (target.getObject() == NULL)
			{
			grid[player->getY()][player->getX()]= Node();
			player->setX(player->getX()-1);
			grid[player->getY()][player->getX()].setObject(player);
			}
			else if (target.getObject()->isEnemy())
			{

				target.getObject()->takeDamage(player->getAttack());
				if (target.getObject()->getHealth() < 1)
					cout << "Enemy Health: " << 0 << endl;
				else
					cout << "Enemy Health: " << target.getObject()->getHealth() << endl;
				if (target.getObject()->getHealth() <= 0)
				{
					player->addExp(target.getObject()->getExperience());
					grid[player->getY()][player->getX() - 1] = Node();
				}
			}
			else if (target.getObject()->isExit())
			{
				floor++;
				player->setX(15);
				player->setY(15);
				makeNextLevel();
			}
			else if (target.getObject()->isItem())
			{
				Item x = Item(target.getObject()->getName(), target.getObject()->getHealthMod(), target.getObject()->getDefenseMod(), target.getObject()->getAttackMod(), target.getObject()->getRegenMod(), target.getObject()->isWeapon(), target.getObject()->isArmor(), target.getObject()->isConsumable());
				inventory.push_back(x);

				grid[player->getY()][player->getX()] = Node();
				player->setX(player->getX() - 1);
				grid[player->getY()][player->getX()].setObject(player);
			}
			else if (target.getObject()->getSymbol().compare(" # ") == 0)
			{
				check = false;
				cout << "You hit a wall.\n";
			}

		}
		else if (input.compare("R") == 0 || input.compare("r") == 0)
		{
			check = false;
			Node target = grid[player->getY()][player->getX() + 1];
			if (target.getObject() == NULL)
			{
				grid[player->getY()][player->getX()] = Node();
				player->setX(player->getX() + 1);
				grid[player->getY()][player->getX()].setObject(player);
			}
			else if (target.getObject()->isEnemy())
			{

				target.getObject()->takeDamage(player->getAttack());
				if (target.getObject()->getHealth() < 1)
					cout << "Enemy Health: " << 0 << endl;
				else
					cout << "Enemy Health: " << target.getObject()->getHealth() << endl;
				if (target.getObject()->getHealth() <= 0)
				{
					player->addExp(target.getObject()->getExperience());
					grid[player->getY()][player->getX() + 1] = Node();
				}
			}
			else if (target.getObject()->isExit())
			{
				floor++;
				player->setX(15);
				player->setY(15);
				makeNextLevel();
			}
			else if (target.getObject()->isItem())
			{
				

				Item x = Item(target.getObject()->getName(), target.getObject()->getHealthMod(), target.getObject()->getDefenseMod(), target.getObject()->getAttackMod(), target.getObject()->getRegenMod(), target.getObject()->isWeapon(), target.getObject()->isArmor(), target.getObject()->isConsumable());
				inventory.push_back(x);

				grid[player->getY()][player->getX()] = Node();
				player->setX(player->getX() - 1);
				grid[player->getY()][player->getX()].setObject(player);
			}
			else if (target.getObject()->getSymbol().compare(" # ") == 0)
			{
				check = false;
				cout << "You hit a wall.\n";
			}
		}
		//else if (input.compare("A") == 0 || input.compare("a") == 0)
		else if (input == "AI")
		{
			check = false;
			int lengthX = x->getX() - player->getX();
			int lengthY = x->getY() - player->getY();
			cout << "LengthX: " << lengthX << "LengthY: " << lengthY << endl;
			
			if (lengthY < 0 && player->getX() - x->getX() == -1)
			{
				player->setX(15);
				player->setY(15);
				makeNextLevel();
			}
			
			if (lengthY<=lengthX)
			{
				if (grid[player->getY()][player->getX() + 1].getObject() != NULL)
				{
					if (grid[player->getY()][player->getX() + 1].getObject()->isEnemy())
					{  
						Node target = grid[player->getY()][player->getX() + 1];

						target.getObject()->takeDamage(player->getAttack());
						if (target.getObject()->getHealth() < 1)
							cout << "Enemy Health: " << 0 << endl;
						else
							cout << "Enemy Health: " << target.getObject()->getHealth() << endl;
						if (target.getObject()->getHealth() <= 0)
						{
							player->addExp(target.getObject()->getExperience());
							grid[player->getY()][player->getX() + 1] = Node();
						}
					}
					else if (grid[player->getY()][player->getX() + 1].getObject()->isWall())
					{
						grid[player->getY()][player->getX()] = Node();
						player->setY(player->getY() + 1);
						grid[player->getY()][player->getX()].setObject(player);
					}	
					else if (grid[player->getY()][player->getX() + 1].getObject()->isExit())
					{
						floor++;
						player->setX(15);
						player->setY(15);
						makeNextLevel();
					}
				}
				else
				{
					grid[player->getY()][player->getX()] = Node();
					player->setX(player->getX() + 1);
					grid[player->getY()][player->getX()].setObject(player);
				}
			} 
			else if (lengthX == 0 || lengthY == 0)
			{
				floor++;
				player->setX(15);
				player->setY(15);
				makeNextLevel();
			}
			else if (lengthY < 0)
			{
				grid[player->getY()][player->getX()] = Node();
				player->setY(player->getY() + 1);
				grid[player->getY()][player->getX()].setObject(player);
			}
			else
			{
				if (lengthX <= lengthY)
				{
					if (grid[player->getY() + 1][player->getX()].getObject() != NULL)
					{
						if (grid[player->getY() + 1][player->getX()].getObject()->isEnemy())
						{
							Node target = grid[player->getY() + 1][player->getX()];

							target.getObject()->takeDamage(player->getAttack());
							if (target.getObject()->getHealth() < 1)
								cout << "Enemy Health: " << 0 << endl;
							else
								cout << "Enemy Health: " << target.getObject()->getHealth() << endl;
							if (target.getObject()->getHealth() <= 0)
							{
								player->addExp(target.getObject()->getExperience());
								grid[player->getY() + 1][player->getX()] = Node();
							}
						}
						else if (grid[player->getY() + 1][player->getX()].getObject()->isWall())
						{
							grid[player->getY()][player->getX()] = Node();
							player->setX(player->getX() + 1);
							grid[player->getY()][player->getX()].setObject(player);
						}
					}
					else
					{
						grid[player->getY()][player->getX()] = Node();
						player->setY(player->getY() + 1);
						grid[player->getY()][player->getX()].setObject(player);		
					}
				}
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
				cout << "Easy Difficulty. Enter 'go' to continue: ";
			else if (difficulty == 2)
				cout << "Normal Difficulty. Enter 'go' to continue: ";
			else
				cout << "Hard Difficulty. Enter 'go' to continue: ";
			
			string nothing;
			cin >> nothing;

			startGame();


		}
		else
			cout << "Invalid Option.\n";
	}

}
void Game::setAI(bool ai)
{
	AI = ai;
}
