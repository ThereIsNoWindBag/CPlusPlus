#include <iostream>
#include <string>

using namespace std;

string s1, s2, stmp, ans = "";
int tmp;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s1;

	if (s1 == "0")
	{
		cout << s1;
		return 0;
	}

	for (char i : s1)
	{
		stmp = "";
		tmp = i - 48;

		for (int j = 0; j < 3; ++j)
		{
			stmp = to_string(tmp % 2) + stmp;
			tmp = tmp / 2;
		}

		ans += stmp;
	}

	while (ans[0] == '0')
	{
		ans = ans.substr(1);
	}

	cout << ans;

	return 0;
}