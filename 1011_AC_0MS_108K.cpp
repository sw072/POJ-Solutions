#include "stdio.h"
#include "iostream"
using namespace std;

int s[65];
int b[65];			//
int n, d, len;		//元素个数，

int search(int k, int res, int cnt)		//对的d[cnt]=res尝试
{  
	if(k>=n)
		return 0;
	if(cnt == len)
		return 1;
	int f = 0;
	if(res == 0)
		f = 1;
	for(int i=k; i<n; ++i)
		if(!b[i])		
		{                            
			if(s[i]+res == d)            
			{                
				b[i] = 1;                
				if(search(0, 0, cnt+1))
					return 1; 
				b[i] = 0; 
				return 0;
			}
			else if(res+s[i] < d)	
			{
				b[i] = 1;
				// 选择s[i]结点，继续搜索len组合
				if(search(i+1, res+s[i], cnt))
					return 1;
				b[i] = 0;
				// 在res=0，即段搜索起点的情况下，如果搜索失败则返回0
				// 因为此时，s[i]是从0开始搜索第一个还没有被用的结点
				// 如果有解，本次搜索必然包含s[i]，否则必然无解。
				if(f)
					return 0;
				while(i<n-1 && s[i]==s[i+1])
					++i;
			}
		}
		return 0;
}

void sort()
{
	int i,j;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-1-i; j++)
		{
			if (s[j] < s[j+1])
				swap(s[j],s[j+1]);
		}
}

int main()
{
	int i;
    while(1)		
	{
        scanf("%d", &n);
		if(!n)
            break;
		int sum = 0;
        for(i=0; i<n; ++i)		
		{
            scanf("%d", &s[i]);
            sum += s[i];
        }
        sort();							//将s由大到小排序
		for(i=s[0];i<=sum;++i)
			if(sum%i==0)
			{
				d=i;					//每段长度为d
                len=sum/i;				//分成len段
				memset(b,0,sizeof(b));
                if(search(0,0,1))
				{
					printf("%d\n",i);                
					break;        
				}
			}
    }
	return 0;
}