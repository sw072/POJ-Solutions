#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100001

struct node
{
	node *next[26];
	int widx[26];
};

node * trie_root;
char dict[N][12];
int n;

int main()
{
	char fw[16];
	int i, fwlen, idx;
	n = 1;
	trie_root = (node *)malloc(sizeof(node));
	memset(trie_root, 0, sizeof(node));
	node *p = trie_root;
	while(1)
	{
		scanf("%s", dict[n]);
		scanf("%c", &fw[0]);
		if(fw[0] != '\n') scanf("%s", fw);
		else break;
		n++;
		p = trie_root;
		i = 0;
		while(fw[i + 1])
		{
			idx = fw[i] - 'a';
			if(!p->next[idx])
			{
				p->next[idx] = (node *)malloc(sizeof(node));
				memset(p->next[idx], 0, sizeof(node));
			}
			p = p->next[idx];
			i++;
		}
		p->widx[fw[strlen(fw) - 1] - 'a'] = n - 1;
	}
	strcpy(fw, dict[n]);
	do
	{
		p = trie_root;
		fwlen = strlen(fw);
		for(i = 0; i < fwlen - 1; i++)
		{
			idx = fw[i] - 'a';
			if(!p->next[idx]) break;
			p = p->next[idx];
		}
		if(i < fwlen - 1 && !p->widx[fw[fwlen - 1] - 'a']) printf("eh\n");
		else printf("%s\n", dict[p->widx[fw[fwlen - 1] - 'a']]);
	}while(scanf("%s", fw) != -1);

	return 0;
}