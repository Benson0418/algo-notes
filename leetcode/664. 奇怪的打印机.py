class Solution:
    def strangePrinter(self, s: str) -> int:
        
        dp = [[0]*len(s) for _ in range(len(s))]
        for k in range(len(s)):
            for i in range(len(s)-k):
                j=i+k
                if i==j:
                    dp[i][j]=1
                elif s[i]==s[j]:
                    dp[i][j]=dp[i][j-1]
                else:
                    ans=0x3f3f3f3f
                    for q in range(i,j):
                        ans=min(ans,dp[i][q]+dp[q+1][j])
                    dp[i][j]=ans
        return dp[i][len(s)-1]
        


        '''
        @cache
        def f(i,j):
            if i==j:
                return 1
            elif s[i]==s[j]:
                return f(i,j-1)
            ans=0x3f3f3f3f3f3f3f3f
            for k in range(i,j):
                ans=min(ans,f(i,k)+f(k+1,j))
            return ans
        return f(0,len(s)-1)
        '''
