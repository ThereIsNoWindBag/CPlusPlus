#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, tmp;
vector<int> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cout << v[0] * v[N - 1];

	return 0;
}