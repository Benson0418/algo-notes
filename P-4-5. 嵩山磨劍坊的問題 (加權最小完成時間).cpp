#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool cmp(pair<int,int> X,pair<int,int> Y){
    return (double)X.first/X.second<(double)Y.first/Y.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> A(n);
    vector<pair<int,int>> M;
    for(int& x:A)cin>>x;
    for (int a,i=0;i<n;++i){
        cin>>a;
        M.push_back({A[i],a});
    }
    sort(M.begin(),M.end(),cmp);
    LL res=0,t=0;
    for (int i=0;i<n;++i){
        t+=M[i].first;
        res+=M[i].second*t;
    }
    cout<<res<<"\n";
    return 0;
}
