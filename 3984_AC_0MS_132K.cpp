#include "stdio.h"
#include "string.h"

bool map[5][5];
int path[25][2];
bool flag[5][5];
int step[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool finish;

void dfs(int x, int y, int l)
{
	int i, j;
	int nextx,nexty;
	if(x == 4 && y == 4)
	{
		finish = true;
		for(i = 0; i < l; i++)
			printf("(%d, %d)\n", path[i][0], path[i][1]);
		return;
	}
	if(finish) return;
	for(i = 0; i < 4; i++)
	{
		nextx = x + step[i][0];
		nexty = y + step[i][1];
		if((nextx >= 0 && nextx < 5) && (nexty >= 0 && nexty < 5) && !map[nextx][nexty] && !flag[nextx][nexty])
		{
			flag[nextx][nexty] = true;
			path[l][0] = nextx;
			path[l][1] = nexty;
			dfs(nextx, nexty, l + 1);
			flag[nextx][nexty] = false;
		}
	}
}

int main()
{
	int i, j;
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			scanf("%d", &map[i][j]);
	path[0][0] = 0;
	path[0][1] = 0;
	memset(flag, 0, sizeof(flag));
	flag[0][0] = true;
	finish = false;
	dfs(0, 0, 1);

	return 0;
}