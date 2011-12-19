#include "stdio.h"
#include "string.h"

#define N 42

struct direction
{
	char dir;
	int stepidx;
};

char map[N][N];
bool flag[N][N];
int w, h;
int sx, sy;
int minstep;
int step[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
direction d[4] = {{'e', 3}, {'s', 2}, {'w', 1}, {'n', 0}};
int sdidx;

int q[65535][2];
int s, e;
int path[65535];

void dfs(int x, int y, int nstep)
{
	if(map[x][y] == 'E')
	{
		if(nstep < minstep)
			minstep = nstep;
		return;
	}
	int i;
	int nextx, nexty;
	for(i = 0; i < 4; i++)
	{
		nextx = x + step[i][0];
		nexty = y + step[i][1];
		if((nextx >= 0 && nextx < h) && (nexty >= 0 && nexty < w) && (map[nextx][nexty] == '.' || map[nextx][nexty] == 'E') && !flag[nextx][nexty])
		{
			flag[nextx][nexty] = true;
			dfs(nextx, nexty, nstep + 1);
			flag[nextx][nexty] = false;
		}
	}
}

bool is_exists(int x, int y)
{
	int i;
	for(i = 0; i < e; i++)
	{
		if(x == q[i][0] && y == q[i][1])
			return true;
	}
	return false;
}

int bfs(int x, int y)
{
	q[0][0] = x;
	q[0][1] = y;
	s = 0;
	e = 1;
	path[s] = 1;
	int i;
	int nextx, nexty;
	while(s < e)
	{
		for(i = 0; i < 4; i++)
		{
			nextx = q[s][0] + step[i][0];
			nexty = q[s][1] + step[i][1];
			if((nextx >= 0 && nextx < h) && (nexty >= 0 && nexty < w) && (map[nextx][nexty] == '.' || map[nextx][nexty] == 'E'))
			{
				if(!is_exists(nextx, nexty))
				{
					q[e][0] = nextx;
					q[e][1] = nexty;
					path[e] = path[s] + 1;
					e++;
					if(map[nextx][nexty] == 'E')
						return path[e - 1];
				}
			}
		}
		s++;
	}
	return -1;
}

int left(int x, int y, int didx)
{
	int nstep = 1;
	int dir, i;
	int nextx, nexty;
	dir = didx;
	int tdir;
	bool bstep = false;
	while(map[x][y] !=  'E')
	{
		tdir = dir;
		dir = (dir + 3) % 4;
		nextx = x + step[d[dir].stepidx][0];
		nexty = y + step[d[dir].stepidx][1];
		bstep = false;
		if((nextx >= 0 && nextx < h) && (nexty >= 0 && nexty < w) && (map[nextx][nexty] == '.' || map[nextx][nexty] == 'E'))
		{
			bstep = true;
		}
		for(i = (dir + 1) % 4;!bstep; i = (i + 1) % 4)
		{
			nextx = x + step[d[i].stepidx][0];
			nexty = y + step[d[i].stepidx][1];
			if((nextx >= 0 && nextx < h) && (nexty >= 0 && nexty < w) && (map[nextx][nexty] == '.' || map[nextx][nexty] == 'E'))
			{
				dir = i;
				break;
			}
		}
		x = nextx;
		y = nexty;
		nstep++;
	}
	return nstep;
}

int right(int x, int y, int didx)
{
	int nstep = 1;
	int dir, i;
	int nextx, nexty;
	dir = didx;
	int tdir;
	bool bstep = false;
	while(map[x][y] !=  'E')
	{
		tdir = dir;
		dir = (dir + 1) % 4;
		nextx = x + step[d[dir].stepidx][0];
		nexty = y + step[d[dir].stepidx][1];
		bstep = false;
		if((nextx >= 0 && nextx < h) && (nexty >= 0 && nexty < w) && (map[nextx][nexty] == '.' || map[nextx][nexty] == 'E'))
		{
			bstep = true;
		}
		for(i = (dir + 3) % 4;!bstep; i = (i + 3) % 4)
		{
			nextx = x + step[d[i].stepidx][0];
			nexty = y + step[d[i].stepidx][1];
			if((nextx >= 0 && nextx < h) && (nexty >= 0 && nexty < w) && (map[nextx][nexty] == '.' || map[nextx][nexty] == 'E'))
			{
				dir = i;
				break;
			}
		}
		x = nextx;
		y = nexty;
		nstep++;
	}
	return nstep;
}

int main()
{
	int n;
	int i, j, k;
	char ch;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d\n", &w, &h);
		for(j = 0; j < h; j++)
		{
			for(k = 0; k < w; k++)
			{
				scanf("%c", &map[j][k]);
				if(map[j][k] == 'S')
				{
					sx = j;
					sy = k;
					if(sx == 0){sdidx = 1;}
					else if(sx == h){sdidx = 3;}
					else if(sy == 0){sdidx = 0;}
					else if(sy == w){sdidx = 2;}
				}
			}
			scanf("%c", &ch);
		}
		memset(flag, 0, sizeof(flag));
		flag[sx][sy] = true;
		minstep = 65535;
//		dfs(sx, sy, 1);
		printf("%d %d %d\n", left(sx, sy, sdidx), right(sx, sy, sdidx), bfs(sx, sy));
	}

	return 0;
}