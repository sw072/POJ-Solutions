#include "stdio.h"

#define N 5000
typedef struct p
{
	int price;
	int len;
	unsigned long nfork;
	p *next;
} price_t;
price_t p[N];
price_t *listlen[N];
int n;
int maxlen;
unsigned int max;

void printline(price_t *point)
{
	if(!point) return;
	printline(point->next);
	printf("(%d,%d)", point->price, point->nfork);
}

void update(price_t *point, int len)
{
	int t = 0;
	if(!len) return;
	price_t *p0 = listlen[len];
	while(p0)
	{
		if(p0->price > point->price)
			t += p0->nfork;
		p0 = p0->next;
	}
	point->nfork = t;
}

int main()
{
	int i, j, k;
	price_t *point;
	bool dup, flag;
	scanf("%d", &n);
	scanf("%d", &p[0].price);
	maxlen = 1;
	listlen[maxlen] = &p[0];
	p[0].nfork = 1;
	p[0].len = 1;

	for(i = 1; i < n; i++)
	{
		scanf("%d", &p[i].price);
		k = 0;
		flag = false;
		dup = false;
		for(j = maxlen; j > 0 && !dup; j--)
		{
			point = listlen[j];
			while(1)
			{
				if(p[i].price == point->price)
				{
					dup = true;
					update(point, j - 1);
				}
				if(p[i].price < point->price)
				{
					dup = false;
					p[i].nfork += point->nfork;
					k = j + 1;
					if(k > maxlen) maxlen = k;
					flag = true;
				}
				if(!point->next) break;
				point = point->next;
			}
			if(flag) break;
		}
		if(!j && !dup)
		{
//			point->next = &p[i];
			p[i].next = listlen[1];
			listlen[1] = &p[i];
			p[i].len = 1;
			p[i].nfork = 1;
		}
		else if(flag)
		{
			p[i].next = listlen[k];
			listlen[k] = &p[i];
			p[i].len = k;
		}
	}
	//	printf("%d\n", maxlen);
	max = 0;
	point = listlen[maxlen];
	while(point)
	{
		max += point->nfork;
		point = point->next;
	}
	printf("%d %d\n", maxlen, max);
	/*
	for(i = maxlen; i > 0; i--)
	{
		printf("%3d:", i);
		point = listlen[i];
		printline(point);
		printf("\n");
	}
	*/
	return 0;
}