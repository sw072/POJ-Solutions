#include "stdio.h"
#include "string.h"

#define CORTOIDX(x, y) ((x) * 4 + (y))
#define SET1(s, x, y) (s |= ((short int)1 << CORTOIDX(x, y)))		//b
#define SET0(s, x, y) (s &= ~((short int)1 << CORTOIDX(x, y)))	//w
#define SETREVERSE(s, x, y) (s ^= ~((short int)1 << CORTOIDX(x, y)))

short int q[32767];
short int path[32767];
int s, e;
bool flag[65535];

int bfs(short int start)
{
	int i, j;
	short int state;
	if((start == (short)0) || (start == (short int)0xFFFF)) return 0;
	q[0] = start;
	s = 0;
	e = 1;
	path[s] = 0;
	while(s < e)
	{
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
			{
				state = q[s];
				SETREVERSE(state, i, j);
				if(i - 1 >= 0)
					SETREVERSE(state, i - 1, j);
				if(j - 1 >= 0)
					SETREVERSE(state, i, j - 1);
				if(i + 1 < 4)
					SETREVERSE(state, i + 1, j);
				if(j + 1 < 4)
					SETREVERSE(state, i, j + 1);
				if(!flag[state])
				{
					path[e] = path[s] + 1;
					q[e] = state;
					e++;
					flag[state] = true;
				}
				if(state == (short int)0 || state == (short int)0xFFFF) return path[e - 1];
			}
		s++;
	}
	return -1;
}

int main()
{
	char line[5];
	int i, j;
	short int start;
	int res;
	while(scanf("%s", line) != -1)
	{
		start = 0;
		memset(flag, 0, 65535);
		for(j = 0; j < 4; j++)
		{
			if(line[j] == 'b') SET1(start, 0, j);
			else SET0(start, 0, j);
		}
		for(i = 1; i < 4; i++)
		{
			scanf("%s", line);
			for(j = 0; j < 4; j++)
			{
				if(line[j] == 'b') SET1(start, i, j);
				else SET0(start, i, j);
			}
		}
		res = bfs(start);
		if(res != -1)
			printf("%d\n", res);
		else printf("Impossible\n");
	}
	return 0;
}