class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @lru_cache(maxsize=None)
        def f(l, r):
            if l + 1 == r: return 0
            return min(values[l] * values[r] * values[i] + f(l, i) + f(i, r) for i in range(l + 1, r))
        return f(0, len(values) - 1)
