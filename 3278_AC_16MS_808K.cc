#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define N 110000

struct step
{
	int pos;
	short int nstep;
};

int n, k;
bool flag[N + 1];

int bfs()
{
	bool isfound = false;
	step s = {n, 0};
	step curr, next;
	int i;
	queue<step> q;
	q.push(s);
	flag[s.pos] = true;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		next.nstep = curr.nstep + 1;
		for(i = 0; i < 3; i++)
		{
			if(i == 0)	next.pos = curr.pos * 2;
			else if( i== 1) next.pos = curr.pos - 1;
			else next.pos = curr.pos + 1;
			if(next.pos == k)
			{
				return next.nstep;
			}
			if(next.pos >= 0 && next.pos <= N && !flag[next.pos])
			{
				flag[next.pos] = true;
				q.push(next);
			}			
		}
	}
	return -1;
}


int main()
{
	while(scanf("%d%d", &n, &k) != -1)
	{
		if(n >= k)
		{
			printf("%d\n", n - k);
		}
		else
		{
			memset(flag, 0, sizeof(flag));
			printf("%d\n", bfs());
		}
	}
	return 0;
}
