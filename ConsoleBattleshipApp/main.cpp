#include "Battleship_test.h"

void win()
{
	cout << "������!" << endl;
}

void playGame()
{
	int turnx = -1, turny = -1;
	Battleship game = Battleship();

	while (turnx != 0 || turny != 0)
	{
		cout << "\n���������� �����: " << game.getcountTurns() << endl;
		cout << "�������� ��� (0, 0 - �����):" << endl;
		cin >> turnx >> turny;
		if (turnx < 0 || turnx > 10 || turny < 0 || turny > 10)
		{
			cout << "������!" << endl;
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