# 題目來源 https://leetcode.cn/problems/boolean-evaluation-lcci/description/
class Solution:
    def countEval(self, s: str, result: int) -> int:
        dp=[[[-1,-1] for _ in range(len(s))] for _z in range(len(s))]
        def f(l,r) -> list:
            if dp[l][r][0]!=-1: return dp[l][r]
            if l==r:
                dp[l][r]=[0,1] if int(s[l]) else [1,0]
                return dp[l][r]
            if l+2==r:
                if s[l+1]=='&':
                    dp[l][r]=[0,1] if int(s[l])&int(s[r]) else [1,0]
                elif s[l+1]=='|':
                    dp[l][r]=[0,1] if int(s[l])|int(s[r]) else [1,0]
                else:
                    dp[l][r]=[0,1] if int(s[l])^int(s[r]) else [1,0]
                return dp[l][r]
            else: 
                S0,S1=0,0
                for i in range(l+1,r,2):
                    A0,A1=f(l,i-1)
                    B0,B1=f(i+1,r)
                    if s[i]=='&':
                        S0+=A0*B0+A1*B0+A0*B1
                        S1+=A1*B1
                    elif s[i]=='|':
                        S0+=A0*B0
                        S1+=A1*B0+A0*B1+A1*B1
                    else:
                        S0+=A0*B0+A1*B1
                        S1+=A1*B0+A0*B1
                dp[l][r]=[S0,S1]
                return dp[l][r]
        E=f(0,len(s)-1)
        return E[1] if result else E[0]


