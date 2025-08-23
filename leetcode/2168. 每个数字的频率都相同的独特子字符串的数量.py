class Solution:
    def equal_digit_frequency(self, s: str) -> int:
        BASE = 131
        MOD = 10**9 + 7
        n = len(s)

        ans = set()


        for i in range(len(s)):
            hashcode=0
            cnt=[0]*10
            maxCnt=0
            maxkinds=0 
            allkinds=0
            for j in range(i,len(s)):
                curval=ord(s[j])-48
                hashcode=(hashcode*BASE+ord(s[j]))%MOD

                cnt[curval]+=1
                if cnt[curval]==1:
                    allkinds+=1
                if cnt[curval]>maxCnt:
                    maxkinds=1
                    maxCnt=cnt[curval]
                elif cnt[curval]==maxCnt:
                    maxkinds+=1

                if maxkinds==allkinds:
                    ans.add(hashcode)
        return len(ans)
                
                

        return len(ans)
