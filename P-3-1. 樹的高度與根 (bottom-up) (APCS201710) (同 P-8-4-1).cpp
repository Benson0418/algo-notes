#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int> parent(N+1);
    deque<int> que;
    vector<int> deg(N+1);
    vector<int> highth(N+1);
    for (int x,y,i=1;i<=N;++i){
        cin>>x;
        for(int j=0;j<x;++j){
            cin>>y;
            parent[y]=i;
            ++deg[i];
        }
        if (!x) que.push_back(i);
    }

    for(int i=1;i<=N;++i){
        if (!parent[i]){
            cout<<i<<"\n";
            break;
        }
    }
    int x;
    while (!que.empty()){
        x=que.front();
        que.pop_front();

        --deg[parent[x]];
        highth[parent[x]]=max(highth[parent[x]],highth[x]+1);
        if (!deg[parent[x]]) que.push_back(parent[x]);
    }
    int res=0;
    for (int i=1;i<=N;++i) res+=highth[i];
    cout<<res;
    return 0;
}
