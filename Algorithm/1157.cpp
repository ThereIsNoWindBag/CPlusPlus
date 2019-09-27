#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int arr[26];
string s;
int len, MAX = 0, mcnt = 0;

int main()
{
	for (int i = 0; i < 26; i++)
	{
		arr[i] = 0;
	}

	cin >> s;

	const char *a = s.c_str();

	len = strlen(a);

	for(int i = 0; i < len; i++)
	{
		arr[toupper(a[i]) - 'A']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > MAX)
		{
			MAX = arr[i];
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == MAX)
		{
			mcnt++;
		}
	}

	if (mcnt > 1)
		cout << "?";
	else
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] == MAX)
				cout << char(i + 'A');
		}

	return 0;
}