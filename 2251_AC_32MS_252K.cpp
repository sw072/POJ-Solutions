#include <stdio.h>
#include <queue>
using namespace std;

#define N 30

int L, R, C;
char d[N][N][N];
bool flag[N][N][N];

struct step
{
	short int x, y, z;
	short int nstep;
}s;
struct dir
{
	short int dx, dy, dz;
};
struct dir dirs[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int bfs()
{
	queue<step> q;
	q.push(s);
	flag[s.x][s.y][s.z] = true;
	step curr, next;
	int i;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		next.nstep = curr.nstep + 1;
		for(i = 0; i < 6; i++)
		{
			next.x = curr.x + dirs[i].dx;
			next.y = curr.y + dirs[i].dy;
			next.z = curr.z + dirs[i].dz;
			if(!(d[next.x][next.y][next.z] == '.' || d[next.x][next.y][next.z] == 'E'))
				continue;
			if(d[next.x][next.y][next.z] == 'E')
			{
				return next.nstep;
			}
			if(next.x >= 0 && next.x < L && next.y >= 0 && next.y < R 
				&& next.z >= 0 && next.z < C && !flag[next.x][next.y][next.z])
			{
				flag[next.x][next.y][next.z] = true;
				q.push(next);
			}
		}
	}
	return -1;
}

int main()
{
	int l, r, c;
	char ch;
	while(1)
	{
		scanf("%d%d%d", &L, &R, &C);
		if(L + R + C == 0) break;
		for(l = 0; l < L; l++)
		{
			scanf("%c", &ch);
			for(r = 0; r < R; r++)
			{
				for(c = 0; c < C; c++)
				{
					scanf("%c", &d[l][r][c]);
					if(d[l][r][c] == 'S')
					{
						s.x = l;
						s.y = r;
						s.z = c;
						s.nstep = 0;
					}
				}
				scanf("%c", &ch);
			}
		}
		memset(flag, 0, sizeof(flag));
		int res = bfs();
		if(res >= 0) printf("Escaped in %d minute(s).\n", res);
		else printf("Trapped!\n");
/*		for(l = 0; l < L; l++)
		{
			for(r = 0; r < R; r++)
			{
				for(c = 0; c < C; c++)
				{
					printf("%c", d[l][r][c]);
				}
				printf("\n");
			}
			printf("\n");
		}
*/
	}

	return 0;
}