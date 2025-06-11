#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n,m;
    cin>>n>>m;
    vector<LL> T(n),S(m);
    priority_queue<LL,vector<LL>,greater<LL>> pq(S.begin(),S.end());

    for (auto& x:T){
        cin>>x;
    }
    LL x;
    for (LL i=0;i<n;++i){
        x=T[i]+pq.top();
        pq.pop();
        pq.push(x);
    }
    for (LL i=0;i<m-1;++i){
        pq.pop();
    }
    cout<<pq.top()<<"\n";

    return 0;
}
