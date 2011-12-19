#include "stdio.h"
#include "string.h"

#define N 100000
#define max(a, b) ((a) > (b) ? (a) : (b))

char s[N], t[N];
short int d1[N], d2[N];

int lcs()
{
	int ls = strlen(s);
	int lt = strlen(t);
	int i, j;
	memset(d1, 0, sizeof(d1));
	memset(d2, 0, sizeof(d2));
	for(i = 1; i <= ls; i++)
	{
		for(j = 1; j <= lt; j++)
		{
			if(s[i - 1] == t[j - 1])
				d2[j] = d1[j - 1] + 1;
			else d2[j] = max(d2[j - 1], d1[j ]);
		}
		memcpy(d1, d2, sizeof(d2));
	}
	return d2[lt];
}

int main()
{
	while(scanf("%s%s", s, t) != -1)
	{
		if(lcs() == strlen(s)) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}