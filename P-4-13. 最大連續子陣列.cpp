#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n,h=0,res=0;
    cin>>n;
    vector<LL> pA(n+1),A(n);
    for (LL& x:A) cin>>x;
    for (int i=0;i<n;++i) pA[i+1]=pA[i]+A[i];
    for (int i=n;i>=0;--i){
        res=max(res,h-pA[i]);
        h=max(h,pA[i]);
    }
    cout<<res<<"\n";
    return 0;
}
