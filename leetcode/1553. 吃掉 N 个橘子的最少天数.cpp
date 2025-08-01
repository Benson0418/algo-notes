@lru_cache(maxsize=None)
def f(cnt):
    if cnt<=1:
        return cnt
    return min(cnt%2+f(cnt//2),cnt%3+f(cnt//3))+1
class Solution:
    def minDays(self, n: int) -> int:
        return f(n)
