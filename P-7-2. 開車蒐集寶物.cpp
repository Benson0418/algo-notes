#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,res=0,t;
    cin>>n>>m;

    vector<int> val(n);
    vector<bool> visit(n);
    for (int& x:val) cin>>x;
    vector<vector<int>> adj(n);
    for (int a,b,i=0;i<m;++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int x;
    deque<int> que;
    for (int i=0;i<n;++i){
        if (visit[i]) continue;
        t=0;
        que.push_back(i);
        visit[i]=1;
        while (!que.empty()){
            x=que.front();
            que.pop_front();
            t+=val[x];
            for (int& z:adj[x]){
                if (visit[z]) continue;
                visit[z]=1;
                que.push_back(z);
            }
        }
        res=max(res,t);
    }
    cout<<res;

    return 0;
}
