#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int tmp1, tmp2;

int friendMap[105][105];
int sumOfThem[105];

int minV = 987654321;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			friendMap[i][j] = 1000000000;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		friendMap[i][i] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> tmp1 >> tmp2;
		friendMap[tmp1-1][tmp2-1] = 1;
		friendMap[tmp2-1][tmp1-1] = 1;
	}

	for (int q = 0; q < N; ++q)
	{
		for (int w = 0; w < N; ++w)
		{
			for (int r = 0; r < N; ++r)
			{
				if( friendMap[w][r] > friendMap[w][q] + friendMap[q][r])
				{
					friendMap[w][r] = friendMap[w][q] + friendMap[q][r];
					friendMap[r][w] = friendMap[w][r];
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		int sum = 0;

		for (int j = 0; j < N; ++j)
		{
			if(friendMap[i][j] != 1000000000)
				sum += friendMap[i][j];
		}
		
		sumOfThem[i] = sum;

		if (minV > sum)
		{
			minV = sum;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if(sumOfThem[i] == minV)
		{
			cout << i + 1;
			break;
		}
	}

	return 0;
}