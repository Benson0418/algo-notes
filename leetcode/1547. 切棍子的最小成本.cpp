class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        @lru_cache(maxsize=None)
        def sol(l,r,idl,idr):
            if idl>idr:return 0
            elif idl==idr:
                return r-l
            else:
                ans=0x3f3f3f3f3f3f3f3f
                for i in range(idl,idr+1):
                    ans=min(ans, sol(l,cuts[i],idl,i-1)+sol(cuts[i],r,i+1,idr))
                return ans+r-l
        return sol(0,n,0,len(cuts)-1)
