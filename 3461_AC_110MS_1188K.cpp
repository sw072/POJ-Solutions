#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char w[10002];
char t[1000002];

int kmp_n(char target[], char pattern[])
{
	int i, j;
	int tlen = strlen(target);
	int plen = strlen(pattern);
	int * p = (int *)malloc(sizeof(int) * plen);
	//contruct arrary p[]
	p[0] = -1;
	for(i = 1; i < plen; i++)
	{
		j = p[i - 1];
		while(j != -1 && pattern[j + 1] != pattern[i]) j = p[j];
		if(pattern[j + 1] == pattern[i]) p[i] = j + 1;
		else p[i] = j;
	}
	//match
	int tidx = 0, pidx = 0;
	int occur = 0;
	while(tidx < tlen)
	{
		while(tidx < tlen && pidx < plen)
		{
			if(target[tidx] == pattern[pidx])
			{	tidx++;		pidx++;}
			else if(pidx == 0)
			{	tidx++;	}
			else
			{	pidx = p[pidx - 1] + 1;}
		}
		if(pidx == plen)
		{
			occur++;
			pidx = p[pidx - 1] + 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
		}
	}
	free(p);
	return occur;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s%s", w, t);
		printf("%d\n", kmp_n(t, w));
	}
	return 0;
}