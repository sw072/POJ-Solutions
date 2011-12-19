#include "iostream"
using namespace std;

char s[8];
int num[200],n,k1[200],k2[200],c=0;

void Change()
{
	int m[200],i,j=1,q;
	c=0;
	i=5;
	while(s[i]=='0')
		i--;
	c=i;q=c;
	while(s[i]!='.')
		i--;
	c=c-i;
	if(c==0)
	{
		i=0;
		while(s[i]!='.')
		{
			m[i+1]=s[i]-'0';
			i++;
		}
		for(i=q+1;i<6;i++)
			m[i]=-1;
	}
	else
	{
		for(i=0;i<6;i++)
		{
			if(s[i]!='.')
			{
				m[j]=s[i]-'0';
				j++;
			}
		}
	while(m[i]==0)
	{
		m[i]=-1;
		i--;
	}

		i=1;
		while(m[i]==0)
		{
			m[i]=-1;
			i++;
		}
		i=5;
		while(m[i]==0)
		{
			m[i]=-1;
			i--;
		}
	}
	j=1;
	for(i=5;i>=1;i--)
		if(m[i]!=-1)
		{
			num[j]=m[i];
			j++;
		}
	num[0]=j-1;
}

void Mult(int a[],int b[],int *s)			//s=a*b
{
	int i,j,max,carry,k;
	for(i=1;i<=b[0];i++)
	{
		carry=0;
		for(j=1;j<=a[0];j++)
		{
			k=s[i+j-1]+b[i]*a[j]+carry;
			s[i+j-1]=k%10;
			carry=k/10;
        }
        if(carry)
          s[i+a[0]]=carry%10;
	}
	max=a[0]+b[0]-1;
	while(carry)  
    {
       s[++max]=carry%10;
       carry/=10;
    }
	s[0]=max;
}

void Copy(int a[],int b[])
{
	int i;
	for(i=0;i<200;i++)
		a[i]=b[i];
}

void Print(int *s)
{
	int i;
	if(c*n>=s[0])
	{
		printf(".");
		for(i=0;i<c*n-s[0];i++)
			printf("0");
		for(i=s[0];i>=1;i--)
			printf("%d",s[i]);
	}
	else
		for(i=s[0];i>=1;i--)
		{
			if(i==c*n)
				printf(".");
			printf("%d",s[i]);
		}
	printf("\n");
}

int main()
{
	int i;
	while(scanf("%s%d",s,&n)!=-1)
	{
		memset(num,0,sizeof(num));
		memset(k1,0,sizeof(k1));
		memset(k2,0,sizeof(k2));
		Change();
		Copy(k1,num);
		for(i=0;i<n-1;i++)
		{
			memset(k2,0,sizeof(k2));
			Mult(k1,num,k2);	//k2=k1*num
			Copy(k1,k2);		//k1=k2
		}
		if(n>1)
			Print(k2);
		else
			Print(k1);
	}

	return 0;
}