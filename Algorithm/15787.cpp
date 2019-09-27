#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int map[100000];
int N, M, tmp, tmp2;
int answer = 0;

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &tmp);
		switch (tmp)
		{
		case 1:
			scanf("%d%d", &tmp, &tmp2);
			map[tmp - 1] |= (1 << (20 - tmp2));
			break;
		case 2:
			scanf("%d%d", &tmp, &tmp2);
			map[tmp - 1] &= ~(1 << (20 - tmp2));
			break;
		case 3:
			scanf("%d", &tmp);
			map[tmp - 1] &= 0x000FFFFF;
			map[tmp - 1] = map[tmp - 1] >> 1;
			break;
		case 4:
			scanf("%d", &tmp);
			map[tmp - 1] = map[tmp - 1] << 1;
			map[tmp - 1] &= 0x000FFFFF;
			break;
		default:
			break;
		}
	}

	bool flag;
	for (int i = 0; i < N; ++i)
	{
		flag = true;
		for (int j = 0; j < i; ++j)
		{
			if (!(map[i] ^ map[j]))
			{
				flag = false;
				break;
			}
		}
		if (flag) answer++;
	}

	printf("%d", answer);

	return 0;
}