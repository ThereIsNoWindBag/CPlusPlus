#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int N, sum = 0;
char b[80], *tok;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i, sum = 0)
	{
		cin >> b;
		tok = strtok(b, "X");
		while (tok != NULL)
		{
			sum += (string(tok).length() * (string(tok).length() + 1)) /2;
			tok = strtok(NULL, "X");
		}

		cout << sum << "\n";
	}

	return 0;
}