#include <iostream>
#include <queue>
using namespace std;

typedef struct _squre {
	int X, Y;
	int size;
	bool isFull;
} square;

int map[129][129];

int N, stdColor, cntW, cntB, tmp;

queue<square> q;

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	square org;

	org.X = 0;
	org.Y = 0;
	org.size = N;
	org.isFull = true;

	q.push(org);

	while (!q.empty())
	{
		square sq = q.front();
		q.pop();

		for (int i = sq.X; i < sq.X + sq.size; ++i)
		{
			stdColor = map[sq.X][sq.Y];
			for (int j = sq.Y; j < sq.Y + sq.size; ++j)
			{
				if (stdColor != map[i][j])
				{
					sq.isFull = false;
					break;
				}
			}
		}

		if (sq.isFull)
		{
			if (stdColor)
				cntB++;
			else
				cntW++;
		}
		else
		{
			q.push({ sq.X, sq.Y, sq.size / 2, true });
			q.push({ sq.X + (sq.size / 2), sq.Y, sq.size / 2, true });
			q.push({ sq.X, sq.Y + (sq.size / 2), sq.size / 2, true });
			q.push({ sq.X + (sq.size / 2), sq.Y + (sq.size / 2), sq.size / 2, true });
		}
	}
	
	cout << cntW << "\n" << cntB;
	
	return 0;
}