#define FOR(i, T) for(unsigned int i = 0; i < (T); ++i)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

char arr[11];
vector<char> v;

int main()
{
	cin >> arr;

	FOR(i, strlen(arr))
	{
		v.push_back(arr[i]);
	}

	sort(v.begin(), v.end(), greater<char>());

	FOR(i, strlen(arr))
	{
		cout << v[i];
	}

	return 0;
}