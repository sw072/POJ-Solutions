#include "iostream"
using namespace std;

#define max(a, b) (a)>(b)?(a):(b)

int N,M;
int W[3403];
int D[3403];
int V[12881];

int MaxD()
{
	int i = 0, j = 0;
	for(i = 0; i < N; i++)
		for(j = M; j >= W[i]; j--)
		{
			V[j] = max(V[j], D[i] + V[j - W[i]]);
		}
	return V[M];
}

int main()
{
	int i;
	while(cin>>N>>M)
	{
		for(i = 0; i < N; i++)
			cin>>W[i]>>D[i];
		memset(V, 0, 12881);
		cout<<MaxD()<<endl;
	}

	return 0;
}