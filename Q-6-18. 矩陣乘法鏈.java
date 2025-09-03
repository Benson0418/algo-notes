import java.util.*;
import java.io.*;


public class Main {
	public static int MAXN = 200;
	public static int[] p = new int[200];
	public static int[][] dp = new int[200][200];
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer in  = new StreamTokenizer(br);
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		in.nextToken();
		int n = (int) in.nval;
		for (int i = 0;i<=n;++i){
			in.nextToken();
			p[i] = (int) in.nval;
		}
		for (int i=0;i<=n;++i){
			Arrays.fill(dp[i], -1);
		}	
		f(0,n);
		out.println(dp[0][n]);
		out.close();
		br.close();
		
	}

	public static int f(int l,int r){
		if (dp[l][r]!=-1) return dp[l][r];
		if (l+1>=r) {
			dp[l][r]=0;
			return 0;
		}
		if (l+2 == r) {
			dp[l][r]=p[l]*p[l+1]*p[r];
			return dp[l][r];
		}
		int e=Integer.MAX_VALUE;
		for (int i = l+1; i<r;++i){
			e=Math.min(e,p[l]*p[i]*p[r]+f(l,i)+f(i,r));
			
		}
		dp[l][r]=e;
		return dp[l][r];
	}
}
