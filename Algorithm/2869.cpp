#include <iostream>

using namespace std;

int A, B, T;
int day;

int main()
{
	cin >> A >> B >> T;

	T -= A;

	day = A - B;

	cout << 1 + T / day + (T % day == 0 ? 0 : 1);

	return 0;
}