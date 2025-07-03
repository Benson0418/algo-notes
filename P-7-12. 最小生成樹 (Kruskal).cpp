#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
#define pb push_back
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

#define Tp tuple<int,int,int>
#define u(x) (get<0>(x))
#define v(x) (get<1>(x))
#define w(x) (get<2>(x))

bool cmp(Tp A, Tp B){
    return w(A)<w(B);
}

struct DSU{
    vector<int> pa;
    int cnt,cost=0;

    DSU(int C):pa(C), cnt(C){iota(all(pa), 0);}

    int found(int x) {return (x==pa[x]?x:pa[x]=found(pa[x]));}
    //可按秩合併
    void unite(int x,int y, int k){
        int p=found(x);
        int q=found(y);
        if (p==q) return;
        if (p<q){
            pa[q]=p;
            --cnt;
        }
        else{
            pa[p]=q;
            --cnt;
        }
        cost+=k;
        return;
    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<Tp> edge(m);

    for (auto& x:edge) cin>>u(x)>>v(x)>>w(x);
    sort(all(edge), cmp); //可用lambda
      /*
  sort(edges.begin(), edges.end(), [](Tp& a, Tp& b) {
    return w(a) < w(b);
});
  */
    DSU dsu(n);
    for (auto& X:edge){
        dsu.unite(u(X), v(X), w(X));
    }

    cout<<(dsu.cnt==1?dsu.cost:-1);

    return 0;

}
