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
using namespace std;

struct coord
{
	int x;
	int y;
};

int sdoku[9][9];

int countOfZero{ 0 };

int tmp;

void searchHorizontal();
void searchVertical();
void searchSquare();

void doAssumeNow();
void checkPossibility();

void printSdoku();

int zeroNumHor[9];
int zeroNumVer[9];
int zeroNumSqr[3][3];

int hunt;

vector<coord> v;
stack<int> s;

bool odds[9];

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

	//0의 갯수를 센다
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sdoku[i][j] == 0)
			{
				zeroNumHor[i]++;
				zeroNumVer[j]++;
				zeroNumSqr[i / 3][j / 3]++;
				countOfZero++;
			}
		}
	}

	//일단 확정적인 것들을 구한다
	while (!!countOfZero)
	{
		hunt = 0;
		searchHorizontal();
		searchVertical();
		searchSquare();
		if (hunt == 0)
			break;
	}

	printSdoku();
}

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

void searchHorizontal()
{
	int zero, sum;

	for (int i = 0; i < 9; ++i)
	{
		if (zeroNumHor[i] == 1)
		{
			zero = 0;
			sum = 0;

			for (int j = 0; j < 9; ++j)
			{
				if (sdoku[i][j] == 0)
					zero = j;
				else
					sum += sdoku[i][j];
			}

			sdoku[i][zero] = 45 - sum;

			zeroNumHor[i]--;
			zeroNumVer[zero]--;
			zeroNumSqr[i / 3][zero / 3]--;
			countOfZero--;
			hunt++;
		}
	}
}

void searchVertical()
{
	int zero, sum;

	for (int i = 0; i < 9; ++i)
	{
		if (zeroNumVer[i] == 1)
		{
			zero = 0;
			sum = 0;

			for (int j = 0; j < 9; ++j)
			{
				if (sdoku[j][i] == 0)
					zero = j;
				else
					sum += sdoku[j][i];
			}

			sdoku[zero][i] = 45 - sum;

			zeroNumHor[zero]--;
			zeroNumVer[i]--;
			zeroNumSqr[zero / 3][i / 3]--;
			countOfZero--;
			hunt++;
		}
	}
}

void searchSquare()
{
	int sum;
	int zeroX, zeroY;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (zeroNumSqr[i][j] == 1)
			{
				sum = 0;

				int pHor = 3*i + 1;
				int pVer = 3*j + 1; 

				for (int x = -1; x < 2; ++x)
				{
					for (int y = -1; y < 2; ++y)
					{
						if (sdoku[pHor + x][pVer + y] == 0)
						{
							zeroX = pHor + x;
							zeroY = pVer + y;
						}
						else
							sum += sdoku[pHor + x][pVer + y];
					}
				}

				sdoku[zeroX][zeroY] = 45 - sum;

				zeroNumHor[zeroX]--;
				zeroNumVer[zeroY]--;
				zeroNumSqr[zeroX / 3][zeroY / 3]--;
				countOfZero--;
				hunt++;
			}
		}
	}
}

void doAssumeNow()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sdoku[i][j] == 0)
				v.push_back({ i, j });
		}
	}

	checkPossibility(v[0]);

	for (int i = 0; i < 9; ++i)
	{
		if (odds[i])
		{
			s.push(i + 1);
		}
	}

	dfs(1);
}

void checkPossibility(coord c)
{
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
			if (sdoku[1 + c.x/3 + x][1 + c.y/3 + y] != 0)
				odds[sdoku[1 + c.x / 3 + x][1 + c.y / 3 + y] - 1] = false;
		}
	}
}

void dfs(int val)
{
	sdoku[v[val - 1].x][v[val - 1].y] = s.top();
	s.pop();

	checkPossibility(v[val]);

	for (int i = 0; i < 9; ++i)
	{
		if (odds[i])
		{
			s.push(i + 1);
		}
	}

	dfs(val + 1);
}