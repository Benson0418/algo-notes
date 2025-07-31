class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums=[1]+nums+[1]
        print(*nums)
        dp=[[0]*len(nums) for _ in range(len(nums))]
        def f(l,r):
            if dp[l][r]!=0: return dp[l][r]
            if l+1>=r:return 0
            if l+2==r:
                dp[l][r]=nums[l]*nums[l+1]*nums[r]
                return dp[l][r]
            else:
                res=0
                for i in range(l+1,r):
                    res=max(res,nums[l]*nums[i]*nums[r]+f(l,i)+f(i,r))
                dp[l][r]=res
                return dp[l][r]

        return f(0,len(nums)-1)
