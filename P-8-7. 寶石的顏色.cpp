#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,res=0;
    cin>>n;
    vector<int> c(n);
    vector<vector<int>> child(n);
    for (auto& x:c) cin>>x;
    for (int a,b,i=0;i<n-1;++i){
        cin>>a>>b;
        child[a].push_back(b);
    }
    unordered_map<int,int> color;

    function<void(int)> dfs=[&](int idx){
        ++color[c[idx]];
        res=max(res,color[c[idx]]);
        for (auto& x:child[idx]){
            dfs(x);
        }
        --color[c[idx]];
    };
    dfs(0);
    cout<<res;


    return 0;
}



