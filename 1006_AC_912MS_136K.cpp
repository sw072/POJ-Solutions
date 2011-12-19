#include "stdio.h"
#include "iostream"
using namespace std;

int sp,se,si,s;

int main()
{
	int i,max,same,c=0;
	while(scanf("%d%d%d%d",&sp,&se,&si,&s))
	{
		if(sp==-1 && se==-1 && si==-1 && s==-1)
			break;
		c++;
		printf("Case %d: the next triple peak occurs in ",c);
		if(sp==se && sp==si)
		{
			printf("%d",21252-s);
			printf(" days.\n");
			continue;
		}
		max=sp;
		if(se>max)
			max=se;
		if(si>max)
			max=si;
		for(i=max+1;;i++)
			if((i-sp)%23==0 && (i-se)%28==0 && (i-si)%33==0)
			{
				same=i;
				break;
			}
		if(same<s)
			printf("%d",same-s+21252);
		else if(same-s>21252)
			printf("%d",same-s-21252);
		else printf("%d",same-s);
		printf(" days.\n");
	}
	return 0;
}