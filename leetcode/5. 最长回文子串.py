class Solution:
    def longestPalindrome(self, s: str) -> str:
        w="#"+"#".join(s)+"#"
        
        p = [0]*len(w)
        center,res = 0,0
        c,r,rad = 0,0,0
        for i in range(len(w)):
            rad = min(p[2*c-i],r-i) if r>i else 1
            while (i+rad<len(w) and i-rad>=0 and w[i+rad]==w[i-rad]):
                rad+=1
            if i+rad>r:
                r=i+rad
                c=i
            if rad>res:
                center=i
                res=rad
            p[i]=rad
        start = (center-res+1)//2
        end = (center+res-1)//2
        return s[start:end]
        """
        manacher結論 (重要!!!)
        由處理後字串反推原始字串
        原始字串長==半徑-1
        原始串結尾下標==處理串結尾位置//2-1
        原始串起始下標==處理串開始位置//2
        """
