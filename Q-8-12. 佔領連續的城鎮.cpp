#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200004;

int idx;
int W[MAXN];
int head[MAXN];
int edges[MAXN];
int to[MAXN];
long long dp[MAXN];
long long ans = 0;
void addEdge(int u, int v) {
    to[++idx] = v;
    edges[idx] = head[u];
    head[u] = idx;
}

void dfs(int u, int parent) {
    dp[u] = W[u]; 
    for (int i = head[u]; i > 0; i = edges[i]) {
        int v = to[i];
        if (v == parent) continue;
        dfs(v, u);
        if (dp[v] > 0) dp[u] += dp[v]; 
    }
    ans = max(ans, dp[u]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &W[i]);

    int u, v;
    idx = 0;
    memset(head, 0, sizeof(head));

    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(1, -1);

    printf("%lld\n", ans);
    return 0;
}
