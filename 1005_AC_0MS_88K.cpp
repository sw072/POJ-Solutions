#include "stdio.h"
#include "math.h"

void Cal(float x,float y)
{
	double r=(float)sqrt(double(x*x)+double(y*y));
	double n=(r*r*3.14159265)/100;
	printf("This property will begin eroding in year %.0f.\n",floor(n)+1);
}

int main()
{
	int n,i;
	float x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&x,&y);
		printf("Property %d: ",i+1);
		Cal(x,y);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}