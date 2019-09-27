#include <iostream>

using namespace std;

int A, B;
int num = 1;
int cnt = 1;
int times = 1;
int sum = 0;

int main()
{
	cin >> A >> B;

	while (cnt <= B)
	{
		if (times > num)
		{
			num++;
			times = 1;
		}

		if (A <= cnt)
		{
			sum += num;
		}
		cnt++;
		times++;
	}

	cout << sum;

	return 0;
}