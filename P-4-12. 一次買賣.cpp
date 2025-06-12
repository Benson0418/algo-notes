#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,ch=0,res=0;
    cin>>n;
    vector<int> p(n);
    for (int& x:p) cin>>x;
    for (int i=n-1;i>=0;--i){
        res=max(res,ch-p[i]);
        ch=max(ch,p[i]);
    }
    cout<<res<<"\n";



    return 0;
}
