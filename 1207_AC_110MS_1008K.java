import java.io.*;
import java.util.*;

class Main
{
	static int Cal(int min,int max)
	{
		int maxcount=0;
		int i;
		for(i=min;i<=max;i++)
		{
			int n=i;
			int count=1;
			while(n>1)
			{
				if(n%2==0)
				{
					n=n/2;	
				}
				else
				{
					n=3*n+1;	
				}
				count++;
			}
			if(count>maxcount)
				maxcount=count;
		}
		return maxcount;
	}
	
    public static void main (String args[]) throws Exception
    {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line="";
		while((line = stdin.readLine())!=null)
		{
	        StringTokenizer st = new StringTokenizer(line);
	        int a = Integer.parseInt(st.nextToken());
	        int b = Integer.parseInt(st.nextToken());
	        
	        System.out.print(a);
	        System.out.print(" ");
	        System.out.print(b);
	        System.out.print(" ");		//a_b_
	        int mc=0;
	        if(a>b)
		    {
		      	  mc=Cal(b,a);
		    }
		    else mc=Cal(a,b);
		    System.out.println(mc);
        }
    }
}

