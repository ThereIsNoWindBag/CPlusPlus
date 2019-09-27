#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int N, K;
int tmp, sum;

int main()
{
	scanf("%d%d", &N, &K);

	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &tmp);
		sum += ((tmp / 2) + tmp % 2);
	}

	printf(sum >= N ? "YES" : "NO");

	return 0;
}