#include "stdio.h"
#include "string.h"

#define N 1000

int parent[N];
bool flag[N];
int max_node, edge_num;
bool is_tree;
bool finish;

int find_set(int idx)
{
	int root = idx;
	int temp;
	while(parent[root] > 0) root = parent[root];
	while(idx != root)
	{
		temp = parent[idx];
		parent[idx] = root;
		idx = temp;
	}
	return root;
}

void union_set(int root1, int root2)
{
	if(root1 == root2) return;
	if(parent[root1] < parent[root2])
	{
		parent[root1] +=parent[root2];
		parent[root2] = root1;
	}
	else
	{
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}
}

int main()
{
	int n1, n2;
	int i, case_num = 0;
	int root1, root2;
	finish = false;
	while(!finish)
	{
		case_num++;
		for(i = 0; i < N; i++) parent[i] = -1;
		max_node = -1;
		edge_num = 0;
		memset(flag, 0, sizeof(flag));
		is_tree = true;
		while(scanf("%d%d", &n1, &n2) != -1)
		{
			edge_num++;
			if(n1 < 0 && n2 < 0)
			{
				finish = true;
				break;
			}
			if(n1 == 0 && n2 == 0)
			{
				if(edge_num == 1)
				{
					printf("Case %d is a tree.\n", case_num);
					break;
				}
				if(!is_tree)
				{
					printf("Case %d is not a tree.\n", case_num);
					break;
				}
				is_tree = false;
				for(i = 1; i <= max_node; i++)
				{
					if(!flag[i]) continue;
					if(parent[i] < 0)
					{
						if(!is_tree) is_tree = true;
						else
						{
							is_tree = false;
							break;
						}
					}
				}
				printf("Case %d is%sa tree.\n", case_num, is_tree ? " " : " not ");
				break;
			}		
			flag[n1] = true;
			flag[n2] = true;
			if(n1 > max_node) max_node = n1;
			if(n2 > max_node) max_node = n2;
			root1 = find_set(n1);
			root2 = find_set(n2);
			if(root1 == root2) is_tree = false;
			else
			{
				union_set(root1, root2);
			}
		}
	}
	return 0;
}