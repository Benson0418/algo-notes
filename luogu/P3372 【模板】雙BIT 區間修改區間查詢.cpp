#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct DualBIT {
    int n;
    vector<LL> bit1, bit2;

    DualBIT(int n): n(n), bit1(n+2), bit2(n+2) {}

    int lowbit(int x) { return x & (-x); }

    void add(vector<LL> &bit, int idx, LL val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += lowbit(idx);
        }
    }

    void range_add(int l, int r, LL val) {
        add(bit1, l, val);
        add(bit1, r + 1, -val);
        add(bit2, l, val * (l - 1));
        add(bit2, r + 1, -val * r);
    }

    LL prefix_sum(vector<LL> &bit, int idx) {
        LL res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= lowbit(idx);
        }
        return res;
    }

    LL prefix_query(int idx) {
        return prefix_sum(bit1, idx) * idx - prefix_sum(bit2, idx);
    }

    LL range_sum(int l, int r) {
        return prefix_query(r) - prefix_query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<LL> A(n + 1);
    DualBIT tree(n);

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        tree.range_add(i, i, A[i]);
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r; LL val;
            cin >> l >> r >> val;
            tree.range_add(l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(l, r) << "\n";
        }
    }

    return 0;
}
