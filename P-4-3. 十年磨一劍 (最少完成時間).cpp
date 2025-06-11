#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> A(n);
    for (int& x:A)cin>>x;
    unsigned long long res=0;
    sort(A.begin(),A.end(),greater<int>());
    for (int i=0;i<n;++i){
        res+=(unsigned long long)A[i]*(i+1);
    }
    cout<<res<<"\n";
    return 0;
}

