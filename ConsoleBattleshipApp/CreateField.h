#include "libs.h"
#define sizeFld 12

class CreateField {
private:
	char fld[sizeFld][sizeFld];
	int k = 0, x, y, p, q, pos;
	
	void printField()
	{
		for (int i = 1; i < sizeFld - 1; i++)
		{
			for (int j = 1; j < sizeFld - 1; j++)
			{
				cout << fld[i][j] << " ";
			}
			cout << endl;
		}
	}
	void setfield()
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < 100; i++)
		{
			for (int i = 0; i < sizeFld; i++)
			{
				for (int j = 0; j < sizeFld; j++)
				{
					fld[i][j] = '?';
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
							if (fld[x - 1][y + i] == '?')
								k++;
							if (fld[x + 1][y + i] == '?')
								k++;
						}
						if (fld[x][y + 4 - t1] == '?')
							k++;
						if (fld[x][y - 1] == '?')
							k++;
						if (k == 14 - t2)
						{
							for (int i = 0; i < 4 - t1; i++)
							{
								fld[x][y + i] = '#';
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
							if (fld[x + i][y - 1] == '?')
								k++;
							if (fld[x + i][y + 1] == '?')
								k++;
						}
						if (fld[x - 1][y] == '?')
							k++;
						if (fld[x + 4 - t1][y] == '?')
							k++;
						if (k == 14 - t2)
						{
							for (int i = 0; i < 4 - t1; i++)
							{
								fld[x + i][y] = '#';
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
			for (int i = 1; i < sizeFld - 1; i++)
			{
				for (int j = 1; j < sizeFld - 1; j++)
				{
					if (fld[i][j] == '#')
					{
						q++;
					}
				}
			}
			if (q == 20)
			{
				printField();
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
	char getcell(int x, int y) { return fld[x][y]; }
	void setcell(int x, int y, char s) { fld[x][y] = s; }
};