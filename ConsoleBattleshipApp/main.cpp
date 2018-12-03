#include "libs.h"
#include "Battleship_test.h"
#include <Windows.h>

void playGame()
{
	int turnx = -1, turny = -1;
	Battleship game = Battleship();
	game.run();

	while (turnx != 0 || turny != 0)
	{
		cout << "Сделайте ход (0, 0 - для выхода):" << endl;
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