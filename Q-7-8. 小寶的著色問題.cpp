#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e4;
constexpr int MEDGE = 2e5;

int head[MAXN];
int edges[MEDGE];
int to[MEDGE];
int cnt;
int color[MAXN];
int que[MAXN];

void connect_edge(int u, int v) {
    to[cnt] = v;
    edges[cnt] = head[u];
    head[u] = cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        // 初始化每組測資
        memset(head, -1, n * sizeof(int));
        memset(color, -1, n * sizeof(int));
        cnt = 0;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            connect_edge(a, b);
            connect_edge(b, a); // 無向邊
        }

        bool flag = false;
        int ql, qr;
        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) continue;

            ql = 0;
            qr = 0;
            color[i] = 0;
            que[qr++] = i;

            while (ql != qr) {
                int x = que[ql++];
                for (int j = head[x]; j != -1; j = edges[j]) {
                    int nx = to[j];
                    if (color[nx] == -1) {
                        color[nx] = 1 - color[x];
                        que[qr++] = nx;
                    } else if (color[nx] == color[x]) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        cout << (flag ? "no" : "yes") << '\n';
    }

    return 0;
}
