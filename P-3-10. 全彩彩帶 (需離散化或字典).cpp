#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin>>n;
    int res=0,l=0,r=0,f;
    vector<int> A;
    unordered_map<int,int> dict;
    unordered_set<int> S;

    for (int a,i=0;i<n;++i){
        cin>>a;
        A.push_back(a);
        dict[a]=0;
        S.insert(a);
    }
    while (!S.empty()){
        S.erase(A[r]);
        ++dict[A[r]];
        ++res;
        ++r;
    }
    while (dict[A[l]]>1){
        --dict[A[l]];
        --res;
        ++l;
    }
    f=res;

    while (r<n){
        ++dict[A[r]];
        ++res;
        while (dict[A[l]]>1){
            --dict[A[l]];
            --res;
            ++l;
        }
        f=min(f,res);
        ++r;
    }
    cout<<f<<"\n";



    return 0;
}
