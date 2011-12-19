#include "stdio.h"
#include "string.h"

#define N 50

int a, b;
bool flag[N][N];
int path[N * N];
bool finish;

int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2 };

void DFS(int x, int y, int nstep)
{
//	if(finish) return;
	if(nstep == a * b)
	{
		finish = true;
		return;
	}
	int i;
	int nx, ny;
	for(i = 0; i < 8; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx >= 0 && nx < a && ny >= 0 && ny < b && !flag[nx][ny] && !finish)
		{
			flag[nx][ny] = true;
			path[nstep] = i;
			DFS(nx, ny, nstep + 1);
			flag[nx][ny] = false;
		}
	}
}

void print_path()
{
	int i;
	int x = 0, y = 'A';
	int nstep = a * b;
	for(i = 1; i < nstep; i++)
	{
		x += dx[path[i]];
		y += dy[path[i]];
		printf("%c%d", y, x + 1);
	}
	printf("\n");
}

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		memset(flag, 0, N * N);
		finish = false;
		flag[0][0] = true;
		DFS(0, 0, 1);
		printf("Scenario #%d:\n", i + 1);
		if(finish)
		{
			printf("A1");
			print_path();
		}
		else printf("impossible\n");
		printf("\n");
	}

	return 0;
}