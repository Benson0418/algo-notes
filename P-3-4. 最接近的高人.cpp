#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x=0;
    vector<pair<int,int>> monostack{{100000000,0}};

    int N;
    cin>>N;
    for (int a,i=1;i<=N;++i){
        cin>>a;
        while (monostack.back().first<=a){
            monostack.pop_back();
        }
        x+=i-monostack.back().second;
        monostack.push_back({a,i});

    }
    cout<<x<<"\n";
    return 0;
}
