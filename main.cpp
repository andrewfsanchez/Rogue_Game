#include "Game.h"

bool AI = false;
int main()
{
	int diff;
	cout << "Choose your difficulty: \n 1. Easy\n 2. Normal\n 3. Hard\n";

	cin >> diff;
	while (!cin || diff > 3 || diff < 1)
	{
		cout << "Invalid option. Choose 1, 2, or 3. \n";
		cin.clear();
		cin.ignore();
		cin >> diff;
	}



	if (diff == 1)
		cout << "Easy Difficulty. Enter \"go\" to continue or \"AI\" to watch the AI player do it: ";
	else if (diff == 2)
		cout << "Normal Difficulty. Enter \"go\" to continue or \"AI\" to watch the AI player do it: ";
	else
		cout << "Hard Difficulty. Enter \"go\" to continue or \"AI\" to watch the AI player do it: ";

	string nothing;


	bool check = true;
	while (check)
	{
		cin >> nothing;

		if (nothing.compare("go") == 0)
		{
			check = false;
			AI = false;
		}
		else if (nothing.compare("AI") == 0 || nothing.compare("ai") == 0)
		{
			check = false;
			AI = true;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "Enter \"go\" to continue: ";

		}
	}

	Game game = Game(diff);
	if (AI == true)
		game.setAI(AI);
	else if (AI == false)
		game.setAI(AI);

	game.startGame();

	return 0;
}
