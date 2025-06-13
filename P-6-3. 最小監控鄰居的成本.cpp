#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,dp1=0,dp2=0,dp3=0,x=0;
    cin>>n;
    vector<int> L(n);
    for (int& x:L) cin>>x;
    if (n==1){
        cout<<L[0];
        return 0;
    }

    for (int i=0;i<n;++i){
        if (i==0 || i==1){
            x=L[i];
        }
        else if (i==2){
            x=L[2]+min(dp2,dp3);
        }
        else{
            x=L[i]+min({dp1,dp2,dp3});
        }
        dp1=dp2;
        dp2=dp3;
        dp3=x;
    }
    cout<<min(dp2,dp3);


    return 0;
}
