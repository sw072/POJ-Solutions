#include <stdio.h>
#include <string.h>

#define LEN 80
#define N 120

char history[N][LEN];
int size;
int idx;

int main()
{
	char cmd[16], url[80];
	idx = size = 0;
	strcpy(history[size++], "http://www.acm.org/");
	idx = size - 1;
	while(1)
	{
		scanf("%s", cmd);
		if(!strcmp("QUIT", cmd)) break;
		else if(!strcmp("VISIT", cmd))
		{
			scanf("%s", url);
			printf("%s\n", url);
			strcpy(history[++idx], url);
			size = idx + 1;
		}
		else if(!strcmp("BACK", cmd))
		{
			if(idx > 0)
			{
				printf("%s\n", history[--idx]);
			}
			else
			{
				printf("Ignored\n");
				idx = 0;
			}
		}
		else if(!strcmp("FORWARD", cmd))
		{
			if(idx + 1 < size)
				printf("%s\n", history[++idx]);
			else printf("Ignored\n");
		}
	}

	return 0;
}