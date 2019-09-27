#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

class linkedList
{
public:
	int value;
	vector<linkedList*> next;

	linkedList()
	{
		next.clear();
	}
};

int N, M;
int tmp1, tmp2;
linkedList *l;

int main()
{
	scanf("%d%d", &N, &M);

	l = new linkedList[N];

	for (int i = 0; i < N - 1; ++i)
	{
		scanf("%d%d", &tmp1, &tmp2);
		l[tmp1-1].next.push_back(&l[tmp2-1]);
	}

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &tmp1);
		l[i].value = tmp1;
	}

	deque<linkedList*> queue;

	linkedList doma;

	int sum;

	for (int i = 0; i < M; ++i)
	{
		scanf("%d",&tmp1);
		if (tmp1 == 1)
		{
			scanf("%d", &tmp1);
			queue.push_back(&l[tmp1 - 1]);

			for (int j = 0; j < queue.size(); ++j)
			{
				for (linkedList * lkd : queue[j]->next)
					queue.push_back(lkd);
			}

			sum = (*queue.begin())->value;
			for (deque<linkedList*>::iterator iter = queue.begin() + 1; iter != queue.end(); ++iter)
			{
				sum ^= (*iter)->value;
			}

			printf("%d", sum);
		}
		else if (tmp1 == 2)
		{
			scanf("%d%d", &tmp1, &tmp2);

			doma.value ^= tmp1;
		}
		else;
	}

	return 0;
}