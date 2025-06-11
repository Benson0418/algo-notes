#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,L,res=0,f;
    cin>>n>>L;
    vector<int> A,cnt;
    cnt.resize(n);

    for (int a,i=0;i<n;++i){
        cin>>a;
        A.push_back(a);
    }
    for (int i=0;i<L;++i){
        cnt[A[i]]+=1;
    }
    for (int i=0;i<n;++i){
        if (cnt[i]){
            ++res;
        }
    }
    f=res;
    for (int l=0,r=L;r<n;++l,++r){
        if (!cnt[A[r]]) ++res;
        cnt[A[r]]+=1;
        cnt[A[l]]-=1;
        if (!cnt[A[l]]) --res;
        f=max(res,f);
    }
    cout<<f<<"\n";

    return 0;
}
