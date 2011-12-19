import java.io.*;
import java.util.*;

class Main
{
    public static void main (String args[]) throws Exception
    {
    	String s="VWXYZABCDEFGHIJKLMNOPQRSTU";
    	char []code=s.toCharArray();
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line="";
		while((line = stdin.readLine())!=null)
		{
			if(line.equalsIgnoreCase("ENDOFINPUT"))
				return ;
			if(line.equalsIgnoreCase("START"))
			{
				char str[]=new char[201];
				while((line = stdin.readLine())!=null)
				{
					if(line.equalsIgnoreCase("END"))
						break;
						
					str=line.toCharArray();
					int i=0,lenth=line.length();
					for(i=0;i<lenth;i++)
					{
						if(str[i]>='A' && str[i]<='Z')
						{
							int k=(int)str[i]-(int)'A';
							str[i]=code[k];
						}
					}
					System.out.println(str);
					
				}
			}

        }
    }
}

