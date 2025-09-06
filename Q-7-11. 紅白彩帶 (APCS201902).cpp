#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> pa, siz, B;
    map<int,int> mp;

    DSU(int n): n(n), pa(n), siz(n,1), B(n,0) {
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }

    void add_block(int len) { mp[len]++; }
    void remove_block(int len) {
        if (--mp[len] == 0) mp.erase(len);
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (siz[a] < siz[b]) swap(a,b);

        // merge b into a
        remove_block(siz[a]);
        remove_block(siz[b]);
        siz[a] += siz[b];
        siz[b] = 0;
        pa[b] = a;
        add_block(siz[a]);
    }

    void activate(int i) {
        B[i] = 1;
        add_block(1); 
        if (i > 0 && B[i-1]) unite(i, i-1);
        if (i+1 < n && B[i+1]) unite(i, i+1);
    }

    int max_len() { return mp.rbegin()->first; }
    int min_len() { return mp.begin()->first; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    DSU dsu(n);

    for (int i=0;i<n;i++) cin >> dsu.B[i];
    for (int i=0;i<n;i++) {
        if (dsu.B[i]) {
            int j=i;
            while (j<n && dsu.B[j]) j++;
            int len = j-i;
            dsu.add_block(len);
            for (int p=i;p<j;p++) {
                dsu.pa[p]=i;
                dsu.siz[i]=len;
            }
            i = j-1;
        }
    }

    long long sum_max = 0, sum_min = 0;


    if (!dsu.mp.empty()) {
        sum_max += dsu.max_len();
        sum_min += dsu.min_len();
    }


    while (k--) {
        int e; cin >> e; e--; 
        dsu.activate(e);
        sum_max += dsu.max_len();
        sum_min += dsu.min_len();
    }

    cout << sum_max << "\n" << sum_min << "\n";
}
