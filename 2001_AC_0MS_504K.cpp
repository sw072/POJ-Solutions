#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1001

struct node
{
	node *next[26];
	short int cnt[26];
};

node * root;
char list[N][24];
int n;

int main()
{
	int idx, i, j, k;
	root = (node *)malloc(sizeof(node));
	memset(root, 0, sizeof(node));
	node *p;
	n = -1;
	while(scanf("%s", list[++n]) != -1)
	{
		p = root;
		i = 0;
		while(list[n][i + 1])
		{
			idx = list[n][i] - 'a';
			p->cnt[idx]++;
			if(!p->next[idx])
			{
				p->next[idx] = (node *)malloc(sizeof(node));
				memset(p->next[idx], 0, sizeof(node));
			}
			p = p->next[idx];
			i++;
		}
		p->cnt[list[n][i] - 'a']++;
	}

	for(i = 0; i < n; i++)
	{
		p = root;
		j = 0;
		while(list[i][j + 1] && p->cnt[list[i][j] - 'a'] != 1)
		{
			p = p->next[list[i][j] - 'a'];
			j++;
		}
		printf("%s ", list[i]);
		for(k = 0; k <= j; k++) printf("%c", list[i][k]);
		printf("\n");
	}

	return 0;
}