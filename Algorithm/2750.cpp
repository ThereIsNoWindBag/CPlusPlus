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

	for (int i = 0; i < N; ++i)
	{
		cout << v[i] << "\n";
	}

	return 0;
}