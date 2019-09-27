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
using namespace std;

int sdoku[9][9];

int countOfZero{ 0 };

int tmp;

void searchHorizontal();
void searchVertical();
void searchSquare();

void doAssume();

void printSdoku();

int zeroNumHor[9];
int zeroNumVer[9];
int zeroNumSqr[3][3];

int hunt;

struct coord
{
	int x;
	int y;
};

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

	//0�� ������ ����
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

	while (!!countOfZero)
	{
		hunt = 0;
		searchHorizontal();
		searchVertical();
		searchSquare();
		if (hunt == 0)
			break;
	}

	doAssume();

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

void doAssume()
{
	vector<coord> v;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sdoku[i][j] == 0)
				v.push_back({ i, j });
		}
	}

}