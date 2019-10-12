#include <iostream>
#include <queue>
using namespace std;

int n, k;
int second, manner;

int minimum;

queue<pair<int, int>> q;

int findMinimum();
void findOne();

int main()
{
	cin >> n >> k;
	const int N = n, K = k;

	if (N == K)
	{
		cout << "0\n";
		cout << "1\n";
	}
	else if (N > K)
	{
		cout << K - N << '\n';
		cout << "1\n";
	}
	else
	{ 
		n = N;
		k = K;

		int v = n;
		q.push(pair<int, int>(v, 0));

		minimum = findMinimum();

		for (; !q.empty();)
		{
			q.pop();
		}

		q.push(pair<int, int>(v, 0));
		findOne();

		cout << minimum << '\n' << manner;
	}

	return 0;
}

int findMinimum()
{
	while (true)
	{
		pair<int, int> p = q.front();
		q.pop();

		int val = p.first;
		int sec = p.second;

		if (val * 2 == k)
		{
			return sec + 1;
		}
		else
		{
			q.push(pair<int, int>(val * 2, sec + 1));
		}

		if (val + 1 == k)
		{
			return sec + 1;
		}
		else
		{
			q.push(pair<int, int>(val + 1, sec + 1));
		}

		if (val - 1 == k)
		{
			return sec + 1;
		}
		else
		{
			q.push(pair<int, int>(val - 1, sec + 1));
		}
	}
}

void findOne()
{
	while (true)
	{
		pair<int, int> p = q.front();
		q.pop();

		int val = p.first;
		int sec = p.second;

		if (sec == minimum)
		{
			if(val == k)
				manner++;
			q.push(pair<int, int>(val + 1, sec + 1));
			q.push(pair<int, int>(val - 1, sec + 1));
			q.push(pair<int, int>(val * 2, sec + 1));
		}
		else if (sec < minimum)
		{
			q.push(pair<int, int>(val + 1, sec + 1));
			q.push(pair<int, int>(val - 1, sec + 1));
			q.push(pair<int, int>(val * 2, sec + 1));
		}
		else
		{
			return;
		}
	}
}