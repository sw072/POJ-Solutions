#include "stdio.h"

int main()
{
	float len,sum;
	while(scanf("%f",&len))
	{
		if(len==0.00)
			break;
		int i;
		sum=0;
		for(i=2;;i++)
		{
			sum+=(float)1/i;
			if(sum>=len)
			{
				printf("%d card(s)\n",i-1);
				break;
			}
		}
	}
	return 0;
}