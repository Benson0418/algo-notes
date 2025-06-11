#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> A,pair<int,int> B){
    return A.second<B.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> M;
    for (int a,b,i=0;i<n;++i){
        cin>>a>>b;
        M.push_back({a,b});
    }
    sort(M.begin(),M.end(),cmp);

    int res=0,t=-1;

    for (int i=0;i<n;++i){
        if (M[i].first>t){
            ++res;
            t=M[i].second;
        }
    }
    cout<<res<<"\n";

    return 0;
}
