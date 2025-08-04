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
