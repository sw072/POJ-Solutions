#include "stdio.h"
#include "string.h"

int count[10];
char queue[16][81];
int idx;

void iterate()
{
	memset(count, 0, sizeof(count));
	int len = strlen(queue[idx]);
	int i, j;
	for(i = 0; i < len; i++) count[queue[idx][i] - '0']++;
	idx++;
	for(i = 0, j = 0; i <= 9; i++)
	{
		if(!count[i]) continue;
		if(count[i] > 9)
		{
			queue[idx][j++] = count[i] / 10 + '0';
			queue[idx][j++] = count[i] % 10 + '0';
		}
		else queue[idx][j++] = count[i] + '0';
		queue[idx][j++] = i + '0';
	}
	queue[idx][j] = '\0';
}

void process()
{
	int maxnitor = 15;
	int i = 1, j;
	idx = 0;
	while(i <= maxnitor)
	{
		iterate();
		if(!strcmp(queue[i - 1], queue[i]))
		{
			if(i == 1)
			{
				printf("%s is self-inventorying\n", queue[0]);
				return;
			}
			else
			{
				printf("%s is self-inventorying after %d steps \n", queue[0], i - 1);
				return;
			}
		}
		else
		{
			for(j = 0; j < i; j++)
			{
				if(!strcmp(queue[j], queue[i]))
				{
					printf("%s enters an inventory loop of length %d\n", queue[0], i - j);
					return;
				}
			}
		}
		i++;
	}
	printf("%s can not be classified after 15 iterations\n", queue[0]);
}

int main()
{
	while(scanf("%s", queue[0]))
	{
		if(queue[0][0] == '-') break;
		process();
	}

	return 0;
}