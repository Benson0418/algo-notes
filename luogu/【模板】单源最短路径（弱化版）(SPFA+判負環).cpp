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
#define pf pop_front

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin>>n>>m>>s;

    vector<vector<pair<int,int>>> graph(n+1);
    vector<int> dist(n+1, INT_MAX),inq(n+1);
    vector<int> cnt(n+1,0);
    deque<int> que;

    for (int u,v,w,i=0;i<m;++i){
        cin>>u>>v>>w; // u->v長度為w
        graph[u].eb(v,w);
    }

    dist[s]=0;
    que.pb(s);
    inq[s]=1;
    cnt[s]=1;

    bool neg_cycle=false;
    while (!que.empty()){
        int u=que.front();
        que.pop_front();
        inq[u]=0;

        for (auto& X:graph[u]){
            auto& v=X.F;
            auto& w=X.S;
            if (dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if (!inq[v]){
                    que.pb(v);
                    inq[v]=1;
                    if (++cnt[v]>n){
                        neg_cycle=true;
                        break;
                    }
                }
            }
        }
    if (neg_cycle) break;
    }

    if (neg_cycle){
        cout<<-1;
    }
    else{
        for (int i=1;i<=n;++i){
            cout<<dist[i]<<" ";
        }
   }
    return 0;
}
