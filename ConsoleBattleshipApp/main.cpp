#include "Battleship_test.h"

void playGame()
{
	int turnx = -1, turny = -1;
	Battleship game = Battleship();

	while (turnx != 0 || turny != 0 && !game.win())
	{
		cout << "Сделайте ход (0, 0 - выход):" << endl;
		cin >> turnx >> turny;
		game.turn(turnx, turny);
	}
}

int main()
{
	setlocale(0, "rus");
	playGame();
	system("pause");
	return 0;
}