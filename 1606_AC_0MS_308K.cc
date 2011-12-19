#include "iostream"
using namespace std;

int X,Y,N;
struct w
{
	int x,y;
}q[200];
int pace[200][3];
int h,t,pos;
char step[8][32]={"","fill A","fill B","empty A","empty B","pour A B","pour B A"};

bool IsUnique(w t,int i)
{
	int k=0;
	for(k=0;k<i;k++)
		if(t.x==q[k].x && t.y==q[k].y)
			return 0;
		return 1;
}

void BFS()
{
	w temp;
	while(h<t)
	{
		if(q[h].y==N)
		{
			pos=h;
			break;
		}
		if(q[h].x!=X)							//将A倒满
		{
			temp.x=X;
			temp.y=q[h].y;
			if(IsUnique(temp,t))
			{
				q[t]=temp;
				pace[t][0]=pace[h][0]+1;
				pace[t][1]=h;
				pace[t][2]=1;
				t++;
			}
		}
		if(q[h].y!=Y)						//将B倒满
		{
			temp.y=Y;
			temp.x=q[h].x;
			if(IsUnique(temp,t))
			{
				q[t]=temp;
				pace[t][0]=pace[h][0]+1;
				pace[t][1]=h;
				pace[t][2]=2;
				t++;
				
			}
		}
		if(q[h].x!=0)
		{
			temp.x=0;						//将A倒空
			temp.y=q[h].y;
			if(IsUnique(temp,t))
			{
				q[t]=temp;
				pace[t][0]=pace[h][0]+1;
				pace[t][1]=h;
				pace[t][2]=3;
				t++;
			}
			if(q[h].y<Y)
			{
				if(Y-q[h].y>q[h].x)			//A->B
				{
					temp.x=0;
					temp.y=q[h].y+q[h].x;
					if(IsUnique(temp,t))
					{
						q[t]=temp;
						pace[t][0]=pace[h][0]+1;
						pace[t][1]=h;
						pace[t][2]=5;
						t++;
						
					}
				}
				else
				{
					temp.y=Y;
					temp.x=q[h].x-(Y-q[h].y);
					if(IsUnique(temp,t))
					{
						q[t]=temp;
						pace[t][0]=pace[h][0]+1;
						pace[t][1]=h;
						pace[t][2]=5;
						t++;	
					}
				}
			}
		}
		if(q[h].y!=0)					//将B倒空
		{
			temp.y=0;
			temp.x=q[h].x;
			if(IsUnique(temp,t))
			{
				q[t]=temp;
				pace[t][0]=pace[h][0]+1;
				pace[t][1]=h;
				pace[t][2]=4;
				t++;
				
			}

			if(q[h].x<X)
			{
				if(X-q[h].x>q[h].y)			//B->A
				{
					temp.y=0;
					temp.x=q[h].x+q[h].y;
					if(IsUnique(temp,t))
					{
						q[t]=temp;
						pace[t][0]=pace[h][0]+1;
						pace[t][1]=h;
						pace[t][2]=6;
						t++;
						
					}
				}
				else
				{
					temp.x=X;
					temp.y=q[h].y-(X-q[h].x);
					if(IsUnique(temp,t))
					{
						q[t]=temp;
						pace[t][0]=pace[h][0]+1;
						pace[t][1]=h;
						pace[t][2]=6;
						t++;
						
					}
				}
			}
		}
		h++;
	}
}

void Output(int i)
{
	if(pace[i][1]==0)
	{
		cout<<step[pace[i][2]]<<endl;
		return;
	}
	Output(pace[i][1]);
	cout<<step[pace[i][2]]<<endl;
}

int main()
{
	while(cin>>X>>Y>>N)
	{
		q[0].x=0;
		q[0].y=0;
		h=0;
		t=1;
		BFS();
		Output(pos);
		cout<<"success"<<endl;
		memset(pace,0,sizeof(pace));
	}
	
	return 0;
}