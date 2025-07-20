#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto& row : grid) {
        for (auto& cell : row) {
            cin >> cell;
        }
    }

    int ans = 0;
    int res = 0;

    bitset<30> pdia, ndia; 
    bitset<15> col;        

    function<void(int, int)> solve = [&](int x, int y) {
        if (x >= n) {
            ans = max(ans, res);
            return;
        }
        if (y >= n) {
            solve(x + 1, 0);
            return;
        }

        //
        solve(x, y + 1);

        int pd = x + y;
        int nd = x - y + n - 1;

        if (!pdia[pd] && !ndia[nd] && !col[y]) {
            pdia[pd] = ndia[nd] = col[y] = 1;
            res += grid[x][y];
            solve(x + 1, 0);
            res -= grid[x][y];
            pdia[pd] = ndia[nd] = col[y] = 0;
        }
    };

    solve(0, 0);
    cout << ans << '\n';
    return 0;
}
