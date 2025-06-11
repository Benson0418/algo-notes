#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n,cnt=0,cost=0,x;
    cin>>n;
    multiset<LL> S;

    for (LL a,i=0;i<n;++i){
        cin>>a;
        cnt+=a;
        S.insert(a);
    }
    LL a,b;
    while (S.size()>1){
        a=*S.begin();
        S.erase(S.begin());
        b=*S.begin();
        S.erase(S.begin());
        x=a+b;
        cost+=x;
        S.insert(x);
    }
    cout<<cnt<<"\n"<<cost<<"\n";
    return 0;
}

