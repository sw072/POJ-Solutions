#include <stdio.h>
#include <string.h>

#define N 8

bool map[N][N];
bool flag[N];
int n, k;

void dfs(int r, int &cnt, int l)
{
	int i, j;
	if(l == k)
	{
		cnt++;
		return;
	}
	if(r == n) return;
	for(; r < n; r++)
		for(i = 0; i < n; i++)
		{
			if(!flag[i] && map[r][i])
			{
				flag[i] = true;
				dfs(r + 1, cnt, l + 1);
				flag[i] = false;
			}
		}
}

int count()
{
	int cnt = 0;
	int i;
	int r;
	memset(flag, 0, sizeof(flag));
	for(r = 0; r < n - k + 1; r++)
		for(i = 0; i < n; i++)
		{
			if(!flag[i] && map[r][i])
			{
				flag[i] = true;
				dfs(r + 1, cnt, 1);
				flag[i] = false;
			}
		}
	return cnt;
}

int main()
{
	int i, j;
	char ch;
	while(scanf("%d%d", &n, &k))
	{
		if(n == -1 && k == -1) break;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
			{
				while(1)
				{
					scanf("%c", &ch);
					if(ch != '.' && ch != '#') continue;
					else break;
				}
				if(ch == '.') map[i][j] = false;
				else map[i][j] = true;
			}
		printf("%d\n",count());
	}

	return 0;
}