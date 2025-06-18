#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> ved;
vector<int> path;

void dfs(int x){
    ved[x]=1;
    path.push_back(x);
    for (auto& y:tree[x]){
        if (!ved[y]) {
            dfs(y);
            path.push_back(x);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,res=0;
    cin>>n;
    tree.resize(n);
    ved.resize(n);
    for (int a,b,c,i=0;i<n-1;++i){
        cin>>a>>b>>c;
        tree[a].push_back(b);
        tree[b].push_back(a);
        res+=c*2;
    }
    for (auto& x:tree) sort(x.begin(),x.end());
    cout<<res<<"\n";
    dfs(0);
    for(auto& z:path) cout<<z<<" ";
    return 0;
}
