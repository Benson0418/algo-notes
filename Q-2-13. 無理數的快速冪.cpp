#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int p=1000000009;

pair<LL,LL> product(pair<LL,LL> X,pair<LL,LL> Y){
return {(((X.first%p)*(Y.first%p))+(2*(X.second)%p*(Y.second)%p))%p,(((X.first%p)*(Y.second%p))%p+((X.second%p)*(Y.first%p)))%p};
}

pair<LL,LL> qpow(pair<LL,LL> X,int n){
    pair<LL,LL> res={1,0};
    while (n){
        if (n&1)res=product(res,X);
        X=product(X,X);
        n>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x,y,n;
    cin>>x>>y>>n;
    pair<LL,LL> res={x,y};
    res=qpow(res,n);

    cout<<res.first<<" "<<res.second<<"\n";

    return 0;
}
