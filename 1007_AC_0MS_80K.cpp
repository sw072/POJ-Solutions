#include "stdio.h"
#include "string.h"

int n,m;
char map[102][52];
struct Turn
{
	int num;
	int ninver;
}t[102];

int n_of_inver(char s[])
{
	int i,j,c=0;
	for(i=0;i<m-1;i++)
		for(j=i+1;j<m;j++)
		{
			if(s[i]>s[j])
				c++;
		}
	return c;
}

void Sort()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
			if(t[j].ninver>t[j+1].ninver)
			{
				Turn temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
}

void Print()
{
	int i;
	for(i=0;i<n;i++)
		printf("%s\n",map[t[i].num]);
}

int main()
{
	int i;
	while(scanf("%d%d",&m,&n)!=-1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",map[i]);
			t[i].num=i;
			t[i].ninver=n_of_inver(map[i]);
		}
		Sort();
		Print();
	}

	return 0;
}