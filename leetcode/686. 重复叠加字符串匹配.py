class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:

        pi=[0]*len(b)
        pl,i=0,1
        while (i<len(b)):
            if b[pl]==b[i]:
                pl+=1
                pi[i]=pl
                i+=1
            else:
                if pl==0:
                    i+=1
                else:
                    pl=pi[pl-1]
        i,j,cnt=0,0,0
        while (cnt<=(len(b)+len(a)-1)//len(a)):
            if i==len(a):
                i=0
                cnt+=1
            if a[i]==b[j]:
                i+=1
                j+=1
            else:
                if j==0:
                    i+=1
                else:
                    j=pi[j-1]
            if j==len(b):
                return cnt+1
                break
        return -1
        
        
            
