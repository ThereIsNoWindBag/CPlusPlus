#define forTime(i, T) for(int i = 0; i < T; ++i)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, tmp, standard, sum;

vector<int> v;

int main()
{
	cin >> T;

	forTime(i, T)
	{
		v.clear();
		sum = 0;

		cin >> N;

		forTime(j, N)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end());
		
		cout << 2 * (v[v.size() - 1] - v[0]) << "\n";
	}

	return 0;
}
