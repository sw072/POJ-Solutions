#include <stdio.h>
#include <string.h>

#define N 15

int a[N], b[N], res[N];
int la, lb, lr;

int main()
{
	int n;
	int i, j, carry;
	char ch;
	scanf("%d\n", &n);
	for(i = 0; i < n; i++)
	{
		la = lb = lr = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(res, 0, sizeof(res));
		while(scanf("%c", &ch) != -1)
		{
			if(ch == ' ') break;
			a[la++] = ch - '0';
		}
		while(scanf("%c", &ch) != -1)
		{
			if(ch == '\n') break;
			b[lb++] = ch - '0';
		}
		lr = la > lb ? la : lb;
		carry = 0;
		for(j = 0; j < lr; j++)
		{
			res[j] = a[j] + b[j] + carry;
			if(res[j] > 9)
			{
				res[j] = res[j] % 10;
				carry = 1;
			}
			else carry = 0;
		}
		if(carry)
		{
			res[lr] = 1;
			lr++;
		}
		for(j = 0; j < lr; j++)
			if(!res[j]) continue;
			else break;
		for(; j < lr; j++) printf("%c", res[j] + '0');
		printf("\n");
	}

	return 0;
}