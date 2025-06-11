#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n,res=0;
    cin>>m>>n;
    vector<int> A;
    unordered_map<int,int> M;
    unordered_set<int> S;

    for (int a,i=0;i<n;++i){
        cin>>a;
        A.push_back(a);
    }

    int l=0,r;
    for (r=0;r<m;++r){
        S.insert(A[r]);
        ++M[A[r]];
    }
    if (S.size()==m)++res;
    while (r<n){
        --M[A[l]];
        if (M[A[l]]<=0){
            S.erase(A[l]);
        }
        ++M[A[r]];
        S.insert(A[r]);
        ++l;
        ++r;
        if (S.size()==m)++res;
    }
    cout<<res<<"\n";




    return 0;
}
