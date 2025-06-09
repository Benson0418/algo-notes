#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    set<int> L;
    for (int a,i=0;i<n;++i){
        cin>>a;
        L.insert(a);
    }
    cout<<L.size()<<endl;
    for (int a:L){
        cout<<a<<' ';
    }
    cout<<endl;

    return 0;
}
