class Solution:
    def minInsertions(self, s: str) -> int:
        
        dp = [[-1]*len(s) for _ in range(len(s))]
        def f(l: int, r: int) -> int:
            if (dp[l][r]!=-1): return dp[l][r]
            if l==r:
                dp[l][r]=0
                return 0
            elif l+1==r:
                dp[l][r]= 0 if s[l]==s[r] else 1
                return dp[l][r]
            elif s[l]==s[r]:
                dp[l][r]=f(l+1,r-1)
                return dp[l][r]
            else:
                dp[l][r]= min(f(l+1,r), f(l,r-1)) +1
                return dp[l][r]
        res=f(0,len(s)-1)
        return res
