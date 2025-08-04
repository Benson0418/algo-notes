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

#define __builtin_popcount(x) popcount(x)
#define __builtin_ctz(x) ctz(x)
#define __builtin_clz(x) clz(x)
#define __builtin_ffs(x) ffs(x)
#define __builtin_parity(x) parity(x)

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

    int n, W;
    cin >> n >> W;
    vector<int> dp(W + 1, 0);
    vector<pii> items;

    for (int i = 0; i < n; ++i)
    {
        int v, w, m;
        cin >> v >> w >> m;
        int k = 1;
        while (m)
        {
            if (m >= k)
            {
                items.pb({v * k, w * k});
                m -= k;
                k <<= 1;
            }
            else
            {
                items.pb({v * m, w * m});
                m = 0;
            }
        }
    }

    for (const auto &item : items)
    {
        int v = item.F, w = item.S;
        for (int j = W; j >= w; --j)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[W] << '\n';

    return 0;
}
