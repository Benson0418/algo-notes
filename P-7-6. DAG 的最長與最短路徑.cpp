#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<vector<pair<int,int>>> adj(n);
    deque<int> que;
    vector<int> indeg(n);

    for (int a,b,c,i=0;i<m;++i){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        ++indeg[b];
    }

    for (int i=0;i<n;++i){
        if (indeg[i]==0){
            que.push_back(i);
        }
    }
    //topo sort
    vector<int> topo(n);
    int i=0;
    while (!que.empty()){
        topo[i]=que.front();
        que.pop_front();
        ++i;
        for (auto& x:adj[topo[i-1]]){
            --indeg[x.first];
            if (indeg[x.first]==0){
                que.push_back(x.first);
            }
        }
    }

    vector<int> min_path(n,INF),max_path(n,-INF);
    min_path[s]=0;
    max_path[s]=0;
    for (int& u:topo){
        for (auto& v:adj[u]){
            if (min_path[u]!=INF){
                min_path[v.first]=min(min_path[v.first],min_path[u]+v.second);
            }
            if (max_path[u]!=-INF){
                max_path[v.first]=max(max_path[v.first],max_path[u]+v.second);
            }

        }
    }
    if (min_path[t]==INF){
        cout<<"No path\nNo path";
    }
    else{
        cout<<min_path[t]<<"\n"<<max_path[t];
    }
    return 0;

}
