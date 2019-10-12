#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v;
stack<pair<int, int>> s;
int cnt[1000005];

int N, tmp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		v.push_back(tmp);
		cnt[tmp]++;
	}

	for (int i = 0; i < N; ++i)
	{
		if (s.empty())
		{
			s.push(pair<int, int>(v[i], i));
			continue;
		}
		
		while (!s.empty() && cnt[s.top().first] < cnt[v[i]])
		{
			v[s.top().second] = v[i];
			s.pop();
		}
		s.push(pair<int, int>(v[i], i));
	}
	
	while (!s.empty())
	{
		v[s.top().second] = -1;
		s.pop();
	}

	for (int i : v)
	{
		cout << i << ' ';
	}

	return 0;
}