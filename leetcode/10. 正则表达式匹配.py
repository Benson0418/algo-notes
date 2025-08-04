class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        @cache
        def f(i,j): # i spointer, j ppointer
            if i<0:
                if j<0:
                    return True
                if p[j]!='*':
                    return False
                return f(i,j-2)
            elif j<0:
                return False

            if p[j]=='*':

                if s[i]==p[j-1] or p[j-1]=='.':
                    return f(i,j-2) or f(i-1,j)
                else:
                    return f(i,j-2)
            
            elif s[i]==p[j] or p[j]=='.':
                return f(i-1,j-1)
            else:
                return False
        return f(len(s)-1,len(p)-1)



