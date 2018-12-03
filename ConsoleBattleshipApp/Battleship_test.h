#include "libs.h"
#include "CreateField.h"

class Battleship {
private:
	int k = 0, x, y, p, q, pos;
	int L, K, i, j;
	int a, b;
	int coordx, coordy;
	CreateField field = CreateField();

	void printField()
	{
		system("cls");
		for (int i = 1; i < sizeFld - 1; i++)
		{
			for (int j = 1; j < sizeFld - 1; j++)
			{
				cout << field.getcell(i, j) << " ";
			}
			cout << endl;
		}
	}
public: 
	Battleship()
	{

	}
	~Battleship()
	{

	}

	void run()
	{

	}
	bool stop()
	{
		return false;
	}
	void turn(int turnx, int turny)
	{
		if (field.getcell(turnx, turny) == '#')
			field.setcell(turnx, turny, 'v');
		else if (field.getcell(turnx, turny) == 'v')
			field.setcell(turnx, turny, 'v');
		else if (field.getcell(turnx, turny) == 'x')
			field.setcell(turnx, turny, 'x');
		else
			field.setcell(turnx, turny, '0');

		//Горизонтальный проход

		for (int K = 4, t = 14; K >= 1, t >= 8; K--, t -= 2)
		{
			L = 1;
			x = sizeFld - K;
			y = sizeFld - L;
			for (int b = 0; b < y + 1; b++)
			{
				for (int a = 0; a < x + 1; a++)
				{
					k = 0;
					for (i = b; i < L + b; i++)
					{
						for (j = a; j < K + a; j++)
						{
							if (field.getcell(i, j) == 'v')
								k++;
						}
					}
					if (k == L * K)
					{
						for (int x = 1; x < sizeFld - 1; x++)
						{
							for (int y = 1; y < sizeFld - 1; y++)
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
							if (field.getcell(coordx - 1, coordy + i) == '?' || field.getcell(coordx - 1, coordy + i) == '0')
								k++;
							if (field.getcell(coordx + 1, coordy + i) == '?' || field.getcell(coordx + 1, coordy + i) == '0')
								k++;
						}
						if (field.getcell(coordx, coordy + K) == '?' || field.getcell(coordx, coordy + K) == '0')
							k++;
						if (field.getcell(coordx, coordy - 1) == '?' || field.getcell(coordx, coordy - 1) == '0')
							k++;
						if (k == t)
						{
							for (int i = 0; i < K; i++)
							{
								field.setcell(coordx, coordy + i, 'x');
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
			x = sizeFld - K;
			y = sizeFld - L;
			for (int b = 0; b < y + 1; b++)
			{
				for (int a = 0; a < x + 1; a++)
				{
					k = 0;
					for (i = b; i < L + b; i++)
					{
						for (j = a; j < K + a; j++)
						{
							if (field.getcell(i, j) == 'v')
								k++;
						}
					}
					if (k == L * K)
					{
						for (int x = 1; x < sizeFld - 1; x++)
						{
							for (int y = 1; y < sizeFld - 1; y++)
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
							if (field.getcell(coordx + i, coordy - 1) == '?' || field.getcell(coordx + i, coordy - 1) == '0')
								k++;
							if (field.getcell(coordx + i, coordy + 1) == '?' || field.getcell(coordx + i, coordy + 1) == '0')
								k++;
						}
						if (field.getcell(coordx - 1, coordy) == '?' || field.getcell(coordx - 1, coordy) == '0')
							k++;
						if (field.getcell(coordx + L, coordy) == '?' || field.getcell(coordx + L, coordy) == '0')
							k++;
						if (k == t)
						{
							for (int i = 0; i < L; i++)
							{
								field.setcell(coordx + 1, coordy, 'x');
							}
						}
						break;
					}
				}
			}
		}
		printField();
	}
};