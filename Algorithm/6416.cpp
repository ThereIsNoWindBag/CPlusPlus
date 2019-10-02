#include <iostream>
using namespace std;

int u, v;



int main()
{
	while (true)
	{
		cin >> u >> v;
		if (u == -1 && v == -1)
			break;
		if (u == 0 && v == 0)
			doClear();
	}
	
	return 0;
}

void doClear()
{
	cout << "Tree" << '\n';
}