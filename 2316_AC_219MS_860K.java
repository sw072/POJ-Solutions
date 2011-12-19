import java.io.*;
import java.util.*;

class Main
{
	
    public static void main (String args[]) throws Exception
    {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line="";
		int num[]=new int[16],i,lenth=0;
		for(i=0;i<16;i++)
			num[i]=0;
		line = stdin.readLine();
		lenth=line.length();
		char s[]=new char[16];
		char str[]=new char[16];
		s=line.toCharArray();
		while((line = stdin.readLine())!=null)
		{
//			if(line.equalsIgnoreCase("0000")) break;
	        str=line.toCharArray();
	       	int k=0,len=line.length();
	       	for(k=0;k<len;k++)
	       	{
	       		num[k]+=(int)(str[k]-'0');
	       	}
        }
        for(i=0;i<lenth;i++)
        {
        	num[i]=(num[i]+(int)(s[i]-'0'))%10;
        	System.out.print(num[i]);
        }
        System.out.print('\n');
    }
}

