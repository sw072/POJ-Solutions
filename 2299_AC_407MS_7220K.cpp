#include <stdio.h>

#define N 500100

__int64 a[N], b[N];

__int64 merge(__int64 *parr, int l, int m, int r)
{
	int i = l, j = m, k = l;
	__int64 count = 0;
	while(i < m && j < r)
	{
		if(parr[i] <= parr[j])
		{
			b[k++] = parr[i++];
		}
		else
		{
			b[k++] = parr[j++];
			count += m - i;
		}
	}
	while(i < m) b[k++] = parr[i++];
	while(j < r) b[k++] = parr[j++];
	for(i = l; i < r; i++) parr[i] = b[i];
	return count;
}

__int64 merge_sort(__int64 *parr, int l, int r)
{
	if(r - l <= 1) return 0;
	int mid = (l + r) / 2;
	__int64 nl = merge_sort(parr, l, mid);
	__int64 nr = merge_sort(parr, mid, r);
	__int64 n = merge(parr, l, mid, r);
	return (nl + nr + n);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, idx;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		for(idx = 0; idx < n; idx++)
		{
			scanf("%I64d", &a[idx]);
		}
		printf("%I64d\n", merge_sort(a, 0, n));
	}

	return 0;
}