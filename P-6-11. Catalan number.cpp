#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;
const uLL P=1e9+9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    uLL n;
    uLL x;
    cin>>n;
    vector<uLL> C(n+1);
    C[0]=1;
    for (uLL i=1;i<=n;++i){
        x=0;
        for (uLL j=0;j<i;++j){
            x+=(C[j]%P)*(C[i-1-j]%P);
        }
        C[i]=x%P;
    }
    cout<<C[n];



    return 0;
}
