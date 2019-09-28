#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> value;
vector<int> sumOfStates;

int sum = 0;

string delimiterM = "-";
string delimiterP = "+";

int main()
{
	string s;
	std::getline(cin, s);

	size_t pos = 0;
	string token;
	//아 이렇게 while 선언해도 되나? (pos = s.find(delimiterM))
	while ((pos = s.find(delimiterM)) != string::npos)
	{
		token = s.substr(0, pos);
		value.push_back(token);
		s.erase(0, pos + 1);
	}
	value.push_back(s);

	for (string tmp : value)
	{
		sum = 0;

		size_t pos2 = 0;
		while ((pos2 = tmp.find(delimiterP)) != string::npos)
		{
			token = tmp.substr(0, pos2);
			sum += stoi(token);
			tmp.erase(0, pos2 + 1);
		}
		sum += stoi(tmp);
		sumOfStates.push_back(sum);
	}

	sum = sumOfStates[0];

	int size = sumOfStates.size();

	for (int i = 1; i < size; ++i)
	{
		sum -= sumOfStates[i];
	}

	cout << sum;

	return 0;
}