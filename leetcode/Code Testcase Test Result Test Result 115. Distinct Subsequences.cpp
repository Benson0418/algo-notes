class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n=len(t)
        m=len(s)
        L=[[0]*(n+1) for _ in range(m+1)]
        for i in range(0,m+1,1):
            L[i][0]=1
        for i in range(1,m+1,1):
            for j in range(1,n+1,1):
                if (s[i-1]==t[j-1]):
                    L[i][j]=L[i-1][j-1]+L[i-1][j]
                else:
                    L[i][j]=L[i-1][j]
        return L[m][n]

