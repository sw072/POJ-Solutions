#include"iostream"
using namespace std;
int A[351][351];
int a[351][351];
int Max(int a,int b)
{
if(a>b)
return a;
return b;
}
int main()
{
	int n,i=0,j=0,max=0;
while(cin>>n)
{
for(i=0;i<n;i++)
for( j=0;j<=i;j++)
cin>>a[i][j];
A[0][0]=a[0][0];
A[1][0]=a[0][0]+a[1][0];
A[1][1]=a[0][0]+a[1][1];
for(i=2;i<n;i++)
for(j=0;j<n;j++)
A[i][j]=Max(A[i-1][j-1]+a[i][j],A[i-1][j]+a[i][j]);

for(i=0;i<n;i++)
if(A[n-1][i]>max)
max=A[n-1][i];
cout<<max<<endl;
for(i=0;i<=350;i++)
for(j=0;j<=350;j++)
A[i][j]=0;
max=0;
}
return 0;
}