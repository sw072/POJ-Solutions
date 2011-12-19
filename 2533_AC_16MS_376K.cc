#include "stdio.h"
#include "string.h"

#define N 1001

int list[N];
int d[N], path[N], max_len, max_len_pos;
int n;

int DP()
{
	int i, j;
	int max = -1, pre;
	d[0] = 1;
	path[0] = -1;
	for(i = 1; i < n; i++)
	{
		max = -1;
		for(j = 0; j < i; j++)
		{
			if(list[i] > list[j])
			{
				if(d[j] > max)
				{
					max = d[j];
					pre = j;
				}
			}
		}
		if(max == -1)
		{
			d[i] = 1;
			path[i] = -1;
		}
		else
		{
			d[i] = max + 1;
			path[i] = pre;
		}
		if(d[i] > max_len)
		{
			max_len = d[i];
			max_len_pos = i;
		}
	}
	return max_len;
}

void print_ordered_list(int pos)
{
	if(pos == -1) return;
	print_ordered_list(path[pos]);
	printf("%d ",list[pos]);
}

int main()
{
	int i;
	while(scanf("%d", &n) != -1)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &list[i]);
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		max_len = 0;
		memset(d, 0, N * 4);
		printf("%d\n", DP());
		//		print_ordered_list(max_len_pos);
		//		printf("\n");
	}

	return 0;
}