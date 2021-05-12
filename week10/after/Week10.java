package run;
import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;

public class Week10 
{ 
	public static double getRadian(double d){
		return d*Math.PI/180;
	}
    public static void main(String[] args) throws Exception 
    {
    	Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		boolean obstacleMap[][] = new boolean[N+1][N+1];
		for(int t=N;t>=1;t--) 
		{
			String line = input.next();
			for(int s=1;s<=N;s++) obstacleMap[t][s]=line.charAt(s-1)=='0'?false:true;	// no obstacle vs. obstacle
		}		
		int sPlayer = input.nextInt();
		int tPlayer = input.nextInt();
		
		double from = input.nextDouble(); // from
		double to = input.nextDouble(); // to
		input.close();
		
		from = getRadian(from);
		to = getRadian(to);

		Map map = new Map(N, obstacleMap, sPlayer, tPlayer,from,to);
		map.createShade();
		map.printShade();
    }
}


// 1. not in range
// 2. phi~ range