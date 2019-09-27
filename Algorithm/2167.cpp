#include <iostream>

using namespace std;

int N, M, tmp, K, x, y, X, Y, sum = 0;
int arr[300][300];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	cin >> K;
	for (int i = 0; i < K; ++i, sum = 0)
	{
		cin >> x >> y >> X >> Y;

		for (int j = x - 1; j < X; ++j)
		{
			for (int k = y - 1; k < Y; ++k)
			{
				sum += arr[j][k];
			}
		}

		cout << sum << "\n";
	}

	return 0;
}