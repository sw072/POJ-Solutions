#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 32
const char prefix[] = "|     ";

int comp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int new_dir(int level, char *f)
{
	char files[2 * LEN][LEN];
	int i, j, n = 0;
	char file[LEN];
	strcpy(file, f);
	do
	{
		if(file[0] == 'f') strcpy(files[n++], file);
		else if(file[0] == 'd')
		{
			for(j = 0; j < level; j++) printf("%s", prefix);
			printf("%s\n", file);
			scanf("%s", file);
			new_dir(level + 1, file);
		}
		else if(file[0] == ']') break;
		else if(file[0] == '*') break;
		else if(file[0] == '#') return 0;
	}while(scanf("%s", file) != -1);
	qsort(files, n, sizeof(files[0]), comp);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < level - 1; j++) printf("%s", prefix);
		printf("%s\n", files[i]);
	}
	return 1;
}

int main()
{
	int i = 0;
	char file[LEN];
	while(scanf("%s", file) != -1)
	{
		if(file[0] == '#') break;
		printf("DATA SET %d:\n", ++i);
		printf("ROOT\n");
		if(!new_dir(1, file)) break;
		printf("\n");
	}

	return 0;
}