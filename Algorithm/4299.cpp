#include <iostream>

using namespace std;

int h, c;

int main()
{
	cin >> h >> c;

	if (h >= c && (h + c) % 2 == 0)
		cout << (h + c) / 2 << " " << (h - c) / 2;
	else
		cout << -1;

	return 0;
}