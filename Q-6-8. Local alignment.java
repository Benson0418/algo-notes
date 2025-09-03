import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s1=sc.nextLine(),s2=sc.nextLine();
		int[][] dp = new int[2][s1.length()+1];
		int wc=1; //JAVA沒有swap，用wc代表curr，1-wc代表prev
		int res=0;
		for (int i=1;i<=s2.length();++i){
			for (int j=1;j<=s1.length();++j){
				dp[wc][j]=Math.max(Math.max(dp[1-wc][j]-3,dp[wc][j-1]-3), Math.max(dp[1-wc][j-1]-5, 0));
				if (s2.charAt(i-1)==s1.charAt(j-1)) {
					dp[wc][j]=Math.max(dp[wc][j],dp[1-wc][j-1]+8);
				}
				res=Math.max(res, dp[wc][j]);
			}
			wc=1-wc;
		}
		System.out.println(res);
	}
}
