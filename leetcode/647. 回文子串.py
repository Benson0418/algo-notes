class Solution:
    def countSubstrings(self, s: str) -> int:
        
        w="#"+"#".join(s)+"#"
        c,r,rad=0,0,0
        p=[0]*len(w)
        for i in range(len(w)):
            rad=min(p[2*c-i],r-i) if r>i else 1
            while i+rad<len(w) and i-rad>=0 and w[i+rad]==w[i-rad]:
                rad+=1
            if i+rad>r:
                r=i+rad
                c=i
            p[i]=rad

        res=0
        for i in range(len(w)):
            if i&1:
                res+=(p[i]+1)//2
            else:
                res+=(p[i])//2
        return res
