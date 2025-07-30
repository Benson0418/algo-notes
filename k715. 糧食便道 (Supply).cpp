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
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

template <typename T>
using maxpq = priority_queue<T>;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    int X[k];
    for (int i = 0; i < k; i++)
    {
        cin >> X[i];
    }

    int cost = 0;
    int head[n + 1] = {0}; // Adjacency list head
    int edges[m * 2 + 1] = {0};
    int to[m * 2 + 1] = {0};
    int weight[m * 2 + 1] = {0};
    int locked[n + 1] = {0}; // To track locked nodes
    for (int i = 1; i <= m * 2; i += 2)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = head[u];
        head[u] = i;
        to[i] = v;
        weight[i] = w;
        edges[i + 1] = head[v];
        head[v] = i + 1;
        to[i + 1] = u;
        weight[i + 1] = w;
    }
    minpq<pair<int, int>> pq; // (weight, u)
    for (auto x : X)
    {
        locked[x] = 1; // Mark locked nodes
        int a = head[x];
        while (a)
        {
            int v = to[a];
            if (!locked[v])
            { // Only add edges to unlocked nodes
                pq.push({weight[a], v});
            }
            a = edges[a];
        }
    }

    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (locked[u])
            continue;  // Skip locked nodes
        locked[u] = 1; // Lock this node
        cost += w;     // Add the weight of the edge
        for (int a = head[u]; a; a = edges[a])
        {
            int v = to[a];
            if (!locked[v])
            { // Only add edges to unlocked nodes
                pq.push({weight[a], v});
            }
        }
    }

    cout << cost << '\n';

    return 0;
}
