#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,C;
    cin>>n>>C;
    vector<int> W(n),V(n),dp(C+1);

    for(int& x:W) cin>>x;
    for(int& x:V) cin>>x;

    for (int i=0;i<n;++i){
        for (int j=C;j>=0;--j){
            if (j>=W[i]){
                dp[j]=max(dp[j],dp[j-W[i]]+V[i]);
            }
        }
    }
    cout<<dp[C];

    return 0;
}
