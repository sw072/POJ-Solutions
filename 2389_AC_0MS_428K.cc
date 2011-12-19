#include "stdio.h"
#include "string.h"

int add(char dst[], int dlen, char adder[], int alen)
{
	int maxlen = dlen > alen ? dlen : alen;
	int i;
	int c = 0;
	for(i = 0; i < maxlen; i++)
	{
		c = dst[i] + adder[i] + c / 10;
		dst[i] = c % 10;
	}
	if(c >= 10)
	{
		dst[i] = 1;
		maxlen++;
	}
	return maxlen;
}

int mul(char a[], int alen, char b[], int blen, char res[])
{
	char t[20001];
	int reslen = 0;
	int i, j;
	int c = 0;
	for(i = 0; i < blen; i++)
	{
		if(b[i] == 0) continue;
		c = 0;
		memset(t, 0,20001);
		for(j = 0; j < alen; j++)
		{
			c = a[j] * b[i] + c / 10;
			t[j + i] = c % 10;
		}
		if(c >= 10)
		{
			t[j + i] = c / 10;
			j++;
		}
		reslen = add(res, reslen, t, j + i);
	}
	return reslen;
}

int main()
{
	char astr[10001], bstr[10001];
	char a[10001], b[10001];
	char c[20001];
	int alen, blen, clen;
	int i = 0;

	while(scanf("%s%s", astr, bstr) != -1)
	{
		alen = strlen(astr);
		blen = strlen(bstr);
		if((alen == 1 && astr[0] == '0') || (blen == 1 && bstr[0] == '0'))
		{
			printf("0\n");
			continue;
		}
		for(i = 0; i < alen; i++)
			a[i] = astr[alen - i - 1] - '0';
		for(i = 0; i < blen; i++)
			b[i] = bstr[blen - i - 1] - '0';
		memset(c, 0, 20001);
		clen = mul(a, alen, b, blen, c);
		for(i = clen - 1; i >= 0; i--)
			printf("%c", c[i] + '0');
		printf("\n");
	}

	return 0;
}