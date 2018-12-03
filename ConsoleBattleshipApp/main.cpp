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
	/*srand((unsigned)time(NULL));*/

	/*char A[N][N];*/

	/*int k = 0, x, y, p, q, pos;
	int L, K, i, j;
	int a, b;
	int coordx, coordy;
	int turnx = -1, turny = -1;*/

	/*for (int i = 0; i < 100; i++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				A[i][j] = '?';
			}
		}
		for (int t1 = 0, t2 = 0; t1 < 4, t2 < 8; t1++, t2 += 2)
		{
			p = 0;
			while (k != (14 - t2))
			{
				pos = 1 + rand() % 2;
				if (pos == 1)
				{
					x = 1 + rand() % 10;
					y = 1 + rand() % (7 + t1);
					k = 0;
					for (int i = -1; i <= 4 - t1; i++)
					{
						if (A[x - 1][y + i] == '?')
							k++;
						if (A[x + 1][y + i] == '?')
							k++;
					}
					if (A[x][y + 4 - t1] == '?')
						k++;
					if (A[x][y - 1] == '?')
						k++;
					if (k == 14 - t2)
					{
						for (int i = 0; i < 4 - t1; i++)
						{
							A[x][y + i] = '#';
						}
						p++;
					}
				}
				if (pos == 2)
				{
					x = 1 + rand() % (7 + t1);
					y = 1 + rand() % 10;
					k = 0;
					for (int i = -1; i <= 4 - t1; i++)
					{
						if (A[x + i][y - 1] == '?')
							k++;
						if (A[x + i][y + 1] == '?')
							k++;
					}
					if (A[x - 1][y] == '?')
						k++;
					if (A[x + 4 - t1][y] == '?')
						k++;
					if (k == 14 - t2)
					{
						for (int i = 0; i < 4 - t1; i++)
						{
							A[x + i][y] = '#';
						}
						p++;
					}
				}
				k = 0;
				if (p == 1 + t1)
					break;
			}
		}
		q = 0;
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < N - 1; j++)
			{
				if (A[i][j] == '#')
				{
					q++;
				}
			}
		}
		if (q == 20)
		{
			for (int i = 1; i < N - 1; i++)
			{
				for (int j = 1; j < N - 1; j++)
				{
					if (A[i][j] == '#')
					{
						cout << A[i][j] << " ";
					}
					else
						cout << A[i][j] << " ";
				}
				cout << endl;
			}
			break;
		}
	}*/


	/*while ((turnx != 0) && (turny != 0))
	{
		cout << "Сделайте ход (0, 0 - для выхода):" << endl;
		cout << "Строка: ";
		cin >> turnx;
		cout << "Столбец: ";
		cin >> turny;
		if (A[turnx][turny] == '#')
			A[turnx][turny] = 'v';
		else if (A[turnx][turny] == 'v')
			A[turnx][turny] = 'v';
		else if (A[turnx][turny] == 'x')
			A[turnx][turny] = 'x';
		else
			A[turnx][turny] = '0';

		//Горизонтальный проход

		for (int K = 4, t = 14; K >= 1, t >= 8; K--, t -= 2)
		{
			L = 1;
			x = N - K;
			y = N - L;
			for (int b = 0; b < y + 1; b++)
			{
				for (int a = 0; a < x + 1; a++)
				{
					k = 0;
					for (i = b; i < L + b; i++)
					{
						for (j = a; j < K + a; j++)
						{
							if (A[i][j] == 'v')
								k++;
						}
					}
					if (k == L * K)
					{
						for (int x = 1; x < N - 1; x++)
						{
							for (int y = 1; y < N - 1; y++)
							{
								if (((x >= b) && (x < i)) && ((y >= a) && (y < j)))
								{
									coordx = b;
									coordy = a;
								}
							}
						}
						k = 0;
						for (int i = -1; i <= K; i++)
						{
							if (A[coordx - 1][coordy + i] == '?' || A[coordx - 1][coordy + i] == '0')
								k++;
							if (A[coordx + 1][coordy + i] == '?' || A[coordx + 1][coordy + i] == '0')
								k++;
						}
						if (A[coordx][coordy + K] == '?' || A[coordx][coordy + K] == '0')
							k++;
						if (A[coordx][coordy - 1] == '?' || A[coordx][coordy - 1] == '0')
							k++;
						if (k == t)
						{
							for (int i = 0; i < K; i++)
							{
								A[coordx][coordy + i] = 'x';
							}
						}
						break;
					}
				}
			}
		}

		//Вертикальный проход

		for (int L = 4, t = 14; L >= 1, t >= 8; L--, t -= 2)
		{
			K = 1;
			x = N - K;
			y = N - L;
			for (int b = 0; b < y + 1; b++)
			{
				for (int a = 0; a < x + 1; a++)
				{
					k = 0;
					for (i = b; i < L + b; i++)
					{
						for (j = a; j < K + a; j++)
						{
							if (A[i][j] == 'v')
								k++;
						}
					}
					if (k == L * K)
					{
						for (int x = 1; x < N - 1; x++)
						{
							for (int y = 1; y < N - 1; y++)
							{
								if (((x >= b) && (x < i)) && ((y >= a) && (y < j)))
								{
									coordx = b;
									coordy = a;
								}
							}
						}
						k = 0;
						for (int i = -1; i <= L; i++)
						{
							if (A[coordx + i][coordy - 1] == '?' || A[coordx + i][coordy - 1] == '0')
								k++;
							if (A[coordx + i][coordy + 1] == '?' || A[coordx + i][coordy + 1] == '0')
								k++;
						}
						if (A[coordx - 1][coordy] == '?' || A[coordx - 1][coordy] == '0')
							k++;
						if (A[coordx + L][coordy] == '?' || A[coordx + L][coordy] == '0')
							k++;
						if (k == t)
						{
							for (int i = 0; i < L; i++)
							{
								A[coordx + i][coordy] = 'x';
							}
						}
						break;
					}
				}
			}
		}

		system("cls");
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < N - 1; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
	}*/
	system("pause");
	return 0;
}