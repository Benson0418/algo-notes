#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> A,pair<int,int> B){
    if (A.first!=B.first) return A.first<B.first;
    else return A.second>B.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,res=0,cres=0;
    cin>>n;
    n=2*n;
    vector<pair<int,int>> D(n);
    for (int m,s,t,i=0,j=0;i<n/2;++i){
        cin>>m>>s>>t;
        D[j]={s,m};
        ++j;
        D[j]={t,-m};
        ++j;
    }
    sort(D.begin(),D.end(),cmp);
    for (int i=0;i<n;++i){
        cres+=D[i].second;
        res=max(res,cres);
    }
    cout<<res;
    return 0;
}
