#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int res=0,cnt=0;
    int l=0,r=0;
    vector<int> A;
    unordered_set<int> S;

    for (int a,i=0;i<n;++i){
        cin>>a;
        A.push_back(a);
    }
    while (r<n){
        if (S.find(A[r])==S.end()){
            S.insert(A[r]);
            ++cnt;
            ++r;
        }
        else{
            S.erase(A[l]);
            ++l;
            --cnt;
        }
        res=max(cnt,res);
    }

    cout<<res<<"\n";

    return 0;
}
