#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define N 1000000

struct node
{
	int num;
	int ntidx[10];
};


node t[N];
int tail;
bool finish;

bool insert(char str[])
{
	int i, idx;
	bool flag = false;
	int len = strlen(str);
	int pidx = 0;
	for(i = 0; i < len; i++)
	{
		idx = str[i] - '0';
		if(t[pidx].ntidx[idx])
		{
			t[pidx].num++;
			pidx = t[pidx].ntidx[idx];
		}
		else
		{
			if(pidx && !t[pidx].num && !flag) break;
			t[pidx].num++;
			t[pidx].ntidx[idx] = tail;
			pidx = tail;
			tail++;
			memset(&t[pidx], 0, sizeof(node));
			flag = true;
		}
	}
	return flag;
}

int main()
{
	int n, m;
	int i, j;
	char pn[16];
	scanf("%d", &n);
	memset(&t[0], 0, sizeof(node));
	for(i = 0; i < n; i++)
	{
		scanf("%d", &m);
		memset(&t[0], 0, sizeof(node));
		finish = false;
		tail = 1;
		for(j = 0; j < m; j++)
		{
			scanf("%s", pn);
			if(!finish) finish = !insert(pn);
		}
		if(finish) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}