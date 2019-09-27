#include <iostream>

using namespace std;

int eki[4][2];

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		cin >> eki[i][0] >> eki[i][1];
	}
	
	int MAX = eki[0][1];
	int cur = eki[0][1];
	for (int i = 1; i < 3; ++i)
	{
		cur += eki[i][1] - eki[i][0];
		if (MAX < cur)
			MAX = cur;
	}
		
	
	cout << MAX;

	return 0;
}