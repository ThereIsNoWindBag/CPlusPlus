#include <iostream>
#include <string>

using namespace std;

string s;
int sum = 0;
int tmp;
int mul = 1;

int main()
{
	cin >> s;

	for (int i = s.length() - 1; i >= 0; --i)
	{
		if (65 <= s[i])
			tmp = s[i] - 55;
		else
			tmp = s[i] - 48;
		
		sum += tmp * mul;
		mul *= 16;
	}

	cout << sum;
}