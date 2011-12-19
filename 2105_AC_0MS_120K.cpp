#include "stdio.h"
#include "math.h"

void main()
{
	int n;
	scanf("%d",&n);
	int i,j,k,a;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			int sum=0;
			for(k=7;k>=0;k--)
			{
				scanf("%1d",&a);
				sum+=a*(int)pow((double)2,(double)k);
			}
			if(j!=0)
				printf(".");
			printf("%d",sum);
		}
		printf("\n");
	}

}