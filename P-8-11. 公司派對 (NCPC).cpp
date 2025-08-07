#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,r1;
    cin>>n>>r1;
    vector<int> head(n+1),edges(n),to(n),happy(n+1),no(n+1),yes(n+1);
    for (int p,r,i=1;i<n;++i){
        cin>>p>>r;
        int c=i+1;
        edges[i]=head[p];
        head[p]=i;
        to[i]=c;
        happy[c]=r;
    }
    happy[1]=r1;
    function<void(int)> f=[&](int u){
        no[u]=0;
        yes[u]= happy[u];
        for (int k = head[u], v;k;k=edges[k]){
            v=to[k];
            f(v);
            no[u]+=max(no[v],yes[v]);
            yes[u]+=no[v];
        }
        return;
    };

    f(1);
    cout<<max(no[1],yes[1]);



    return 0;
}
