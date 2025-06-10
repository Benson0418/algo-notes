#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){

    int n,K;
    LL res=-210000000000;
    cin>>n>>K;

    int pA=0;
    int x;
    set<LL> sA{0};
    set<LL>::iterator idx;

    for (int a,i=0;i<n;++i){
        cin>>a;
        pA+=a;

        x=pA-K;
        idx=sA.lower_bound(x);
        if (idx!=sA.end() && K>=pA-*idx){
            res=max(res,pA-*idx);
        }
        sA.insert(pA);
    }
    cout<<res<<"\n";
    return 0;
}
