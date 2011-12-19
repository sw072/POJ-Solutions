#include <stdio.h>
#include <queue>
using namespace std;

#define N 101

bool flag[N][N];
struct state
{
	short int A, B;
	short int nstep;
}s;

short int A, B, C;
short int path[N * 10][2];
short int idx; 
//0 FILL(1); 1 DROP(1); 2 POUR(1,2); 3 FILL(2); 4 DROP(2); 5 POUR(2,1)
int bfs()
{
	queue<state> q;
	q.push(s);
	state curr, next;
	path[0][0] = path[0][1] = -1;
	idx = 1;
	int i = -1;
	while(!q.empty())
	{
		curr = q.front();
		i++;
		q.pop();
		next.nstep = curr.nstep + 1;
		if(curr.A < A)
		{
			next.A = A;
			next.B = curr.B;
			if(!flag[next.A][next.B])
			{
				flag[next.A][next.B] = true;
				q.push(next);
				path[idx][0] = i;
				path[idx][1] = 0;
				idx++;
				if(next.A == C || next.B == C) return next.nstep;
			}
		}
		if(curr.A)
		{
			next.A = 0;
			next.B = curr.B;
			if(!flag[next.A][next.B])
			{
				flag[next.A][next.B] = true;
				q.push(next);
				path[idx][0] = i;
				path[idx][1] = 1;
				idx++;
				if(next.A == C || next.B == C) return next.nstep;
			}
		}
		if(curr.B < B && curr.A)
		{
			next.B = curr.B + curr.A;
			if(next.B > B)
			{
				next.A = next.B - B;
				next.B = B;
			}
			else next.A = 0;
			if(!flag[next.A][next.B])
			{
				flag[next.A][next.B] = true;
				q.push(next);
				path[idx][0] = i;
				path[idx][1] = 2;
				idx++;
				if(next.A == C || next.B == C) return next.nstep;
			}
		}
		if(curr.B < B)
		{
			next.A = curr.A;
			next.B = B;
			if(!flag[next.A][next.B])
			{
				flag[next.A][next.B] = true;
				q.push(next);
				path[idx][0] = i;
				path[idx][1] = 3;
				idx++;
				if(next.A == C || next.B == C) return next.nstep;
			}
		}
		if(curr.B)
		{
			next.A = curr.A;
			next.B = 0;
			if(!flag[next.A][next.B])
			{
				flag[next.A][next.B] = true;
				q.push(next);
				path[idx][0] = i;
				path[idx][1] = 4;
				idx++;
				if(next.A == C || next.B == C) return next.nstep;
			}
		}
		if(curr.A < A && curr.B)
		{
			next.A = curr.A + curr.B;
			if(next.A > A)
			{
				next.B = next.A - A;
				next.A = A;
			}
			else next.B = 0;
			if(!flag[next.A][next.B])
			{
				flag[next.A][next.B] = true;
				q.push(next);
				path[idx][0] = i;
				path[idx][1] = 5;
				idx++;
				if(next.A == C || next.B == C) return next.nstep;
			}
		}
	}
	return -1;
}

void print_path(int k)
{
	if(path[k][1] == -1) return;
	print_path(path[k][0]);
	switch(path[k][1])
	{
	case 0:printf("FILL(1)\n"); break;
	case 1:printf("DROP(1)\n"); break;
	case 2:printf("POUR(1,2)\n"); break;
	case 3:printf("FILL(2)\n"); break;
	case 4:printf("DROP(2)\n"); break;
	case 5:printf("POUR(2,1)\n"); break;
	default: /* error */ break;
	}
}

int main()
{
	scanf("%d%d%d", &A, &B, &C);
	s.A = 0;
	s.B = 0;
	s.nstep = 0;
	memset(flag, 0, sizeof(flag));
	flag[s.A][s.B] = true;
	int res = bfs();
	if(res >= 0)
	{
		printf("%d\n", res);
		print_path(idx - 1);
	}
	else printf("impossible\n");

	return 0;
}