class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        prime=[0]*(n//2+1)
        cnt=0
        isPrime=[True]*(n+1)
        isPrime[0]=False
        isPrime[1]=False

        for i in range(2,n):
            if isPrime[i]:
                prime[cnt]=i
                cnt+=1
            
            for j in range(cnt):
                if i*prime[j]>=n:
                    break
                isPrime[i*prime[j]]=False
                if i%prime[j]==0:
                    break
        return cnt
