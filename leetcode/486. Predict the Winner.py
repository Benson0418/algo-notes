class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        @lru_cache(maxsize=None)
        def f(l: int,r: int) -> int:
            if l==r:
                return nums[l]
            elif l+1==r:
                return max(nums[l],nums[r])
            else:
                return max(nums[l]+min(f(l+2,r),f(l+1,r-1)),nums[r]+min(f(l+1,r-1),f(l,r-2)))

        return f(0,len(nums)-1)>=sum(nums)-f(0,len(nums)-1)
