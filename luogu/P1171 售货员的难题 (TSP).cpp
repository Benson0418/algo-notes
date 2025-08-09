#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=20;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int grid[MAXN][MAXN];
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            cin>>grid[i][j];
        }
    }
    int dp[1<<MAXN][MAXN];
    memset(dp,-1,sizeof(dp));

    auto f=[&](auto&& self,int status,int curr) ->int{
        if (status==(1<<n)-1) return grid[curr][0];
        if (dp[status][curr]!=-1) return dp[status][curr];
        int ans=INT_MAX;
        for (int i=0;i<n;++i){
            if ((status&(1<<i))==0){
                ans=min(ans, grid[curr][i]+self(self,status|(1<<i),i));
            }
        }
        dp[status][curr]=ans;
        return ans;
    };


    cout<<f(f,1,0);

    return 0;
}
