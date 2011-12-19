#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define N 400001

char str[N];

void dfs(int p[], int idx)
{
	if(p[idx] == -1) return;
	dfs(p, p[idx]);
	printf("%d ", p[idx] + 1);
}

void kmp(char s[])
{
	int i, j;
	int len = strlen(str);
	int * p = (int *)malloc(sizeof(int) * len);
	p[0] = -1;
	for(i = 1; i < len; i++)
	{
		j = p[i -1];
		while(j != -1 && s[i] != s[j + 1]) j = p[j];
		if(s[i] == s[j + 1]) p[i] = j +1;
		else p[i] = -1;
	}
	//for(i = 0; i < len; i++)
	//	printf("%d ", p[i]);
	//printf("\n");
	dfs(p, len - 1);
	free(p);
}

int main()
{
	int i;
	int len;
	bool flag;
	while(scanf("%s", str) != -1)
	{
		kmp(str);
		printf("%d\n", strlen(str));
	}

	return 0;
}