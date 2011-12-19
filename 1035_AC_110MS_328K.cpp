#include "stdio.h"
#include "string.h"
#include "math.h"

struct word
{
	char w[16];
	int len;
};

word words[10001];
int n;

bool str_cmp(char s[], int slen, char l[], int llen)
{
	int i, j;
	bool flag = false;
	i = 0;
	j = 0;
	while(i < slen && j < llen)
	{
		if(s[i] != l[j])
		{
			if(!flag)
			{
				j++;
				flag = true;
				continue;
			}
			else return false;
		}
		i++;
		j++;
	}
	return true;
}

bool is_correct(char str[], int len)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(len == words[i].len)
		{
			if(!strcmp(str, words[i].w))
				return true;
		}
	}
	return false;
}

void process(char str[])
{
	int i, j;
	bool res;
	int len = strlen(str);
	if(is_correct(str, len))
	{
		printf("%s is correct\n", str);
		return;
	}
	else 
	{
		printf("%s:", str);
		for(i = 0; i < n; i++)
		{
			if(len == words[i].len)
			{
				res = false;
				for(j = 0; j < len; j++)
				{
					if(str[j] != words[i].w[j])
					{
						if(!res)
							res = true;
						else break;
					}
				}
				if(j == len)
				{
					printf(" %s", words[i].w);
				}
			}
			else if(abs(len - words[i].len) == 1)
			{
				if(len < words[i].len) res = str_cmp(str, len, words[i].w, words[i].len);
				else res = str_cmp(words[i].w, words[i].len, str, len);
				if(res) printf(" %s", words[i].w);
			}
		}
		printf("\n");
	}
}

int main()
{
	char str[16];
	n = 0;
	while(1)
	{
		scanf("%s", words[n].w);
		if(words[n].w[0] == '#') break;
		words[n].len = strlen(words[n].w);
		n++;
	}
	while(1)
	{
		scanf("%s", str);
		if(str[0] == '#') break;
		process(str);
	}

	return 0;
}