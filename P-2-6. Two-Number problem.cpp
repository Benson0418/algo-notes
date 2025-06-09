#include<bits/stdc++.h>
using namespace std;

int main(){
    int res=0;
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n,K;
    unordered_set<int> A;
    cin>>m>>n>>K;
    for (int a,i=0;i<m;++i){
        cin>>a;
        A.insert(a);
    }
    for (int a,i=0;i<n;++i){
        cin>>a;
        if (A.find(K-a)!=A.end()){
            ++res;
        }
    }
    cout<<res<<endl;


    return 0;
}
