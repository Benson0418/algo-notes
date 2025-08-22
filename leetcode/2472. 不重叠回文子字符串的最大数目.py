class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        
        w="#"+"#".join(s)+"#"
        p=[0]*len(w)
        c,r,rad=0,0,0
        res=0
        for i in range(len(w)):
            rad=min(p[2*c-i],r-i) if r>i else 1
            while i+rad<len(w) and i-rad>=0 and w[i+rad]==w[i-rad] and rad<=k:
                rad+=1
            if i+rad>r:
                r=i+rad
                c=i
            p[i]=rad
        
        time=-1
        print(p)
        for i in range(len(w)):
            if p[i]-1==k and time<i-p[i]+1:
                res+=1
                time=i+p[i]-1 if (i+p[i]-1)&1 else i+p[i]-2 #sharp奇數串覆蓋到sharp是可以重複利用的
        return res



