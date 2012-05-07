#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define N  50001
#define H_MAX 2000000
#define H_MIN -1

struct node
{
	int min, max;
	int lidx, ridx;
	node *left;
	node *right;
};

int h[N];
int n;
int q;

node *root;

void create_segmenttree(node **pr, int l, int r, int *pmin, int *pmax)
{
	int lmin, lmax, rmin, rmax;
	lmin = rmin = H_MAX;
	lmax = rmax = H_MIN;
	int mid;
	*pr = (node *)malloc(sizeof(node));
	(*pr)->lidx = l;
	(*pr)->ridx = r;
	if(l == r)
	{
		(*pr)->left = (*pr)->right = NULL;
		(*pr)->min = (*pr)->max = h[l];
		if(*pmin > h[l]) *pmin = h[l];
		if(*pmax < h[l]) *pmax = h[l];
		return;
	}
	else
	{
		mid = (l + r) / 2;
		create_segmenttree(&((*pr)->left), l, mid, &lmin, &lmax);
		create_segmenttree(&((*pr)->right), mid + 1, r, &rmin, &rmax);
		*pmin = (*pr)->min = min(lmin, rmin);
		*pmax = (*pr)->max = max(lmax, rmax);
	}
}

void query(node *r, int a, int b, int *pmin, int *pmax)
{
	int lidx = r->lidx;
	int ridx = r->ridx;
	if(r->lidx >= a && r->ridx <= b)
	{
		if(r->min < *pmin) *pmin = r->min;
		if(r->max > *pmax) *pmax = r->max;
		return;
	}
	int mid = (r->lidx + r->ridx) / 2;
	if(a <= mid) query(r->left, a, b, pmin, pmax);
	if(b > mid) query(r->right, a, b, pmin, pmax);
}

void print_segmenttree(node *r)
{
	if(!r) return;
	print_segmenttree(r->left);
	print_segmenttree(r->right);
	printf("[%d %d](%d, %d)\n", r->lidx, r->ridx, r->min, r->max);
}

void free_segmenttree(node *r)
{
	if(!r) return;
	free_segmenttree(r->left);
	free_segmenttree(r->right);
	free(r);
}

int main()
{
	int i, a, b;
	int min = H_MAX;
	int max = -1;
	while(scanf("%d %d", &n, &q) != -1)
	{
		for(i = 0; i < n; i++)
			scanf("%d", &h[i]);
		create_segmenttree(&root, 0, n - 1, &min, &max);
//		print_segmenttree(root);
		for(i = 0; i < q; i++)
		{
			scanf("%d %d", &a, &b);
			min = H_MAX;
			max = -1;
			query(root, a - 1, b - 1, &min, &max);
			printf("%d\n", max - min);
		}
		free_segmenttree(root);
	}
	return 0;
}