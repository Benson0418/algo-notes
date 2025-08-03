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
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<tii> arr(n);
    for (int a, b, c, i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }


    sort(all(arr), [](const tii &x, const tii &y)
         { return g2(x) < g2(y); });

    vector<int> dp(m + 1, 0);

    int k = 0;
    while (k < n)
    {
        int group_id = g2(arr[k]);
        vector<tii> group;


        while (k < n && g2(arr[k]) == group_id)
            group.pb(arr[k++]);


        for (int j = m; j >= 0; --j)
        {
            int best = dp[j];
            for (const auto &item : group)
            {
                int w = g0(item), v = g1(item);
                if (j >= w)
                    best = max(best, dp[j - w] + v);
            }
            dp[j] = best;
        }
    }

    cout << dp[m] << '\n';
    return 0;
}
