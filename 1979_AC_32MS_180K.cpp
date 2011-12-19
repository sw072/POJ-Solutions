#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define N 30
struct pos
{
	int r, c;
};
int m, n;
bool map[N][N];
bool visit[N][N];
int sr, sc;
const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs()
{
	int i, cnt = 0;
	pos s = {sr, sc};
	pos curr, next;
	queue<pos> q;
	q.push(s);
	cnt++;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		for(i = 0; i < 4; i++)
		{
			next.r = curr.r + dirs[i][0];
			next.c = curr.c + dirs[i][1];
			if(next.r >= 0 && next.r < m && next.c >= 0 && next.c < n 
				&& map[next.r][next.c] && !visit[next.r][next.c])
			{
				visit[next.r][next.c] = true;
				q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int i, j;
	char ch;
	while(scanf("%d%d", &n, &m) != -1)
	{
		if(n == 0 && m == 0) break;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for(i = 0; i < m; i++)
			for(j = 0; j < n; j++)
			{
				while(scanf("%c", &ch) != -1)
				{
					if(ch != '.' && ch != '#' && ch != '@') continue;
					else break;
				}
				if(ch == '.') map[i][j] = true;
				else if(ch == '#') map[i][j] = false;
				else
				{
					sr = i;
					sc = j;
					map[i][j] = true;
					visit[i][j] = true;
				}
			}
		printf("%d\n", bfs());
	}

	return 0;
}