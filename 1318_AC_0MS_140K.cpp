#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define LEN 8

struct w
{
	char word[LEN];
	char mark[LEN];
};

w dict[N];
int n;

int comp(const void *a, const void *b)
{
	w *w1 = (w *)a;
	w *w2 = (w *)b;
	return strcmp(w1->word, w2->word);
}

int main()
{
	char word[LEN];
	int i, j, len;
	int cnt[26];
	bool found;
	n = 0;
	while(scanf("%s", word) != -1)
	{
		if(!strcmp(word, "XXXXXX")) break;
		strcpy(dict[n].word, word);
		len = strlen(word);
		memset(cnt, 0, sizeof(cnt));
		for(i = 0; i < len; i++) cnt[word[i] - 'a']++;
		j = 0;
		for(i = 0; i < 26; i++)
		{
			if(cnt[i])
			{
				dict[n].mark[j++] = i + 'a';
				cnt[i]--;
				i--;
			}
		}
		dict[n].mark[j] = '\0';
		n++;
	}

	qsort(&dict[0], n, sizeof(w), comp);

	while(scanf("%s", word) != -1)
	{
		if(!strcmp(word, "XXXXXX")) break;
		len = strlen(word);
		memset(cnt, 0, sizeof(cnt));
		for(i = 0; i < len; i++) cnt[word[i] - 'a']++;
		j = 0;
		for(i = 0; i < 26; i++)
		{
			if(cnt[i])
			{
				word[j++] = i + 'a';
				cnt[i]--;
				i--;
			}
		}
		found = false;
		for(i = 0; i < n; i++)
		{
			if(!strcmp(dict[i].mark, word))
			{
				printf("%s\n", dict[i].word);
				found = true;
			}
		}
		if(!found) printf("NOT A VALID WORD\n");
		printf("******\n");
	}

	return 0;
}