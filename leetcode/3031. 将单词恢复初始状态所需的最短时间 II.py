class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        z=[0]*len(word)
        z[0]=len(word)

        i,c,r,leng=1,0,0,0
        while i<len(word):
            leng=min(z[i-c],r-i) if i<r else 0
            while i+leng<len(word) and word[i+leng]==word[leng]:
                leng+=1
            if i+leng>r:
                r=i+leng
                c=i
            z[i]=leng
            i+=1
        
        i=k
        while i<len(word):
            if z[i]==len(word)-i:
                return i//k
            i+=k
        return i//k
