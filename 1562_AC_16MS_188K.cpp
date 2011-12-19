#include <stdio.h>
#include <string.h>

#define N 105

int m, n;
bool map[N][N];
bool visit[N][N];
int count;

short int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void dfs(int i, int j)
{
	int k;
	int ni, nj;
	for(k = 0; k < 8; k++)
	{
		ni = i + dirs[k][0];
		nj = j + dirs[k][1];
		if(ni >= 0 && ni < m && nj >= 0 && nj < n && map[ni][nj] && !visit[ni][nj])
		{
			visit[ni][nj] = true;
			dfs(ni, nj);
		}
	}
}

int count_deposit()
{
	int i, j;
	count = 0;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(map[i][j] && !visit[i][j])
			{
				count++;
				visit[i][j] = true;
				dfs(i, j);
			}
	return count;
}

int main()
{
	int i, j;
	char ch;
	while(scanf("%d%d", &m, &n))
	{
		if(!m) break;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				while(scanf("%c", &ch))
					if(ch != '*' && ch != '@') continue;
					else break;
				if(ch == '*') map[i][j] = false;
				else map[i][j] = true;
			}
		}
		count_deposit();
		printf("%d\n", count);
	}
	return 0;
}