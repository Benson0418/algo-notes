#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> L(n);
    vector<int> stk;
    for (int& x:L) cin>>x;

    for (int i=0;i<n;++i){
        auto idx=lower_bound(stk.begin(),stk.end(),L[i]);
        if (idx==stk.end()) stk.push_back(L[i]);
        else *idx=L[i];
    }
    cout<<stk.size();
    return 0;
}
