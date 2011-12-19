#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int num;
int d[100002];
bool flag;

int ctoi(char ch)
{
	switch(ch)
	{
	case 'A':
	case 'B':
	case 'C':return 2; 
	case 'D':
	case 'E':
	case 'F':return 3; 
	case 'G':
	case 'H':
	case 'I':return 4; 
	case 'J':
	case 'K':
	case 'L':return 5;
	case 'M':
	case 'N':
	case 'O':return 6;
	case 'P':
	case 'R':
	case 'S':return 7; 
	case 'T':
	case 'U':
	case 'V':return 8; 
	case 'W':
	case 'X':
	case 'Y':return 9; 
	}
	return -1;
}

void Change(char p[],int k)
{
	char q[16];
	int i,j=0,len=strlen(p);
	for(i=0;i<len;i++)
	{
		if(p[i]>='0' && p[i]<='9')
		{
			q[j]=p[i];
			j++;
		}
		else if(p[i]>='A' && p[i]<='Z')
		{
			q[j]=ctoi(p[i])+'0';
			j++;
		}
	}
	q[j]=0;
	d[k]=atoi(q);
}

int Partition(int *a,int s,int e)
{
	int i=s,j=e+1;
	int k=a[s];
	int t;
	while(1)
	{
		while(i<=e && a[++i]<k);
		while(a[--j]>k);
		if(i>=j)
			break;
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	if(i<=e)
	{
		a[s]=a[j];
		a[j]=k;
	}
	else
	{
		a[s]=a[e];
		a[e]=k;
	}
	return j;
}

void Qsort(int *a,int s,int e)
{
	if(s>=e)
		return;
	int pos=Partition(a,s,e);
	Qsort(a,s,pos-1);
	Qsort(a,pos+1,e);
}

int main()
{
	int i;
	char s[64];
	while(scanf("%d",&num)!=-1)
	{
		flag=0;
		for(i=0;i<num;i++)
		{
			scanf("%s",s);
			Change(s,i);
		}
		Qsort(d,0,num-1);
		int temp,c,j;
		for(i=0;i<num;)
		{
			temp=d[i],c=0;
			for(j=0;;j++)
			{
				if(d[i+j]==temp)
					c++;
				else
				{
					if(c>1)
					{
						flag=1;
						char s[16],s2[16],s3[16];
						int l;
						itoa(temp,s,10);
						if((l=strlen(s))<7)
						{
							int k;
							for(k=0;k<7-l;k++)
								s3[k]='0';
							s3[k]=0;
							strcat(s3,s);
							strcpy(s,s3);
						}
						strcpy(s2,s);
						s[3]=0;
						printf("%s-%s ",s,s2+3);
						printf("%d\n",c);
					}
					i=i+c;
					break;
				}
			}
		}
		if(flag==0)
			printf("No duplicates.\n");
	}
	return 0;
}