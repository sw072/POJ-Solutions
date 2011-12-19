#include "stdio.h"
#include "string.h"

char tmap[19][16]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char hmap[][16]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int hday,hyear,hmonth;

int tday,tyear;			//一年260天
char tmonth[16];

int Find(char map[][16],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp(tmonth,map[i])==0)
			return i;
		return -1;
}

void Change()
{
	int sum=365*tyear,m;
	m=Find(tmap,19);
	sum+=20*(m)+tday;
	hyear=sum/260;
	sum-=260*hyear;
	hday=sum%13;
	hmonth=sum%20;
}

int main()
{
	int n,i;
	char ch;
	scanf("%d",&n);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d%c%s%d",&tday,&ch,tmonth,&tyear);
		Change();
		printf("%d %s %d\n",hday+1,hmap[hmonth],hyear);
	}
	return 0;
}