#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,W;
    cin>>n>>W;
    vector<int> T(n);
    vector<pair<int,int>> M(n); //W T
    vector<int> pdp(W+1),cdp(W+1);
    for(int& x:T) cin>>x;
    for (int i=0;i<n;++i){
        M[i].first=T[i];
        cin>>M[i].second;
    }
    for (int i=0;i<n;++i){
        for (int j=1;j<=W;++j){
            cdp[j]=pdp[j];
            if (j>=M[i].first){
                cdp[j]=max(cdp[j],pdp[j-M[i].first]+M[i].second);
            }
        }
        swap(cdp&,pdp&);
    }
    cout<<pdp[W];

    return 0;
}
