    function<int(int, int, int, int)> solve = [&](int limit, int col, int left, int right) -> int {
        if (col == limit) return 1;
        int ans = 0;
        int candidate = limit & ~(col | left | right);
        while (candidate) {
            int place = candidate & -candidate; // 取最右邊的1
            candidate ^= place; // 清除該位
            ans += solve(limit,
                         col | place,
                         (left | place) << 1,
                         (right | place) >> 1);
        }
        return ans;
    };
