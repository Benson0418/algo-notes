class Solution:
    def strStr(self, text: str, patt: str) -> int:
        
        pi=[0]*len(patt)

        pl=0
        i=1
        while i<len(patt):
            if patt[pl]==patt[i]:
                pl+=1
                pi[i]=pl
                i+=1
            else:
                if pl==0:
                    i+=1
                else:
                    pl=pi[pl-1]
        i,j=0,0
        while (i<len(text)):
            if text[i]==patt[j]:
                i+=1
                j+=1
            else:
                if j==0:
                    i+=1
                else:
                    j=pi[j-1]
            if j>=len(patt):
                return i-j
        return -1
