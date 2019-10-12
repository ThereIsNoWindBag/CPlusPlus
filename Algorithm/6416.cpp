#include <iostream>
#include <map>
#include <vector>
using namespace std;

int c;
int u, v;

int main()
{
	while (true)
	{
		c++;

		vector<int> donor, recev;
		multimap<int, int> MAP, revMAP;

		while (true)
		{
			cin >> u >> v;

			if (u == 0 && v == 0)
				break;
			if (u == -1 && v == -1)
				return 0;
			
			donor.push_back(u);
			recev.push_back(v);
			MAP.insert(pair<int, int>(u, v));
			revMAP.insert(pair<int, int>(v, u));
		}

		if (MAP.empty())
		{
			cout << "Case " << c << " is a tree.\n";
			continue;
		}

		//판정 부분 시작~
		bool isTree = true;

		//1. 루트는 단 하나 뿐이다.

		int storage;
		int numOfRoot = 0;

		for (int i : donor)
		{
			if (revMAP.count(i) == 0)
			{
				storage = i;
				numOfRoot++;
				break;
			}
		}

		for (int i : donor)
		{
			if (revMAP.count(i) == 0 && storage != i)
			{
				numOfRoot++;
				break;
			}
		}
		
		if (numOfRoot != 1)
			isTree = false;

		//2. '오는' 경로는 단 한개 뿐이다
		for (int i : recev)
		{
			if (revMAP.count(i) != 1)
			{
				isTree = false;
				break;
			}
		}

		if (isTree)
		{
			cout << "Case " << c << " is a tree.\n";
		}
		else
		{
			cout << "Case " << c << " is not a tree.\n";
		}
	}

	return 0;
}