import java.io.*;
import java.util.*;

class Main
{
	
    public static void main (String args[]) throws Exception
    {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line="";
        int RGB[][]=new int[16][3];
        int i=0,R=0,G=0,B=0;
        for(i=0;i<16;i++)
        {
        	line = stdin.readLine();
        	StringTokenizer st = new StringTokenizer(line);
	        R = Integer.parseInt(st.nextToken());
	        G = Integer.parseInt(st.nextToken());
	        B = Integer.parseInt(st.nextToken());
	        RGB[i][0]=R;
	        RGB[i][1]=G;
	        RGB[i][2]=B;
        }
		while((line = stdin.readLine())!=null)
		{
	        StringTokenizer st = new StringTokenizer(line);
	        R = Integer.parseInt(st.nextToken());
	        G = Integer.parseInt(st.nextToken());
	        B = Integer.parseInt(st.nextToken());
	        if(R==-1 && G==-1 && B==-1)
	        	break;
	        double D=Integer.MAX_VALUE;
	       	int min=0;
	        for(i=0;i<16;i++)
	        {
	        	double a=(R-RGB[i][0])*(R-RGB[i][0])+(G-RGB[i][1])*(G-RGB[i][1])+(B-RGB[i][2])*(B-RGB[i][2]);
	        	double d=Math.sqrt(a);	
	        	if(d<D)
	        	{
	        		D=d;
	        		min=i;
	        	}
	        }
	        //(0,0,0) maps to (0,0,0)
//	        char [] s=new char[36];
//	        s=("("+R+","+G +","+B+") maps to ("+RGB[i][0]+","+RGB[i][1]+","+RGB[i][2]+")");
//	        String str=new String("adsfasfs");
	        String s="("+Integer.toString(R)+","+Integer.toString(G)  +","+Integer.toString(B)+") maps to ("+Integer.toString(RGB[min][0])+","+Integer.toString(RGB[min][1])+","+Integer.toString(RGB[min][2])+")";
	        System.out.println(s);
        }
    }
}

