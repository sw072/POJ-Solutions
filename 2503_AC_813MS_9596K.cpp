#include <stdio.h>
#include <string>
#include <map>
using namespace std;

typedef map<string, string> Dict;

int main()
{
	Dict dict;
	char w[16], fw[16], ch;
	string wstr, fwstr;
	while(1)
	{
		scanf("%s", w);
		scanf("%c", &ch);
		if(ch == '\n') break;
		scanf("%s", fw);
		wstr = w;
		fwstr = fw;
		dict[fwstr] = wstr;
//		dict.insert(map<string, string>::value_type(string(fw), string(w)));
	}
	strcpy(fw, w);
	do
	{
		map<string, string>::iterator it = dict.find(string(fw));
		if(it != dict.end()) printf("%s\n", it->second.data());
		else printf("eh\n");
	}while(scanf("%s", fw) != -1);

	return 0;
}