#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,res=0;
    cin>>n;
    vector<int> A,B;
    for (int a,i=0;i<n;++i){
        cin>>a;
        B.push_back(a);
    }
    for (int a,i=0;i<n;++i){
        cin>>a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int a=0,b=0;
    while (a<n){
        if (A[a]>B[b]){
            ++b;
            ++res;
        }
        ++a;
    }
    cout<<res<<"\n";



    return 0;
}
