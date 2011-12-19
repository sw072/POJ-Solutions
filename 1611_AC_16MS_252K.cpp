#include "stdio.h"

#define N 30000

int parent[N];
int n, m;

int find_set(int idx)
{
	int root = idx;
	int temp;
	while(parent[root] >= 0) root = parent[root];
	while(idx != root)
	{
		temp = parent[idx];
		parent[idx] = root;
		idx = temp;
	}
	return root;
}

void union_set(int idx1, int idx2)
{
	int root1 = find_set(idx1);
	int root2 = find_set(idx2);
	if(root1 == root2) return;
	if(parent[root1] > parent[root2])
	{
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}
	else
	{
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
}

int main()
{
	int i, j, k, idx, root;
	while(1)
	{
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0) break;
		for(i = 0; i < n; i++)
		{
			parent[i] = -1;
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d", &k);
			scanf("%d", &root);
			if(k == 1) continue;
			for(j = 1; j < k; j++)
			{
				scanf("%d", &idx);
				union_set(root, idx);
			}
		}
		printf("%d\n", -parent[find_set(0)]);
	}

	return 0;
}