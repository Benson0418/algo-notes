#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t,dp1=0,dp2=0,ndp1,ndp2;
    cin>>n>>t;
    int x=t,y=t;

    for (int a,b,i=0;i<n;++i){
        cin>>a>>b;
        ndp1=min(abs(a-x)+dp1,abs(a-y)+dp2);
        ndp2=min(abs(b-x)+dp1,abs(b-y)+dp2);
        dp1=ndp1;
        dp2=ndp2;
        x=a;
        y=b;
    }
    cout<<min(dp1,dp2);


    return 0;
}
