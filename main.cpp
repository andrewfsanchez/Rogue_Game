#include "Game.h"

int main()
{
    int diff;
    cout << "Choose your difficulty: \n 1. Easy\n 2. Normal\n 3. Hard\n";

    cin >> diff;
    if (!cin || diff > 3 || diff < 1)
    {
        cout << "Invalid option. Choose 1, 2, or 3. \n";
        cin.clear();
        cin.ignore();
    }

    while (!cin || diff > 3 || diff < 1);



    if (diff == 1)
        cout << "Easy Difficulty. Enter \"go\" to continue: ";
    else if (diff == 2)
        cout << "Normal Difficulty. Enter \"go\" to continue: ";
    else
        cout << "Hard Difficulty. Enter \"go\" to continue: ";

    string nothing;
    

	bool check = true;
	while (check)
	{
		cin >> nothing;

		if (noting.compare("go") == 0)
		{
			check = false;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "Enter \"go\" to continue: ";

		}
	}

    Game game = Game(diff);

    game.startGame();

    return 0;
}
