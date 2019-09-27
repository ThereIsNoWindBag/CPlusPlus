#include <iostream>

using namespace std;

bool **map;

int a, b, c, d;
int x, y;
int lMax{ 0 }, rMax{ 0 }, uMax{ 0 }, dMax{ 0 };

int main()
{
	cin >> a >> b >> c >> d;
	lMax = a; uMax = b;
	a++; b++;

	map = new bool*[a] { false };
	for (int i = 0; i < a; ++i)
	{
		map[i] = new bool[b] { false };
	}

	for (int i = 0; i < c; ++i)
	{
		cin >> x >> y;
		map[x][y] = true;

		if (x < lMax) lMax = x;
		if (rMax < x) rMax = x;
		if (y < uMax) uMax = y;
		if (y > dMax) dMax = y;
	}

	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}

	int G{ rMax - lMax }, S{ dMax - uMax };

	G -= d; S -= d;

	for (int i = 0; i <= G; ++i)
	{
		for (int j = 0; j <= S; ++j)
		{

		}
	}
}