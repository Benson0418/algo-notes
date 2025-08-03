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

/*
若使用less_equal<T>，可實現多重集的功能
但此時upper_bound與lower_bound的功能互換
且erase只能透過upper_bound存取，才能達成預期刪除結果
*/

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

    int n, m;
    cin >> n >> m;
    vector<int> cost(m), val(m), rel(m);
    vector<vector<int>> follow(n);
    for (int i = 0; i < m; ++i)
    {
        int v, p, q;
        cin >> v >> p >> q;
        cost[i] = v;
        val[i] = p * v;
        rel[i] = q;
        if (q == 0)
            continue;
        follow[q - 1].pb(i);
    }

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        if (rel[i] == 0)
        {
            for (int j = n; j >= cost[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
                if (!follow[i].empty() && j - cost[i] - cost[follow[i][0]] >= 0)
                {
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[follow[i][0]]] + val[i] + val[follow[i][0]]);
                }
                if (sz(follow[i]) == 2)
                {
                    if (j - cost[i] - cost[follow[i][1]] >= 0)
                    {
                        dp[j] = max(dp[j], dp[j - cost[i] - cost[follow[i][1]]] + val[i] + val[follow[i][1]]);
                    }
                    if (j - cost[i] - cost[follow[i][0]] - cost[follow[i][1]] >= 0)
                    {
                        dp[j] = max(dp[j], dp[j - cost[i] - cost[follow[i][0]] - cost[follow[i][1]]] + val[i] + val[follow[i][0]] + val[follow[i][1]]);
                    }
                }
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
