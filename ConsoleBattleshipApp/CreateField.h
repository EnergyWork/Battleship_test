#include "libs.h"
#define N 12

class CreateField {
private:
	char A[N][N];
	int k = 0, x, y, p, q, pos;

	void setfield()
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < 100; i++)
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
							cout << A[i][j] << " ";
					}
					cout << endl;
				}
				break;
			}
		}
	}
public:
	CreateField()
	{
		setfield();
	}
	~CreateField()
	{

	}
	char getcell(int x, int y) { return A[x][y]; }
	void setcell(int x, int y, char s) { A[x][y] = s; }
};