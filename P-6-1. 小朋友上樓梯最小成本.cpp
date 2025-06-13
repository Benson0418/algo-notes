#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,dp1=0,dp2=0,x=0;
    cin>>n;
    vector<int> L(n);
    for (int& x:L) cin>>x;
    for (int i=0;i<n;++i){
        x=min(dp1,dp2)+L[i];
        dp1=dp2;
        dp2=x;
    }
    cout<<x;
    return 0;
}
