#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

long long map[500][500], tmp, sum;
int N, row;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%lld", &tmp);
			map[i][j] = tmp;
		}
	}

	long long *p;
	for (int i = 0; i < N; ++i)
	{
		p = find(map[i], map[i]+N, 0);
		if (p != map[i] + N)
		{
			row = i;
			break;
		}
	}

	sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += map[row][i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%lld", map[i][j]);
		}
	}

	return 0;
}