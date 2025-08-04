class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(s)!=0 and len(p)==0:
            return False
        elif len(s)==0 and len(p)==0:
            return True
        
        @lru_cache(maxsize=None)
        def f(i,j):
            if i<0:
                if j<0:
                    return True
                else:
                    if p[j]=='*':
                        return f(i,j-1)
                    else:
                        return False
                
            elif j<0: return False if p[0]!='*' else True

            if s[i]==p[j] or p[j]=='?':
                return f(i-1,j-1)
            elif p[j]=='*':
                for k in range(i,-1,-1):
                    if f(k,j-1):
                        return True
                return False
            return False


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        prev = [False] * (m + 1)
        curr = [False] * (m + 1)
        prev[0] = True

        for j in range(1, m + 1):
            if p[j - 1] == '*':
                prev[j] = prev[j - 1]

        for i in range(1, n + 1):
            curr[0] = False
            for j in range(1, m + 1):
                if p[j - 1] == '*':
                    curr[j] = curr[j - 1] or prev[j]
                elif p[j - 1] == '?' or p[j - 1] == s[i - 1]:
                    curr[j] = prev[j - 1]
                else:
                    curr[j] = False
            prev, curr = curr, [False] * (m + 1)

        return prev[m]

