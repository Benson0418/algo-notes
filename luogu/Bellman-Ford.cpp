#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
#define pb push_back
#define mp make_tuple
#define eb emplace_back


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin>>n>>m>>s;

    vector<tuple<int,int,int>> edges(m);
    vector<int> dist(n+1, INT_MAX);

    for (int u,v,w,i=0;i<m;++i){
        cin>>u>>v>>w; // u->v長度為w
        edges[i]=mp(u,v,w);
    }

    dist[s]=0;

    bool flag=0;
    for (int k=1;k<=n-1;++k){
        if (flag) break;
        flag=1;
        for (tuple<int,int,int> x:edges){
            if (dist[get<0>(x)]==INT_MAX) continue;
            if (dist[get<0>(x)]+get<2>(x)<dist[get<1>(x)]){
                dist[get<1>(x)]=dist[get<0>(x)]+get<2>(x);
                flag=0;
            }
        }
    }

    for (int i=1;i<=n;++i){
        cout<<dist[i]<<" ";
    }
    return 0;
}
