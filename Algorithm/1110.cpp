#include <iostream>
#include <string>

using namespace std;

string s, org, ts;
int cycle = 0;

int main()
{
	cin >> s;

	org = s;

	do
	{
		if (s.length() == 1)
			s = "0" + s;

		ts = to_string((s[0] - '0') + (s[1] - '0'));

		s = to_string(s[1] - '0') + to_string(ts[ts.length() - 1] - '0');

		cycle++;
	} while (stoi(s) != stoi(org));
	
	cout << cycle;

	return 0;
}