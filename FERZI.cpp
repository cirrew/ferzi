#include <iostream>
using namespace std;
int m[8][8];
int z;
void output()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << m[i][j]<<' ';
		}
		cout << endl;
	}
	cout << endl;
}
int ifqueen(int y, int x)
{
	for (int i = 0; i < y; ++i)
	{
		if (m[i][x])
			return 0;
	}
	for (int i = y + 1; i < 8; i++)
	{
		if (m[i][x])
			return 0;
	}
	for (int i = 1; (i <= y) && (x - i >= 0); ++i)
	{
		if (m[y - i][x - i])
			return 0;
	}
	for (int i = 1; (i <= y) && (x + i < 8); i++)
	{
		if (m[y - i][x + i])
			return 0;
	}
	return 1;
}
int placequeen(int y)
{
	cout << "Вхождение №" <<z<< endl;
	z++;
	output();
	if (y == 8)
	{
		return 1;
	}
	for (int i=0;i<8;i++)
		if (ifqueen(y, i)==1)
		{
			m[y][i] = 1;
			if (placequeen(y + 1))
				return 1;
			m[y][i] = 0;
		}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	z = 1;
	placequeen(0);
	cout << "Результат" << endl;
	output();
	return 0;
}