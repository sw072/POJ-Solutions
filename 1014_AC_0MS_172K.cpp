#include "stdio.h"

int num[6];
int sumval;

void dfs(int val, bool &flag, int sum, int idx)
{
	if(sum == val)
	{
		flag = true;
		return;
	}
	if(flag) return;
	int i;
	for(i = 0; i <= num[idx] && idx < 6; i++)
	{
		dfs(val, flag, sum + i * (idx + 1), idx + 1);
	}
}

bool can_divided(int val)
{
	bool flag = false;
	dfs(val, flag, 0, 0);
	return flag;
}

int main()
{
	int i, c;
	c = 0;
	while(1)
	{
		c++;
		sumval = 0;
		for(i = 0; i < 6; i++)
		{
			scanf("%d", &num[i]);
			num[i] = num[i] % 30;
			sumval += (i + 1) * num[i];
		}
		if(num[0]  == 0 && num[1]  == 0 && num[2]  == 0 && num[3]  == 0 && num[4]  == 0 && num[5]  == 0) break;
		printf("Collection #%d:\n", c);
		if(sumval % 2)
		{
			printf("Can't be divided.\n");
		}
		else
		{
			if(can_divided(sumval / 2))
			{
				printf("Can be divided.\n");
			}
			else
			{
				printf("Can't be divided.\n");
			}
		}
		printf("\n");
	}

	return 0;
}