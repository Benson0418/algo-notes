class Solution:
    def canIWin(self, CI: int, T: int) -> bool:
        if CI >= T:
            return True
        if CI * (CI + 1) // 2 < T:
            return False

        dp = [0] * (1 << CI)  

        def dfs(status, rest):
            if rest <= 0:
                return False
            if dp[status] != 0:
                return dp[status] == 1

            for i in range(CI):
                if status & (1 << i): 
                    if not dfs(status ^ (1 << i), rest - (i + 1)):
                        dp[status] = 1
                        return True

            dp[status] = -1
            return False

        return dfs((1 << CI) - 1, T)
