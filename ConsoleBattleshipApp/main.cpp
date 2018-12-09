#include "Battleship_test.h"

void win()
{
	cout << "Победа!" << endl;
}

void playGame()
{
	int turnx = -1, turny = -1;
	Battleship game = Battleship();

	while (turnx != 0 || turny != 0)
	{
		cout << "\nКоличество ходов: " << game.getcountTurns() << endl;
		cout << "Сделайте ход (0, 0 - выход):" << endl;
		cin >> turnx >> turny;
		if (turnx < 0 || turnx > 10 || turny < 0 || turny > 10)
		{
			cout << "Ошибка!" << endl;
			continue;
		}		
		game.turn(turnx, turny);
		if (game.win()) win();
	}
}

int main()
{
	setlocale(0, "rus");
	playGame();
	system("pause");
	return 0;
}