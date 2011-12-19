#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define N 201
#define min(a, b) (a < b ? a : b)
#define INF 0x7FFFFFFF

int residual[N][N];
int m, n;

#define DINIC

#ifdef EK
int min_aug[N], pre[N];
int bfs(int start, int end)
{
	int curr, i;
	queue<int> q;
	q.push(start);
	memset(pre, -1, sizeof(pre));
	for(i = start; i <= end; i++) min_aug[i] = INF;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		for(i = start; i <= end; i++)
		{
			if(pre[i] == -1 && residual[curr][i])
			{
				pre[i] = curr;
				q.push(i);
				min_aug[i] = min(min_aug[curr], residual[curr][i]);
				if(i == end) return min_aug[end];
			}
		}
	}
	return 0;
}

int ek(int start, int end)
{
	int max_flow = 0;
	int aug;
	int i;
	while(aug = bfs(start, end))
	{
		for(i = end; i != start; i = pre[i])
		{
			residual[pre[i]][i] -= aug;
			residual[i][pre[i]] += aug;
		}
		max_flow += aug;
	}
	return max_flow;
}
#elif defined DINIC
int level[N];
int stack[N], top;
int bfs(int start, int end)
{
	memset(level, -1, sizeof(level));
	level[start] = 0;
	queue<int> q;
	q.push(start);
	int curr, i;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		if(curr == end) break;
		for(i = start; i <= end; i++)
		{
			if(residual[curr][i] && level[i] == -1)
			{
				level[i] = level[curr] + 1;
				q.push(i);
			}
		}
	}
	return level[end];
}

int find_aug(int curr, int low, int start, int end)
{
	if(curr == end) return low;
	int i, aug, ret = 0;
	for(i = start; i <= end; i++)
	{
		if(level[curr] + 1 == level[i] && residual[curr][i])
		{
			if(aug = find_aug(i, min(residual[curr][i], low - ret), start, end))
			{
				residual[curr][i] -= aug;
				residual[i][curr] += aug;
				ret += aug;
			}
		}
	}
	if(!ret) level[curr] = -1;
	return ret;
}

int dinic(int start, int end)
{
	int max_flow = 0;
	int aug;
	while(bfs(start, end) != -1)
	{
		aug = find_aug(start, INF, start, end);
		max_flow += aug;
	}
	return max_flow;
}

#endif
int max_flow()
{
#ifdef EK
	return ek(1, n);
#elif defined DINIC
	return dinic(1, n);
#endif
}

int main()
{
	int i;
	int x, y, c;
	while(scanf("%d%d", &m, &n) != -1)
	{
		memset(residual, 0, sizeof(residual));
		for(i = 0; i < m; i++)
		{
			scanf("%d%d%d", &x, &y, &c);
			residual[x][y] += c;
		}
		printf("%d\n", max_flow());
	}

	return 0;
}