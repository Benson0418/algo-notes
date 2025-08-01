#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
#define g0(t) get<0>(t)
#define g1(t) get<1>(t)
#define g2(t) get<2>(t)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9 + 7;
template <typename T>
using maxpq = priority_queue<T>;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    vector<int> pA(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pA[i] = pA[i - 1] + A[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> dfs = [&](int l, int r)
    {
        if (dp[l][r] != -1)
            return dp[l][r];
        if (l == r)
        {
            dp[l][r] = 0;
            return dp[l][r];
        }
        if (l + 1 == r)
        {
            dp[l][r] = abs(A[l] - A[r]);
            return dp[l][r];
        }
        else
        {
            int ans = INF;
            for (int i = l; i < r; i++)
            {
                ans = min(ans, abs((pA[i] - pA[l - 1]) - (pA[r] - pA[i])) + dfs(l, i) + dfs(i + 1, r));
            }
            dp[l][r] = ans;
            return dp[l][r];
        }
        return dp[l][r] = 0; // Fallback return, should not be reached
    };
    cout << dfs(1, n) << "\n";

    return 0;
}
