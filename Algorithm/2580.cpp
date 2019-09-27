/*
기본 아이디어 : 
'수가 확정된 곳을 채우고 갱신하고 
채우고 갱신하고를 반복하면 완성 되지 않을까?'

++++
검색을 하던 도중 (답 검색 아님)
반드시 추측을 가정하고 풀어야 하는 경우가 있다는 걸 알게 됐다.
이런 경우가 생기기 전까지는 (== 확정 숫자가 존재하는 경우까지)
위의 기본 아이디어의 방법대로하고
그 뒤부터는 가정을 통한 트리로 풀어보았다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

struct coord
{
	int x;
	int y;
};

int sdoku[9][9];

int countOfZero{ 0 };

int tmp;

vector<coord> vCoord;
vector<int> vVal;
stack<pair<int, int>> s;

bool odds[9];

int layer;

bool done = false;

void printSdoku()
{
	cout << endl;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << sdoku[i][j] << " ";
		}
		cout << "\n";
	}
}

bool check()
{
	bool ret = true;

	int sum;

	for (int i = 0; i < 9; ++i)
	{
		sum = 0;
		for (int j = 0; j < 9; ++j)
		{
			sum += sdoku[i][j];
		}
		if (sum != 45)
		{
			ret = false;
			return ret;
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		sum = 0;
		for (int j = 0; j < 9; ++j)
		{
			sum += sdoku[j][i];
		}
		if (sum != 45)
		{
			ret = false;
			return ret;
		}
	}

	int XAxis, YAxis;

	for (int i = 0; i < 3; ++i)
	{
		XAxis = 1 + i * 3;
		for (int j = 0; j < 3; ++j)
		{
			YAxis = 1 + j * 3;

			sum = 0;
			for (int x = -1; x < 2; ++x)
			{
				for (int y = -1; y < 2; ++y)
				{
					sum += sdoku[XAxis + x][YAxis + y];
				}
			}
			if (sum != 45)
			{
				ret = false;
				return ret;
			}
		}
	}

	return ret;
}


void checkPossibility(int n)
{
	coord c = vCoord[n];

	for (int i = 0; i < 9; ++i)
	{
		odds[i] = true;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (sdoku[c.x][i] != 0)
			odds[sdoku[c.x][i] - 1] = false;
	}
	for (int i = 0; i < 9; ++i)
	{
		if (sdoku[i][c.y] != 0)
			odds[sdoku[i][c.y] - 1] = false;
	}
	for (int x = -1; x < 2; ++x)
	{
		for (int y = -1; y < 2; ++y)
		{
			if (sdoku[1 + 3 * (c.x / 3) + x][1 + 3 * (c.y / 3) + y] != 0)
				odds[sdoku[1 + 3 * (c.x / 3) + x][1 + 3 * (c.y / 3) + y] - 1] = false;
		}
	}
}

void DFS(int n)
{
	//일단 pop 하고 그 숫자를 스도쿠에 넣는다.
	pair<int, int> p = s.top();

	sdoku[vCoord[p.first].x][vCoord[p.first].y] = p.second;

	if (layer == n)
	{
		if (check())
		{
			printSdoku();
			done = true;
			return;
		}
		else
		{
			return;
		}
	}

	checkPossibility(n);

	int personalOdds[9];

	for (int i = 0; i < 9; ++i)
	{
		personalOdds[i] = odds[i];
	}

	for (int i = 0; i < 9; ++i)
	{
		if (personalOdds[i])
		{
			s.push(pair<int, int>{n, i + 1});
			DFS(n + 1);
			if (done)
				return;
			sdoku[vCoord[s.top().first].x][vCoord[s.top().first].y] = 0;
			s.pop();
		}
	}
}

void doDFS()
{
	//0인 좌표들을 따냄
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sdoku[i][j] == 0)
				vCoord.push_back({ i, j });
		}
	}

	layer = vCoord.size();

	checkPossibility(0);

	int personalOdds[9];

	for (int i = 0; i < 9; ++i)
	{
		personalOdds[i] = odds[i];
	}

	for (int i = 0; i < 9; ++i)
	{
		if (personalOdds[i])
		{
			s.push(pair<int, int>{0, i + 1});
			DFS(1);
			if (done)
				return;
			sdoku[vCoord[s.top().first].x][vCoord[s.top().first].y] = 0;
			s.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	//입력 받는다
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> tmp;
			sdoku[i][j] = tmp;
		}
	}

	doDFS();
}
