#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //初始化
    int n,m;
    cin>>n>>m;
    vector<int> weight(2*n),parent(2*n);
    vector<pair<int,int>> tree(2*n);
    for (int a,i=n;i<2*n;++i){
        cin>>a;
        weight[i]=a;
    }
    vector<int> goods(m);
    for (auto& x:goods) cin>>x;
    vector<int> indeg(2*n);
    for (int p,s,t,i=0;i<n-1;++i){
        cin>>p>>s>>t;
        tree[p].first=s;
        tree[p].second=t;
        parent[s]=p;
        parent[t]=p;
        indeg[p]=2;
    }

    // 將分流器初始化 (bottom-up)
    deque<int> que;
    for (int i=n;i<2*n;++i){
        que.push_back(i);
    }
    int x;
    while (!que.empty()){
        x=que.front();
        que.pop_front();
        if (parent[x]){
            weight[parent[x]]+=weight[x];
            --indeg[parent[x]];
            if (indeg[parent[x]]==0){
                que.push_back(parent[x]);
            }
        }
    }

    //for (auto& y:weight) cout<<y<<" ";
    //貨物進入分流

    int cur=1;
    for(auto& y:goods) {
        cur=1;
        while (cur<n){
            weight[cur]+=y;
            if (weight[tree[cur].first]<=weight[tree[cur].second]){
                cur=tree[cur].first;
            }
            else{
                cur=tree[cur].second;
            }
        }
        weight[cur]+=y;
        cout<<cur<<" ";
    }

    return 0;
}

