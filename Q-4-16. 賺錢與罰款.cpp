#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL N,t=0,res=0;
    cin>>N;
    vector<LL> T(N);
    vector<pair<LL,LL>> M(N);
    for (LL& x:T) cin>>x;
    for (int i=0;i<N;++i){
        M[i].first=T[i];
        cin>>M[i].second;
    }
    sort(M.begin(),M.end());
    for (int i=0;i<N;++i){
        t+=M[i].first;
        res+=M[i].second-t;
    }
    cout<<res;


    return 0;
}
