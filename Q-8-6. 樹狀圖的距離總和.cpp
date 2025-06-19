#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n;
    cin>>n;

    if (n==1){
        cout<<0;
        return 0;
    }

    vector<LL> parent(n+1),edge(n+1),indeg(n+1),stcnt(n+1,1);
    LL res=0;

    for(LL a,i=2;i<=n;++i){
        cin>>a;
        parent[i]=a;
        ++indeg[a];
    }
    for (LL a,i=2;i<=n;++i){
        cin>>a;
        edge[i]=a;
    }
    deque<LL> que;
    for (LL i=2;i<=n;++i){
        if (!indeg[i]){
            que.push_back(i);
        }
    }

    LL x;
    while (!que.empty()){
        x=que.front();
        que.pop_front();
        if (!parent[x]) break;
        --indeg[parent[x]];
        stcnt[parent[x]]+=stcnt[x];
        if (!indeg[parent[x]]) que.push_back(parent[x]);
        res+=(stcnt[x]*(n-stcnt[x])*2*edge[x]);
    }
    cout<<res;

    return 0;
}


