/*
�⺻ ���̵�� : 
'���� Ȯ���� ���� ä��� �����ϰ� 
ä��� �����ϰ� �ݺ��ϸ� �ϼ� ���� ������?'

++++
�˻��� �ϴ� ���� (�� �˻� �ƴ�)
�ݵ�� ������ �����ϰ� Ǯ��� �ϴ� ��찡 �ִٴ� �� �˰� �ƴ�.
�̷� ��찡 ����� �������� (== Ȯ�� ���ڰ� �����ϴ� ������)
���� �⺻ ���̵���� �������ϰ�
�� �ں��ʹ� ������ ���� Ʈ���� Ǯ��Ҵ�.
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
	//�ϴ� pop �ϰ� �� ���ڸ� ������ �ִ´�.
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
	//0�� ��ǥ���� ����
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

	//�Է� �޴´�
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
