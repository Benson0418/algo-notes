#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,P;

int qpow(ll a,ll n){
    ll res=1;
    a%=P;
    while (n){
        if (n&1)res=res*a%P;
        a=a*a%P;
        n>>=1;
    }
    return res;
}


int main(){
    cin>>n>>P;
    for (int a,i=0;i<n;++i){
        cin>>a;
        cout<<qpow(a,P-2)<<' ';
    }

    cout<<endl;
    return 0;
}
