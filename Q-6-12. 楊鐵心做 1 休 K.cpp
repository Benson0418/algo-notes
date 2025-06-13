#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,K;
    cin>>n>>K;
    vector<int> M(n),dp(n);
    for (int& x:M) cin>>x;
    deque<pair<int,int>> monostk;

    for (int i=0;i<n;++i){
        if (!monostk.empty() && monostk[0].second<i-K) monostk.pop_front();
        if  (i-K-1>=0 && !monostk.empty()){
            dp[i]=max(dp[i-K-1]+M[i],monostk[0].first);
        }
        else if (i-K-1<0 && !monostk.empty()){
            dp[i]=max(M[i],monostk[0].first);
        }
        else if (i-K-1>=0 && monostk.empty()){
            dp[i]=dp[i-K-1]+M[i];
        }
        else dp[i]=M[i];
        while (!monostk.empty() && monostk.back().first<=dp[i]) monostk.pop_back();
        monostk.push_back({dp[i],i});
    }
    cout<<dp.back();
    return 0;
}
