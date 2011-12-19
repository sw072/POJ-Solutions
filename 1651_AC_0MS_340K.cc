#include "iostream"
#include "limits.h"
using namespace std;

int n,a[102];
int f[102][102];

int Cal()
{
	int d,i,j,k,temp,min;
	for(d=1;d<=n-2;d++)
		for(i=1;i<n-d;i++)
		{
			min=INT_MAX;
			j=i+d-1;
			for(k=i;k<=j;k++)
			{
				if(k==i)
					temp=a[k]*a[i-1]*a[j+1]+f[k+1][j];
				else if(k==j)
					temp=a[k]*a[i-1]*a[j+1]+f[i][k-1];
				else
					temp=a[k]*a[i-1]*a[j+1]+f[i][k-1]+f[k+1][j];
				if(temp<min)
					min=temp;
			}
			f[i][j]=min;
		}
	return f[1][n-2];
	
}

int main()
{
	int i;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<Cal()<<endl;
	}
	return 0;
}