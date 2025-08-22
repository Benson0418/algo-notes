"""
原始碼拉車模板，與Z函數比較學習
"""
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
        manacher結論 (重要二級結論 記!!!)
        由處理後字串反推原始字串
        原始字串長==半徑-1
        原始串結尾下標==處理串結尾位置//2-1
        原始串起始下標==處理串開始位置//2

        舉個例子
        原串 abbcbbb
        處理串 #a#b#b#c#b#b#b#
        已知最長處理後回文串為下標7(#b#b#c#b#b#) rad==6
        對應原串bbcbb長度為5
        處理串結尾下標為[13] (7+6-1) 13//2-1==5
        同理起始下標為[2] (7-6+1) 2//2==1

        原串
        cabbad
        處理串 #c#a#b#b#a#d#
        已知最長處理後回文串為下標6(#a#b#b#a#) rad==5
        對應原串長為4
        處理串結尾下標[10] 原串結尾 10//2-1=4
        處理串起始下標[2] 原串結尾 2//2==1
        """
