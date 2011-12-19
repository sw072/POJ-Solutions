#include "stdio.h"
#include "string.h"

#define N 15000
#define XMAX 32000

int c[XMAX + 1];
int res[N + 1];
int n;

#define low_bit(index) (index & (index ^ (index - 1)))

inline void add(int index, int val)
{
	while(index <= XMAX + 1)
	{
		c[index] += val;
		index += low_bit(index);
	}
}

inline int sum(int index)
{
	int s = 0;
	while(index > 0)
	{
		s += c[index];
		index -= low_bit(index);
	}
	return s;
}

int main()
{
	int x, y;
	int i;
	while(scanf("%d", &n) != -1)
	{
		memset(c, 0, (XMAX + 1) * 4);
		memset(res, 0, (N + 1) * 4);
		for(i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			res[sum(++x)]++;
			add(x, 1);
		}
		for(i = 0; i < n; i++)
			printf("%d\n", res[i]);
	}

	return 0;
}