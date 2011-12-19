#include "stdio.h"
#include "iostream"
using namespace std;

int n;
short int map[101][101];

int Dp(short int a[])
{
	short int b[101];
	b[0]=a[0];
	int i;
	for(i=1;i<n;i++)
	{
//		if(a[i]>=0)
//			b[i]=b[i-1]+a[i];
//		else b[i]=a[i];
		if(b[i-1]>=0)
			b[i]=b[i-1]+a[i];
		if(b[i-1]<0)
			b[i]=a[i];

	}
	short int max=-20000;
	for(i=0;i<n;i++)
		if(b[i]>max)
			max=b[i];
	return max;
}

int Cal()
{
	short int a[101];
	int i,j,p,q;
	short int max=-20000,temp;
	for(i=0;i<n;i++)
		for(j=1;j<=n-i;j++)
		{
			memset(a,0,sizeof(a));
			for(p=0;p<n;p++)
				for(q=0;q<j;q++)
					a[p]+=map[i+q][p];
			temp=Dp(a);
			if(temp>max)
				max=temp;
		}
	return max;
}

int main()
{
	int i,j;
	while(scanf("%d",&n)!=-1)
	{
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&map[i][j]);
		short int max=Cal();
		printf("%d\n",max);
	}
	return 0;
}