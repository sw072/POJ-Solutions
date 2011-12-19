#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define N 8

struct pos
{
	int x, y;
	int nstep;
};
bool board[N][N];
pos s, e;
const int dirs[][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

int bfs()
{
	int i;
	pos curr, next;
	queue<pos> q;
	q.push(s);
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		for(i = 0; i < 8; i++)
		{
			next.x = curr.x + dirs[i][0];
			next.y = curr.y + dirs[i][1];
			if(next.x >= 0 && next.x < 8 && next.y >= 0 && next.y < 8 && !board[next.x][next.y])
			{
				if(next.x == e.x && next.y == e.y) return (curr.nstep + 1);
				board[next.x][next.y] = true;
				next.nstep = curr.nstep + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main()
{
	char ss[3], se[3];
	int res;
	while(scanf("%s %s", ss, se) != -1)
	{
		s.x = ss[0] - 'a';
		s.y = ss[1] - '1';
		s.nstep = 0;
		e.x = se[0] - 'a';
		e.y = se[1] - '1';
		e.nstep = 0;
		if(s.x == e.x && s.y == e.y)
		{
			res = 0;
		}
		else
		{
			memset(board, 0, sizeof(board));
			board[s.x][s.y] = true;
			res = bfs();
		}
		printf("To get from %s to %s takes %d knight moves.\n", ss, se, res);
	}

	return 0;
}
