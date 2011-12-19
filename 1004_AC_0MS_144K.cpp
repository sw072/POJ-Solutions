#include "iostream"
using namespace std;

int main()
{
	int i;
	float sum=0,m;
	while(scanf("%f",&m)!=-1)
	{
		sum=0;
		sum+=m;
		for(i=1;i<12;i++)
		{
			scanf("%f",&m);
			sum+=m;
		}
		printf("$%.2f\n",sum/12);
	}
	return 0;
}