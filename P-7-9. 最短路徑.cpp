#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<P>> graph(n); //鄰居 長度
    for (int a,b,c,i=0;i<m;++i){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    vector<int> dis(n,INF);
    vector<int> locked(n);
    dis[0]=0;
    priority_queue<P,vector<P>,greater<P>> pq; //距離 節點
    pq.push({0,0});
    P t;
    while (!pq.empty()){ //t 1距離 2節點
        t=pq.top();
        pq.pop();
        if (locked[t.second])continue;
        locked[t.second]=1;
        for (auto& x:graph[t.second]){ //x 1鄰居 2長度
            if (dis[x.first]>dis[t.second]+x.second){
                dis[x.first]=dis[t.second]+x.second;
                pq.push({dis[x.first],x.first});
            }
        }
    }
    int o=0,p=0;
    for (int i=0;i<n;++i){
        if (dis[i]==INF){
            ++p;
        }
        else if(dis[i]>o){
            o=dis[i];
        }
    }
    cout<<o<<"\n"<<p;
    return 0;
}
